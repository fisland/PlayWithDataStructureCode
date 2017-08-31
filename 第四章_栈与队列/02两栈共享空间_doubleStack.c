#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define True 1
#define FALSE 0

#define MAXSIZE 20 //存储空间初始分配量
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int SElemType; /* 类型根据实际情况来定，这里是int */

/* 顺序栈结构 */
typedef struct
{
        SElemType data[MAXSIZE];
        int top1; /* 用于栈1栈顶指针 */
        int top2; /* 用于栈2栈顶指针 */
}SqDoubleStack;

Status visit(SElemType c){
    printf("%d ",c);
    return OK;
}

// 构造一个空栈s
Status InitStack(SqDoubleStack *S){
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

// 把s设置为空栈
Status ClearStack(SqDoubleStack *S){
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

// 判断s是否是空栈
Status StackEmpty(SqDoubleStack S){
    if (S.top1 == -1 && S.top2 == MAXSIZE){
        return True;
    }
    return FALSE;
}

// 返回s的元素个数，栈的长度
int StackLength(SqDoubleStack S){
    return (S.top1+1) + (MAXSIZE - S.top2);
}

// 插入元素为e为新的栈顶元素
Status Push(SqDoubleStack *S, SElemType e, int StackNumber){
    if (S->top1+1 == S->top2){
        // 已满，无法加入
        return ERROR;
    }
    if (StackNumber == 1){
        S->data[++S->top1] = e;
    }
    else if (StackNumber == 2){
        S->data[--S->top2] = e;
    }
    return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqDoubleStack *S, SElemType *e, int StackNumber){
    if (StackNumber == 1){
        if (S->top1 == -1){
            return ERROR;
        }
        *e = S->data[S->top1--];
    }
    else if (StackNumber == 2){
        if (S->top2 == MAXSIZE){
            return ERROR;
        }
         *e =  S->data[S->top2++];
    }
    return OK;
}

// 打印
Status StackTraverse(SqDoubleStack S){
    int i;
    i = 0;
    while (i<=S.top1){
        visit(S.data[i++]);
    }
    i = S.top2;
    while (i<MAXSIZE){
        visit(S.data[i++]);
    }
    return OK;
}

int main(){
    int j;
    SqDoubleStack s;
    int e;
    if (InitStack(&s) == OK){
        for(j=1;j<=5;j++)
            Push(&s,j,1);
        for(j=MAXSIZE;j>=MAXSIZE-2;j--)
            Push(&s,j,2);
    }

    printf("栈中元素依次为：");
    StackTraverse(s);

    Pop(&s,&e,2);
    printf("\n弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    for(j=6;j<=MAXSIZE-2;j++)
                Push(&s,j,1);

    printf("栈中元素依次为：");
    StackTraverse(s);

        
    printf("\n栈满否：%d(1:否 0:满)\n",Push(&s,100,1));
    StackTraverse(s);

    ClearStack(&s);
    printf("\n栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    printf("栈中元素依次为：");

    StackTraverse(s);
}