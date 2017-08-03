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
typedef int QElemType; /* 类型根据实际情况来定，这里是int */
/* 循环队列的顺序存储结构 */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}SqQueue;

Status visit(QElemType c)
{
	printf("%d ",c);
	return OK;
}
Status InitQueue(SqQueue *Q){

}
Status DestoryQueue(SqQueue *Q){

}
Status ClearQueue(SqQueue *Q){

}
Status QueueEmpty(SqQueue Q){

}
GetHead(SqQueue Q,QElemType *e){

}
EnQueue(SqQueue *Q,QElemType e){

}
DeQueue(SqQueue *Q,QElemType *e){

}
int QueueLength(SqQueue Q){

}