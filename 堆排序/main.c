#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int n;
int a[105];

void DownAdjust(int f,int t)
{
	int now = f;
	int next;
	while (now * 2 <= t)
	{
		next = now * 2;
		if (now * 2 + 1 <= t && a[now * 2 + 1] > a[next])
		{
			next = now * 2 + 1;
		}
		if (a[now] < a[next])
		{
			int maxx = a[now];
			a[now] = a[next];
			a[next] = maxx;
		}
		else
			break;
		now = next;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = n / 2; i >= 1; i--)
	{
		DownAdjust(i, n);
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int maxx = a[1];
		a[1] = a[n - i + 1];
		a[n - i + 1] = maxx;
		DownAdjust(1, n - i);
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

/*
8
53 17 78 9 45 65 87 32
*/