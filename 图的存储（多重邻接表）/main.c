#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n, m;
typedef struct ENode
{
	int w;
	int u, v;
	struct ENode* unext;
	struct ENode* vnext;
}ENode;

struct Graph
{
	char data;
	ENode* first;
}g[100];

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
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x);
		yi = Find(y);
		ENode* s = (ENode*)malloc(sizeof(ENode));
		s->w = w;
		s->u = yi;
		s->unext = g[yi].first;
		g[yi].first = s;
		s->v = xi;
		s->vnext = g[xi].first;
		g[xi].first = s;
	}

	char z;
	int zi, d = 0;
	scanf(" %c", &z);
	zi = Find(z);
	ENode* p = g[zi].first;
	while (p != NULL)
	{
		d++;
		if (p->u == zi)
			p = p->unext;
		else
			p = p->vnext;
	}
	printf("%d\n", d);
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