#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}QNode;
typedef struct
{
	QNode* f;
	QNode* r;
}Queue;
//初始化
Queue InitQueue()
{
	QNode* head = (QNode*)malloc(sizeof(QNode));
	head->next = NULL;
	Queue q;
	q.f = head;
	q.r = head;
	return q;
}
//入队
void EnQueue(int x,Queue* q)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->data = x;
	s->next = NULL;
	q->r->next = s;
	q->r = s;
}
//出队
void DeQueue(Queue* q)
{
	if (q->f == q->r)
	{
		printf("队列为空!\n");
		return;
	}
	QNode* s = q->f->next;
	if (q->f->next == q->r)
	{
		q->r = q->f;
	}
	q->f->next = s->next;
	free(s);
}
//输出队首元素
void FrontQueue(Queue* q)
{
	if (q->f == q->r)
	{
		printf("队列为空!\n");
		return;
	}
	printf("%d\n", q->f->next->data);
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