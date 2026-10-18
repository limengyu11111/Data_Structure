#include<stdio.h>
#include<stdlib.h>
typedef struct btnode
{
	char data;
	struct btnode* l;
	struct btnode* r;
	int lflag;
	int rflag;
}BTNode,*BTree;
BTree InitBTree(char x)
{
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->data = x;
	s->l = NULL;
	s->r = NULL;
	s->lflag = 0;
	s->rflag = 0;
	return s;
}
BTNode* Find(BTNode* root,char x)
{
	if (root->data == x)
		return root;
	if (root->l != NULL && root->lflag == 0)
	{
		BTNode* ans = Find(root->l, x);
		if (ans != NULL && ans->data == x)
			return ans;
	}
	if (root->r != NULL && root->rflag == 0)
	{
		BTNode* ans = Find(root->r, x);
		if (ans != NULL && ans->data == x)
			return ans;
	}
	return NULL;
}
BTNode* Insert(BTNode* root, char x, char fx, int flag)
{
	BTNode* s = InitBTree(x);
	BTNode* f = Find(root, fx);
	if (flag == 0)
	{
		f->l = s;
	}
	else
	{
		f->r = s;
	}
	return root;
}
BTNode* pre = NULL;
void Visit(BTNode* p)
{
	if (p->lflag == 0 && p->l == NULL)
	{
		p->lflag = 1;
		p->l = pre;
	}
	if (pre != NULL && pre->rflag == 0 && pre->r == NULL)
	{
		pre->rflag = 1;
		pre->r = p;
	}
	pre = p;
}
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	if (root->lflag == 0)
	{
		InOrder(root->l);
	}
	Visit(root);
	if (root->rflag == 0)
	{
		InOrder(root->r);
	}
}
void Seek(char x, BTNode* root)
{
	BTNode* s = Find(root, x);
	if (s->l == NULL)
		printf("没前驱\n");
	else
	{
		if (s->lflag == 1)
		{
			printf("前驱: %c\n", s->l->data);
		}
		else
		{
			BTNode* ll = s->l;
			while (ll->r != NULL&&ll->rflag==0)
			{
				ll = ll->r;
			}
			printf("前驱: %c\n", ll->data);
		}
	}
	if (s->r == NULL)
		printf("没后继\n");
	else
	{
		if (s->rflag == 1)
		{
			printf("后继: %c\n", s->r->data);
		}
		else
		{
			BTNode* rr = s->r;
			while (rr->l != NULL&&rr->lflag==0)
			{
				rr = rr->l;
			}
			printf("后继: %c\n", rr->data);
		}
	}
	
}
int main()
{
	char x;
	int n;
	printf("n: x:\n");
	scanf_s("%d %c", &n, &x, sizeof(x));
	getchar();
	BTree root = InitBTree(x);
	int flag;
	char fx;
	for (int i = 2; i <= n; i++)
	{
		printf("x: fx: flag:\n");
		scanf_s(" %c %c %d", &x, sizeof(x), &fx, sizeof(fx), &flag);
		getchar();
		root = Insert(root, x, fx, flag);
	}
	printf("输入x，找x的前驱后继:\n");
	scanf_s(" %c", &x, sizeof(x));
	InOrder(root);
	printf("\n查找结果：\n");
	Seek(x, root);
	return 0;
}
/*
9 A
B A 0
E A 1
C B 1
D C 0
F E 1
G F 0
H G 0
K G 1
*/
