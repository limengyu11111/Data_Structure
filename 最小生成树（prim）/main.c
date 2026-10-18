#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define INF 100000
int n, m;
int g[105][105];
int flag[105];
int dist[105];

void Prim()
{
	int x = 1;
	flag[x] = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0 && g[x][i] < INF)
		{
			dist[i] = min(dist[i], g[x][i]);
		}
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int minn = -1;
		int t = INF;
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[j] < t)
			{
				minn = j;
				t = dist[j];
			}
		}

		flag[minn] = 1;
		printf("点%d 通过边权为%d的边 连到生成树上\n", minn, t);
		sum += t;

		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && g[minn][j] < INF)
			{
				dist[j] = min(dist[j], g[minn][j]);
			}
		}
	}

	printf("%d\n", sum);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		flag[i] = 0;
		dist[i] = INF;
		for (int j = 0; j < n; j++)
		{
			g[i][j] = INF;
		}
	}

	int x, y, w;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		g[x][y] = w;
		g[y][x] = w;
	}
	
	Prim();
	return 0;
}