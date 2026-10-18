#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct ENode
{
	int w;
	int head;
	struct ENode* hnext;
	int tail;
	struct ENode* tnext;
}ENode;

struct Graph
{
	char data;
	ENode* firstout;
	ENode* firstin;
}g[105];

int n, m;

int Find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[i].data == x)
			return i;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &g[i].data);
		g[i].firstin = NULL;
		g[i].firstout = NULL;
	}

	char x, y;
	int w, xi, yi;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x);
		yi = Find(y);
		ENode* s = (ENode*)malloc(sizeof(ENode));
		s->w = w;
		s->head = xi;
		s->tail = yi;
		s->hnext = g[xi].firstout;
		g[xi].firstout = s;
		s->tnext = g[yi].firstin;
		g[yi].firstin = s;
	}
	char z;
	int zi, ind=0, outd = 0;
	scanf(" %c", &z);
	zi = Find(z);
	ENode* p = g[zi].firstout;
	while (p != NULL)
	{
		outd++;
		p = p->hnext;
	}
	p = g[zi].firstin;
	while (p != NULL)
	{
		ind++;
		p = p->tnext;
	}
	printf("出度%d 入度%d\n", outd, ind);
	return 0;
}

/*
4 5
A B C D
A B 3
A D 6
A C 0
B D 9
D C 4
A
*/