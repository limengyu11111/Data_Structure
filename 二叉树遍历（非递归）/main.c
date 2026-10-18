#include<stdio.h>
#include<stdlib.h>
typedef struct btnode
{
	int data;
	struct btnode* l;
	struct btnode* r;
}BTNode,*BTree;
typedef struct node
{
	BTNode* data;
	struct node* next;
}Node,*Stack;
Stack InitStack()
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->next = NULL;
	return s;
}
void Push(Stack s, BTNode* x)
{
	Node* f = (Node*)malloc(sizeof(Node));
	f->data = x;
	f->next = s->next;
	s->next = f;
}
void Pop(Stack s)
{
	if (s->next == NULL)
	{
		printf("空栈！\n");
		return;
	}
	Node* f = s->next;
	s->next = s->next->next;
	free(f);
}
int IsEmpty(Stack s)//0 非空 1 空
{
	if (s->next == NULL)
		return 1;
	else
		return 0;
}
BTNode* Front(Stack s)
{
	if (s->next == NULL)
	{
		printf("空栈！\n");
		return NULL;
	}
	return s->next->data;
}
BTree InitBTree(int x)
{
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->l = NULL;
	s->r = NULL;
	s->data = x;
	return s;
}
BTNode* Find(BTree root, int x)
{
	if (root->data == x)
		return root;
	if (root->l != NULL)
	{
		BTNode* ans = Find(root->l, x);
		if (ans != NULL && ans->data == x)
			return ans;
	}
	if (root->r != NULL)
	{
		BTNode* ans = Find(root->r, x);
		if (ans != NULL && ans->data == x)
			return ans;
	}
	return NULL;
}
BTree Insert(BTree root, int x,int fx, int flag)
{
	BTNode* f = Find(root, fx);
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->data = x;
	s->l = NULL;
	s->r = NULL;
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
void PreOrder(BTree root)
{
	Stack s = InitStack();
	BTNode* f = root;
	while (IsEmpty(s) == 0 || f != NULL)
	{
		if (f != NULL)
		{
			printf("%d\n", f->data);
			Push(s, f);
			f = f->l;
		}
		else
		{
			f = Front(s);
			Pop(s);
			f = f->r;
		}
	}
}
void InOrder(BTree root)
{
	Stack s = InitStack();
	BTNode* f = root;
	while (IsEmpty(s) == 0 || f != NULL)
	{
		if (f != NULL)
		{
			Push(s, f);
			f = f->l;
		}
		else
		{
			f = Front(s);
			Pop(s);
			printf("%d\n", f->data);
			f = f->r;
		}
	}
}
int main()
{
	int x, n, fx;
	int flag;//0左 1右
	printf("x: n: \n");
	scanf_s("%d %d", &x, &n);
	BTree root = InitBTree(x);
	for (int i = 2; i <= n; i++)
	{
		printf("x: fx: flag:\n");
		scanf_s("%d %d %d", &x, &fx, &flag);
		root = Insert(root,x, fx, flag);
	}
	PreOrder(root);
	InOrder(root);
	return 0;
}
/*
1
9
2 1 0
5 1 1
3 2 1
6 5 1
4 3 0
7 6 0
8 7 0
11 7 1
*/