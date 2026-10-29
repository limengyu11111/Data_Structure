#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int n;
int a[105];

void MergeSort(int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	MergeSort(l, mid);
	MergeSort(mid + 1, r);

	int i = l, j = mid + 1;
	int t[105], k = 1;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j])
		{
			t[k] = a[i];
			i++; k++;
		}
		if (a[i] > a[j])
		{
			t[k] = a[j];
			j++; k++;
		}
	}
	while (i <= mid)
	{
		t[k] = a[i];
		i++; k++;
	}
	while (j <= r)
	{
		t[k] = a[j];
		j++; k++;
	}
	for (i = 1; i < k; i++)
	{
		a[i + l - 1] = t[i];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	MergeSort(1, n);

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