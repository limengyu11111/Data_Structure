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

	int x, j;
	for (int i = 1; i <= n - 1; i++)
	{
		x = a[i + 1];
		for (j = i; j >= 1; j--)
		{
			if (a[j] > x)
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = x;
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
3 1 7 5 2 4 9 6
*/