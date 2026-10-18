#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define maxx 100
typedef struct Queue
{
	int data[maxx];
	int f;
	int r;
}Queue;

void InitQueue(Queue* q)
{
	q->f = 0;
	q->r = 0;
}

int IsEmpty(Queue* q)
{
	if (q->r == q->f)
		return 1;
	return 0;
}

void EnQueue(Queue* q,int n)
{
	if ((q->r + 1) % maxx == q->f)
	{
		printf("队列已满，入队失败\n");
		return;
	}
	q->data[q->r] = n;
	q->r = (q->r + 1) % maxx;
}

int DeQueue(Queue* q)
{
	if (IsEmpty(q))
	{
		printf("队列为空，出队失败\n");
		return -1;
	}
	int n = q->data[q->f];
	q->f = (q->f + 1) % maxx;
	return n;
}

typedef struct ENode
{
	int adj;
	struct ENode* next;
}ENode;

struct Graph
{
	char data;
	ENode* first;
}g[105];

int flag[105];

int n, m;
int Find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (x == g[i].data)
			return i;
	}
}

void BFS(int i)
{
	Queue q;
	InitQueue(&q);
	EnQueue(&q, i);
	flag[i] = 1;

	ENode* p = NULL;
	int x, y;
	while (!IsEmpty(&q))
	{
		x = DeQueue(&q);
		printf("%c\n", g[x].data);
		p = g[x].first;
		while (p != NULL)
		{
			if (flag[p->adj] == 0)
			{
				EnQueue(&q, p->adj);
				flag[p->adj] = 1;
			}
			p = p->next;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &g[i].data);
		g[i].first = NULL;
		flag[i] = 0;
	}

	char x, y;
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c", &x, &y);
		xi = Find(x);
		yi = Find(y);
		ENode* p = (ENode*)malloc(sizeof(ENode));
		p->adj = yi;
		p->next = g[xi].first;
		g[xi].first = p;

		p = (ENode*)malloc(sizeof(ENode));
		p->adj = xi;
		p->next = g[yi].first;
		g[yi].first = p;
	}

	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
			BFS(i);
	}
	return 0;
}