#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n, m;

typedef struct Edge
{
	int w;
	int u, v;
}Edge;
Edge e[10000];
int f[105];

void Sortt(int l, int r)
{
	int minn;
	Edge t;
	for (int i = l; i <= r; i++)
	{
		minn = i;
		for (int j = minn + 1; j <= r; j++)
		{
			if (e[minn].w > e[j].w)
			{
				minn = j;
			}
		}
		t = e[i];
		e[i] = e[minn];
		e[minn] = t;
	}
}
int Find(int x)
{
	if (x == f[x])
		return x;
	else
	{
		f[x] = Find(f[x]);
		return f[x];
	}
}

void Kruskal()
{
	int cnt = 0;
	int sum = 0;
	int fu, fv;
	for (int i = 1; i <= m; i++)
	{
		fu = e[i].u;
		fv = e[i].v;
		fu = Find(fu);
		fv = Find(fv);
		if (fu != fv)
		{
			printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
			sum += e[i].w;
			cnt++;
			f[fu] = fv;
		}
		if (cnt == n - 1)
			break;
	}
	printf("%d\n", sum);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	Sortt(1, m);
	Kruskal();
	return 0;
}

/*
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
*/