#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define inf 100000

int n, m;
char v[105];
int e[105][105];

int Find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == x)
			return i;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &v[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			e[i][j] = inf;
		}
	}
	char x, y;
	int w, xi, yi;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c %d", &x, & y, & w);
		xi = Find(x);
		yi = Find(y);
		e[xi][yi] = w;
		e[yi][xi] = w;
	}
	char c;
	int ci,d = 0;
	scanf(" %c", &c);
	ci = Find(c);
	for (int i = 1; i <= n; i++)
	{
		if (e[ci][i] != inf)
			d++;
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