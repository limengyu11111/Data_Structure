#include<stdio.h>
#include<stdlib.h>

typedef struct huffmantree
{
	int w;
	int fi;
	int l;
	int r;
}HuffmanTree;

void Find(HuffmanTree* root, int x, int* s1, int* s2)
{
	int minn;
	for (int i = 0; i <= x; i++)
	{
		if (root[i].fi == -1)
		{
			minn = i;
			break;
		}
	}
	for (int i = 0; i <= x; i++)
	{
		if (root[i].fi == -1 && root[i].w < root[minn].w)
			minn = i;
	}
	*s1 = minn;
	for (int i = 0; i <= x; i++)
	{
		if (root[i].fi == -1&&i!=*s1)
		{
			minn = i;
			break;
		}
	}
	for (int i = 0; i <= x; i++)
	{
		if (root[i].fi == -1 && i != *s1 && root[i].w < root[minn].w)
			minn = i;
	}
	*s2 = minn;
}

HuffmanTree* CreateHuffmanTree(int n, int w[])
{
	int m = 2 * n - 1;
	HuffmanTree* tree = (HuffmanTree*)malloc(sizeof(HuffmanTree) * m);
	for (int i = 0; i < n; i++)
	{
		tree[i].fi = -1;
		tree[i].l = -1;
		tree[i].r = -1;
		tree[i].w = w[i];
	}
	int s1, s2;
	for (int i = n; i < m; i++)
	{
		Find(tree, i - 1, &s1, &s2);
		tree[i].w = tree[s1].w + tree[s2].w;
		tree[i].l = s1;
		tree[i].r = s2;
		tree[i].fi = -1;
		tree[s1].fi = i;
		tree[s2].fi = i;
	}
	return tree;
}

char** CreateCode(int n, HuffmanTree* tree)
{
	char* t = (char*)malloc(sizeof(char) * n);
	char** codes = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		codes[i] = NULL;
	}
	int p = 0, pre = 0;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		start = n - 1;
		t[start] = '\0';
		p = i;
		pre = tree[p].fi;
		while (pre != -1)
		{
			start--;
			if (tree[pre].l == p)
				t[start] = '1';
			else
				t[start] = '0';
			p = pre;
			pre = tree[p].fi;
		}
		codes[i] = (char*)malloc(sizeof(char) * (n - start));
		strcpy(codes[i], &t[start]);
	}
	return codes;
}

int main()
{
	int n;
	char a[105];
	int w[105];
	scanf_s("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf_s("%c", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	HuffmanTree* root = CreateHuffmanTree(n, w);
	char** codes = CreateCode(n, root);
	for (int i = 0; i < n; i++)
	{
		printf("%c: %s\n", a[i], codes[i]);
	}
}

/*
9
agmteh is
1 1 1 1 2 2 3 3 5 
*/


//hahaha