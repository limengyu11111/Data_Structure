#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode
{
	int data;
	struct stackNode* next;
}SNode, * Stack;

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
		printf("空栈\n");
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
int ind[105];
int etv[105];
int ltv[105];
int topo[105], k;
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

void TopoSort()
{
	Stack s = InitStack();
	for (int i = 1; i <= n; i++)
	{
		etv[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			s = Push(s, i);
		}
	}

	int t1, t2;
	ENode* p;
	for (int i = 1; i <= n; i++)
	{
		if (IsEmpty(s))
			break;

		t1 = GetTop(s);
		s = Pop(s);
		topo[++k] = t1;
		p = g[t1].first;
		while (p != NULL)
		{
			t2 = p->adj;
			ind[t2]--;
			if (ind[t2] == 0)
			{
				s = Push(s, t2);
			}
			if (etv[t2] < etv[t1] + p->w)
			{
				etv[t2] = etv[t1] + p->w;
			}
			p = p->next;
		}
	}
}

void CriticalPath()
{
	int maxx = etv[topo[k]];
	for (int i = 1; i <= n; i++)
	{
		ltv[i] = maxx;
	}

	ENode* p;
	for (int i = k - 1; i >= 1; i--)
	{
		p = g[topo[i]].first;
		while (p != NULL)
		{
			if (ltv[topo[i]] > ltv[p->adj] - p->w)
			{
				ltv[topo[i]] = ltv[p->adj] - p->w;
			}
			p = p->next;
		}
	}

	printf("所有的关键活动为：\n");
	int ete, lte;
	for (int i = 1; i <= n; i++)
	{
		p = g[i].first;
		while (p != NULL)
		{
			ete = etv[i];
			lte = ltv[p->adj] - p->w;
			if (ete == lte)
			{
				printf("%c-->%c\n", g[i].data, g[p->adj].data);
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
	int xi, yi, w;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, &y, &w);
		xi = Find(x);
		yi = Find(y);
		ind[yi]++;
		ENode* p = (ENode*)malloc(sizeof(ENode));
		p->adj = yi;
		p->w = w;
		p->next = g[xi].first;
		g[xi].first = p;
	}
	TopoSort();
	CriticalPath();

	return 0;
}