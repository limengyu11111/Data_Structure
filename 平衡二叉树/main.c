#include<stdio.h>
#include<stdlib.h>
typedef struct avlnode
{
	int data;
	struct avlnode* l;
	struct avlnode* r;
	int h;
}AVLNode,*AVLTree;
int maxx(int a, int b)
{
	return a > b ? a : b;
}
int GetH(AVLNode* root)
{
	if (root != NULL)
		return root->h;
	else
		return 0;
}
AVLNode* CreateNode(int x)
{
	AVLNode* p = (AVLNode*)malloc(sizeof(AVLNode));
	p->data = x;
	p->h = 1;
	p->l = NULL;
	p->r = NULL;
	return p;
}
AVLNode* Left(AVLNode* root)
{
	AVLNode* x = root;
	AVLNode* y = root->r;
	x->r = y->l;
	y->l = x;
	x->h = maxx(GetH(x->l), GetH(x->r)) + 1;
	y->h = maxx(GetH(y->l), GetH(y->r)) + 1;
	return y;
}
AVLNode* Right(AVLNode* root)
{
	AVLNode* x = root;
	AVLNode* y = root->l;
	x->l = y->r;
	y->r = x;
	x->h = maxx(GetH(x->l), GetH(x->r)) + 1;
	y->h = maxx(GetH(y->l), GetH(y->r)) + 1;
	return y;
}
AVLNode* Insert(AVLNode* root, int x)
{
	if (root == NULL)
	{
		AVLNode* p = CreateNode(x);
		return p;
	}
	else if (x < root->data)
	{
		root->l = Insert(root->l, x);
		if (GetH(root->l) - GetH(root->r) >= 2)
		{
			if (x < root->l->data)
			{
				root = Right(root);
			}
			else
			{
				root->l = Left(root->l);
				root = Right(root);
			}
		}
	}
	else
	{
		root->r = Insert(root->r, x);
		if (GetH(root->r) - GetH(root->l) >= 2)
		{
			if (x > root->r->data)
			{
				root = Left(root);
			}
			else
			{
				root->r = Right(root->r);
				root = Left(root);
			}
		}
	}
	root->h = maxx(GetH(root->l), GetH(root->r)) + 1;
	return root;
}
AVLNode* Delete(AVLNode* root, int x)
{
	if (root == NULL)
	{
		printf("未找到数据\n");
		return root;
	}
	if (root->data == x)
	{
		if (root->l != NULL && root->r != NULL)
		{
			AVLNode* p = root->l;
			while (p->r != NULL)
				p = p->r;
			root->data = p->data;
			root->l = Delete(root->l, p->data);
			if (GetH(root->r) - GetH(root->l) >= 2)
			{
				AVLNode* ri = root->r;
				if (GetH(ri->r) > GetH(ri->l))
				{
					root = Left(root);
				}
				else
				{
					root->r = Right(root->r);
					root = Left(root);
				}
			}
		}
		else
		{
			if (root->l != NULL)
			{
				AVLNode* p = root;
				root = root->l;
				free(p);
				return root;
			}
			else
			{
				AVLNode* p = root;
				root = root->r;
				free(p);
				return root;
			}
		}
	}
	else
	{
		if (x < root->data)
		{
			root->l = Delete(root->l, x);
			if (GetH(root->r) - GetH(root->l) >= 2)
			{
				AVLNode* ri = root->r;
				if (GetH(ri->r) > GetH(ri->l))
				{
					root = Left(root);
				}
				else
				{
					root->r = Right(root->r);
					root = Left(root);
				}
			}
		}
		else
		{
			root->r = Delete(root->r, x);
			if (GetH(root->l) - GetH(root->r) >= 2)
			{
				AVLNode* le = root->l;
				if (GetH(le->l) > GetH(le->r))
				{
					root = Right(root);
				}
				else
				{
					root->l = Left(root->l);
					root = Right(root);
				}
			}
		}
	}
	if (root != NULL)root->h = maxx(GetH(root->l), GetH(root->r)) + 1;
	return root;
}
void InOrder(AVLTree root)
{
	if (root == NULL)return;
	InOrder(root->l);
	printf("%d ", root->data);
	int p = GetH(root->l) - GetH(root->r);
	printf("%d\n", p);
	InOrder(root->r);
}
int main()
{
	int n, k;
	AVLTree root = NULL;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &k);
		root = Insert(root, k);
	}
	InOrder(root);
	printf("\n");
	root = Delete(root, 5);
	InOrder(root);
	return 0;

}
/*
9
1 2 3 4 5 6 7 8 9
9
9 8 7 6 5 4 3 2 1
*/