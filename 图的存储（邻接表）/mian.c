#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n, m;
typedef struct ENode
{
	int adj;
	int w;
	struct ENode* next;
}ENode;

struct Graph
{
	char data;
	ENode* first;
}g[105];

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
		g[i].first = NULL;
	}
	char x, y;
	int w, xi, yi;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y,&w);
		xi = Find(x);
		yi = Find(y);
		ENode* s = (ENode*)malloc(sizeof(ENode));
		s->adj = yi;
		s->w = w;
		s->next = g[xi].first;
		g[xi].first = s;
		s = (ENode*)malloc(sizeof(ENode));
		s->adj = xi;
		s->w = w;
		s->next = g[yi].first;
		g[yi].first = s;
	}
	char c;
	int ci, d = 0;
	scanf(" %c", &c);
	ci = Find(c);
	ENode* p = g[ci].first;
	while (p != NULL)
	{
		p = p->next;
		d++;
	}
	printf("%d\n", d);
	return 0;
}
/*
4 5
ABCD
A B 3
A D 6
A C 0
B D 9
D C 4
A
*/