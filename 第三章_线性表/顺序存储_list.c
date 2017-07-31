#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define True 1
#define FALSE 0

#define MAXSIZE 20 //存储空间初始分配量

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* 类型根据实际情况来定，这里是int */

Status visit(ElemType c){
    printf("%d ",c);
    return OK;
}
typedef struct {
    ElemType data[MAXSIZE];  /* 数组，存储数据元素*/
    int length; /* 线性表当前长度 */
}Sqlist;

/* 初始化顺序线性表 */
Status InitList(Sqlist *L){
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已经存在。操作结果：如果L为空表，返回T，否则F */ 
Status ListEmpty(Sqlist L){
    if (L.length == 0){
        return True;
    }
    else{
        return FALSE;
    }
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(Sqlist *L){
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(Sqlist L){
    return L.length;
}

/* 初始条件，顺序线性表L已存在，i<=i<=ListLength(L) */
/* 操作结果，用e返回L中第i个元素的值，注意这里i是指位置，从0开始  */
Status GetElem(Sqlist L, int i, ElemType *e){
    if (L.length == 0 || i < 1 || i > L.length){
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(Sqlist L, ElemType e){
    int i;
    if (L.length == 0){
        return 0;
    }
    for (i = 0; i < L.length; i++){
        if (L.data[i] == e){
            break;
        }
    }
    if (i>=L.length){
        return 0;
    }
    printf("第几个：%d",i);
    return i+1;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(Sqlist *L, int i, ElemType e){
    int k;
    if (L->length == MAXSIZE){/* 顺序线性表已经满 */
        return ERROR;
    }
    if (i<1 || i>L->length+1){/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
        return ERROR;
    }
    if (i<=L->length){/* 若插入数据位置不在表尾 */
        for (k = L->length-1; k>=i-1; k--){/* 将要插入位置之后的数据元素向后移动一位 */
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1] = e;/* 将新元素插入 */
    L->length++;
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(Sqlist *L, int i, ElemType *e){
    int k;
    if (L->length==0){ /* 线性表为空 */
        return ERROR;
    }
    if (i<1 || i>L->length){ /* 删除位置不正确 */
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length){ /* 如果删除不是最后位置 */
        for (k=i; k < L->length; k++){ /* 将删除位置后继元素前移 */
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(Sqlist L){
    int i;
    for (size_t i = 0; i < L.length; i++){
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}

void unionL(Sqlist *La, Sqlist Lb){
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for (size_t i = 1; i <= Lb_len; i++){
        GetElem(Lb, i, &e);
        if (!LocateElem(*La,e))
        {
            ListInsert(La,++La_len,e);
        }
    }
}

int main(){
    Sqlist L;
    Sqlist Lb;

    ElemType e;
    Status i;
    int j, k;

    /* 初始化 */
    i = InitList(&L);
    printf("初始化L后，L.length=%d\n", L.length);

    /* 插入 */
    for(j=1; j<=5; j++){
        i = ListInsert(&L,1,j);
    }
    printf("在L的表头依次插入1-5后，L.data= ");
    ListTraverse(L);

    /* 清空 */
    i = ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    /* 插入10个 */
    for(j=1; j<=10; j++){
        i = ListInsert(&L,1,j);
    }
    printf("在L的表头依次插入1-10后，L.data= ");
    ListTraverse(L);
    printf("L.length=%d\n",L.length);

    /* 插入0 */
    i = ListInsert(&L,1,0);
    printf("在L的表头依次插入0后，L.data= ");
    ListTraverse(L);
    printf("L.length=%d\n",L.length);

    /* 取第五个的值 */
    GetElem(L,5,&e);
    printf("取第五个的值:%d\n",e);

    /* 取3和4个的位置 */
    for(j=3; j<=4; j++){
        k = LocateElem(L,j);
        printf("k--------->%d",k);
        if (k){/*强行转换，会吧k的值强行转为bool*/
             printf("第%d个元素的值是%d\n",k,j);  
        }
        else{
            printf("没有值为%d的元素\n",j);
        }
    }

    /* 删除 */
    k = ListLength(L);
    for (j=k+1; j >= k; j--)
    {
        i = ListDelete(&L,j,&e);
        if (i == ERROR){
            printf("删除第%d个元素失败，\n",j);
        }
        else{
            printf("删除第%d个元素的值为%d\n",j,e);
        }
    }

    printf("依次输出L的元素：");
    ListTraverse(L);

    j = 5;
    ListDelete(&L,j,&e);
    printf("删除第%d个元素的值为%d\n",j,e);
    printf("依次输出L的元素：");
    ListTraverse(L);


    // 合并
    i = InitList(&Lb);
    for(j=10;j<=18;j++){
        ListInsert(&Lb,1,j);
    }
    printf("依次输出Lb的元素：");
    ListTraverse(Lb);

    unionL(&L, Lb);
	printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L); 
    return 0;
}