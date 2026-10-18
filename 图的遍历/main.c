#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define inf 100000
char e[105];
int v[105][105];
int flag[105];
int n, m;

int Find(char x)
{
	for (int i = 1; i <= n; i++)
	{
		if (e[i] == x)
			return i;
	}
}

void DFS(int n)
{
	printf("%c\n", e[n]);
	flag[n] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (v[n][i] != inf && flag[i] == 0)
		{
			DFS(i);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &e[i]);
		flag[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			v[i][j] = inf;
		}
	}

	char x, y;
	int xi, yi;
	for (int i = 1; i <= m; i++)
	{
		scanf(" %c %c", &x, &y);
		xi = Find(x);
		yi = Find(y);
		v[xi][yi] = 1;
		v[yi][xi] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
			DFS(i);
	}

	return 0;
}

/*
9 16
A B C D E F G H I
A B
A F
B G
G F
B C
B I
C I
C D
I D
D G
D H
D E
G H
H E
E F
F G
*/