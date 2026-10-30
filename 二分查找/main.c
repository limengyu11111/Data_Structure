#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, a[105], k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);

	int l=1, r=n, mid;
	int ans = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (k == a[mid])
		{
			ans = mid;
			break;
		}
		else
		{
			if (k > a[mid])
			{
				l = mid+1;
			}
			else
			{
				r = mid-1;
			}
		}
	}
	if (ans == -1)
		printf("no!\n");
	else
		printf("yes!\n");

	return 0;
}

/*
11
5 13 19 21 37 56 64 75 80 88 92
10
*/