#include<stdio.h>
#include<stdlib.h>
#define maxx 10
typedef struct Queue
{
	int f, r;
	int* data;
}Queue;
//队列初始化
Queue InitQueue()
{
	Queue q;
	q.f = 0;
	q.r = 0;
	q.data = (int*)malloc(sizeof(int) * maxx);
	return q;
}
//入队
void EnQueue(int x,Queue* q)
{
	if (q->f == (q->r + 1) % maxx)
	{
		printf("队列已满!\n");
	}
	else
	{
		q->data[q->r] = x;
		q->r = (q->r + 1) % maxx;
	}
}
//出队
void DeQueue(Queue* q)
{
	if (q->f == q->r)
	{
		printf("队列为空!\n");
	}
	else
	{
		printf("出队\n");
		q->data[q->f] = 0;
		q->f = (q->f + 1) % maxx;
	}
}
//输出队首元素
void FrontQueue(Queue* q)
{
	if (q->f == q->r)
	{
		printf("队列为空!\n");
	}
	else
	{
		printf("%d\n", q->data[q->f]);
	}
}
int main()
{
	Queue q = InitQueue();
	EnQueue(1, &q);
	EnQueue(2, &q);
	EnQueue(3, &q);
	FrontQueue(&q);
	DeQueue(&q);
	FrontQueue(&q);
	DeQueue(&q);
	DeQueue(&q);
	DeQueue(&q);
	return 0;
}