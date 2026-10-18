#include<stdio.h>
#include<stdlib.h>
typedef struct bstnode
{
	int data;
	struct bstnode* l;
	struct bstnode* r;
}BSTNode,*BSTree;

BSTNode* CreateNode(int data)
{
	BSTNode* root = (BSTNode*)malloc(sizeof(BSTNode));
	root->data = data;
	root->l = NULL;
	root->r = NULL;
	return root;
}
//查找(非递归)
BSTNode* Find01(int x, BSTNode* root)
{
	while (root != NULL && root->data != x)
	{
		if (x < root->data)
		{
			root = root->l;
		}
		else
		{
			root = root->r;
		}
	}
	return root;
}
//查找(递归)
BSTNode* Find02(int x, BSTNode* root)
{
	if (root == NULL || root->data == x)
		return root;
	if (x < root->data)
	{
		return Find02(x, root->l);
	}
	else
	{
		return Find02(x, root->r);
	}
}
//插入(非递归)
BSTNode* Insert01(int x, BSTNode* root)
{
	if (root == NULL)
	{
		root = CreateNode(x);
		return root;
	}
	BSTNode* p = root;
	BSTNode* pre = NULL;
	while (p!=NULL)
	{
		pre = p;
		if (x < p->data)
		{
			p = p->l;
		}
		else
		{
			p = p->r;
		}
	}
	BSTNode* s = CreateNode(x);
	if (x < pre->data)
	{
		pre->l = s;
	}
	else
	{
		pre->r = s;
	}
	return root;
}
//插入(递归)
BSTNode* Insert02(int x, BSTNode* root)
{
	if (root == NULL)
	{
		BSTNode* s = CreateNode(x);
		return s;
	}
	if (x < root->data)
	{
		root->l = Insert02(x, root->l);
	}
	else
	{
		root->r = Insert02(x, root->r);
	}
	return root;
}
//中序遍历
void InOrder(BSTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->l);
	printf("%d\n", root->data);
	InOrder(root->r);
	return;
}
BSTNode* Delete01(BSTree root, int x)
{
	if (root == NULL)
	{
		printf("空树\n");
		return root;
	}
	BSTNode* p = root;
	BSTNode* pre = NULL;
	while (p != NULL && p->data != x)
	{
		pre = p;
		if (x < p->data)
			p = p->l;
		else
			p = p->r;
	}
	if (p == NULL)
	{
		printf("未找到\n");
		return root;
	}
	if (p->l != NULL && p->r != NULL)
	{
		BSTNode* q = p->l;
		BSTNode* qpre=p;
		while (q->r != NULL)
		{
			qpre = q;
			q = q->r;
		}
		p->data = q->data;
		p = q;
		pre = qpre;
	}
	BSTNode* ch = NULL;
	if (p->l != NULL)
		ch = p->l;
	else
		ch = p->r;
	if (pre == NULL)
	{
		root = ch;
	}
	else
	{
		if (pre->l == p)
		{
			pre->l = ch;
		}
		else
		{
			pre->r = ch;
		}
		free(p);
	}
	return root;
}
BSTNode* Delete02(BSTree root, int x)
{
	if (root == NULL)
	{
		printf("未找到\n");
		return root;
	}
	if (root->data == x)
	{
		if (root->l != NULL && root->r != NULL)
		{
			BSTNode* p = root->l;
			while (p->r != NULL)
				p = p->r;
			root->data = p->data;
			root->l = Delete02(root->l, p->data);
		}
		else
		{
			BSTNode* s = root;
			if (root->l != NULL)
				root = root->l;
			else
				root = root->r;
			free(s);
			return root;
		}
	}
	else if (x < root->data)
		root->l = Delete02(root->l, x);
	else
		root->r = Delete02(root->r, x);
	return root;
}
int main()
{
	int n, x;
	scanf_s("%d", &n);
	BSTree root = NULL;
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &x);
		root = Insert01(x, root);
	}
	InOrder(root);
	scanf_s("%d", &x);
	root = Delete01(root, x);
	InOrder(root);
	//BSTNode* p = Find01(x, root);
	//if (p == NULL)printf("该结点不存在\n");
	//else printf("该结点存在\n");
}
/*
9
8 3 10 1 6 14 4 7 13
*/