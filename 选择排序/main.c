#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n;
int a[105];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int minn = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[minn])
			{
				minn = j;
			}
		}
		int t = a[minn];
		a[minn] = a[i];
		a[i] = t;
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}