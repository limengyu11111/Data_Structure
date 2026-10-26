#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void QSort(int a[], int l, int r)
{
	if (r <= l)
		return;

	int i = l, j = r;
	int p = a[i];

	while (i < j)
	{
		while (i < j && a[j] >= p)
			j--;
		if (i < j)
		{
			a[i] = a[j];
		}
		while (i < j && a[i] <= p)
			i++;
		if (i < j)
		{
			a[j] = a[i];
		}
	}

	a[i] = p;
	QSort(a, l, i - 1);
	QSort(a, i + 1, r);
}

int main()
{
	int n;
	int a[105];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	QSort(a, 1, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

/*
8
1 8 3 9 4 5 4 7
*/