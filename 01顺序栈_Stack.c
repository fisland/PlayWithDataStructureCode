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
        int top; /* 用于栈顶指针 */
}SqStack;

Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

// 初始化操作，建立一个空栈
Status InitStack(SqStack *S){

    return OK;
}

// 若栈存在，销毁它
Status DestoryStack(SqStack *S){

    return OK;
}

// 将栈清空
Status ClearStack(SqStack *S){
    return OK;
}

// 是否为空
int StackEmpty(SqStack S){

    return True;
}

// 若栈非空。用e返回s的栈顶元素
int GetTop(SqStack S, SElemType *e){

    return *e;
}

// 若栈存在，插入新元素e到栈s中并成为栈顶元素
Status Push(SqStack *S, SElemType e){
    if (S->top == MAXSIZE-1){
        return ERROR;
    }
    // 栈顶指针加1
    S->top++;
    // 将新插入元素赋值给栈顶空间
    S->data[S->top] = e;
    return OK;
}

// 删除栈中栈顶元素，并用e返回值
Status Pop(SqStack *S,SElemType *e){
    if (S->top == -1){
        return ERROR;
    }
    // 将要删除的栈顶元素赋值给e
    *e = S->data[S->top];
    // 栈指针减一
    S->top--;
    return OK;
}

// 返回栈s的元素个数SElemType
int StackLength(SqStack S){
    return 0;
}



