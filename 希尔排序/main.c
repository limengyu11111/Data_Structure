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

	int k = 0;
	for (int d = n / 2; d >= 1; d /= 2)
	{
		k++;
		int x, j;
		for (int i = 1 + d; i <= n; i++)
		{
			x = a[i];
			for (j = i - d; j >= 1; j -= d)
			{
				if (a[j] > x)
				{
					a[j + d] = a[j];
				}
				else
					break;
			}
			a[j + d] = x;
		}

		printf("第%d次排序后的结果:\n", k);
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}

/*
8
3 1 7 5 2 4 9 6
*/