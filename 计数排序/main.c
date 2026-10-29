#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int a[105];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	int cnt[10000], sum[10000];
	int maxx = a[1];
	for (int i = 0; i < 10000; i++)
	{
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
		if (a[i] > maxx)
			maxx = a[i];
	}
	sum[0] = 0;
	for (int i = 1; i <= maxx; i++)
	{
		sum[i] = sum[i - 1] + cnt[i];
	}

	int t[105];
	for (int i = n; i >= 1; i--)
	{
		t[sum[a[i]]] = a[i];
		sum[a[i]]--;
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", t[i]);
	}
	printf("\n");
	return 0;
}

/*
9
1 4 1 2 5 2 4 1 8
*/