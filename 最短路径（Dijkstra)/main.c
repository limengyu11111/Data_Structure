#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define INF 100000

int n, m;
int g[105][105];
int dist[105];
int pre[105];
int flag[105];

void Dijkstra(int x)
{
	flag[x] = 1;
	dist[x] = 0;

	for (int i = 0; i < n; i++)
	{
		if (flag[i] == 0 && g[x][i] < INF)
		{
			dist[i] = g[x][i];
			pre[i] = x;
		}
	}

	int t;
	int minn;
	for (int i = 1; i <= n - 1; i++)
	{
		t = -1;
		minn = INF;
		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[j] < minn)
			{
				t = j;
				minn = dist[j];
			}
		}
		flag[t] = 1;

		for (int j = 0; j < n; j++)
		{
			if (flag[j] == 0 && dist[t] + g[t][j] < dist[j])
			{
				dist[j] = dist[t] + g[t][j];
				pre[j] = t;
			}
		}
	}

}

int main()
{
	scanf("%d %d", &n, &m);
	int x, y, w;

	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		pre[i] = -1;
		flag[i] = 0;
		for (int j = 0; j < n; j++)
		{
			g[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		g[x][y] = w;
		g[y][x] = w;
	}

	int k;
	scanf("%d", &k);
	Dijkstra(k);

	for (int i = 0; i < n; i++)
	{
		printf("%d的最短路径长度为%d\n", i, dist[i]);
		printf("最短路径为 %d ", i);
		int t = pre[i];
		while (t != -1)
		{
			printf("%d ", t);
			t = pre[t];
		}
		printf("\n");
	}

	return 0;
}