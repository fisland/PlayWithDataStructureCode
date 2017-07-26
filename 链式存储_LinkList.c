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
typedef int ElemType; /* 类型根据实际情况来定，这里是int */

Status visit(ElemType c){
    printf("%d ",c);
    return OK;
}

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

/* 初始化顺序线性表 */
Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));/* 产生头结点,并使L指向此头结点 */
    if (!(*L)){ /* 存储分配失败 */
        return ERROR;
    }
    (*L)->next = NULL;/* 指针域为空 */
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L){
    if(L->next)
        return FALSE;
    else
        return True;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L){
    LinkList p,q;
    p = (*L)->next;/*  p指向第一个结点 */
    while(p){/*  没到表尾 */
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next=NULL; /* 头结点指针域为空 */
    return OK;
}