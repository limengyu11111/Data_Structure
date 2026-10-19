#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode
{
	int data;
	struct stackNode* next;
}SNode, *Stack;

Stack InitStack()
{
	Stack s = (SNode*)malloc(sizeof(SNode));
	s->next = NULL;
	return s;
}

Stack Push(Stack s, int x)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = x;
	p->next = s->next;
	s->next = p;
	return s;
}

int IsEmpty(Stack s)
{
	if (s->next == NULL)
		return 1;
	else
		return 0;
}

Stack Pop(Stack s)
{
	SNode* p = s->next;
	if (p == NULL)
	{
		printf("¿ÕÕ»\n");
		return s;
	}
	else
	{
		s->next = p->next;
		free(p);
		p = NULL;
		return s;
	}
}

int GetTop(Stack s)
{
	if (IsEmpty(s))
	{
		return -1;
	}
	else
	{
		return s->next->data;
	}
}

int n, m;
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

int ind[105];
int topo[105], k;

int Find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[i].data == x)
			return i;
	}
}

void TopoSort()
{
	Stack s = InitStack();
	k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			s = Push(s, i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (IsEmpty(s))
			break;

		int t = GetTop(s);
		s = Pop(s);
		topo[++k] = t;
		ENode* p = g[t].first;
		while (p != NULL)
		{
			int z = p->adj;
			ind[z]--;
			if (ind[z] == 0)
			{
				s = Push(s, z);
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
		ind[i] = 0;
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
		ind[yi]++;
	}
	TopoSort();

	if (k < n)
	{
		printf("ÓÐ»·\n");
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			printf("%c ", g[topo[i]].data);
		}
	}

	return 0;
}

/*
6 8
A B C D E F
A B
A C
A D
C B
C E
F D
F E
D E
*/