#include<stdio.h>
#include<stdlib.h>
int f[200];
int Find(int x)
{
	if (f[x] < 0)
	{
		return x;
	}
	else
	{
		int t = Find(f[x]);
		f[x] = t;
		return t;
	}
}
void Union(int x, int y)
{
	int xx = Find(x);
	int yy = Find(y);
	if (xx == yy)
	{
		printf("同一集合\n");
	}
	else
	{
		if (-f[xx] > -f[yy])
		{
			f[yy] = xx;
		}
		else
		{
			if (f[xx] == f[yy])
				f[yy]--;
			f[xx] = yy;
		}
		printf("合并成功\n");
	}
}
int main()
{
	int n, m;//n个数据 m个操作
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf_s("%d", &x);
		f[x] = -1;
	}
	printf("1 查找 2 合并\n");
	for (int i = 1; i <= m; i++)
	{
		int chooce, x, y;
		scanf_s("%d %d %d", &chooce, &x, &y);
		if (chooce == 1)
		{
			printf("%d:%d  %d:%d\n", x, Find(x), y, Find(y));
		}
		else
		{
			Union(x, y);
		}
	}
	return 0;
}