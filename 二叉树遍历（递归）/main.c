#include<stdio.h>
#include<stdlib.h>
//广度遍历所需队列
typedef struct qnode
{
	int data;
	struct qnode* next;
}QNode;
typedef struct queue
{
	QNode* f;
	QNode* r;
}Queue;
Queue InitQueue()
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->next = NULL;
	Queue q;
	q.f = s;
	q.r = s;
	return q;
}
void EnQueue(int x, Queue* q)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->data = x;
	s->next = NULL;
	q->r->next = s;
	q->r = s;
}
int DeQueue(Queue* q)
{
	if (q->f == q->r)
	{
		printf("队列为空!\n");
		return -1;
	}
	QNode* s = q->f->next;
	if (q->f->next == q->r)
	{
		q->r = q->f;
	}
	q->f->next = s->next;
	int x = s->data;
	free(s);
	return x;
}

typedef struct btnode
{
	int data;
	struct btnode* l;
	struct btnode* r;
}BTNode, * BTree;
//初始化
BTree InitBTree(int x)
{
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->data = x;
	s->l = NULL;
	s->r = NULL;
	return s;
}
//查找结点
BTNode* Find(int fx, BTNode* root)
{
	if (root->data == fx)
		return root;
	if (root->l != NULL)
	{
		BTNode* ans = Find(fx, root->l);
		if (ans != NULL && ans->data == fx)
			return ans;
	}
	if (root->r != NULL)
	{
		BTNode* ans = Find(fx, root->r);
		if (ans != NULL && ans->data == fx)
			return ans;
	}
	return NULL;
}
//插入结点
BTNode* Insert(int x, int fx, int flag, BTree root)
{
	BTNode* f = Find(fx, root);
	BTNode* s = (BTNode*)malloc(sizeof(BTNode));
	s->data = x;
	s->l = NULL;
	s->r = NULL;
	if (flag == 0)
	{
		f->l = s;
	}
	else if (flag == 1)
	{
		f->r = s;
	}
	return root;
}
//广度遍历
void LevelOrderBT(BTree root)
{
	Queue q = InitQueue();
	EnQueue(root->data,&q);
	int x = 0;
	BTNode* s = NULL;
	while (q.f->next != NULL)
	{
		x = DeQueue(&q);
		printf("%d\n", x);
		s = Find(x, root);
		if (s->l != NULL)
			EnQueue(s->l->data, &q);
		if (s->r != NULL)
			EnQueue(s->r->data, &q);
	}
}
//前序中序后序遍历
void PreOrderBT(BTree root)
{
	if (root == NULL)
		return;
	printf("%d\n", root->data);
	PreOrderBT(root->l);
	PreOrderBT(root->r);
}
void InOrderBT(BTree root)
{
	if (root == NULL)
		return;
	InOrderBT(root->l);
	printf("%d\n", root->data);
	InOrderBT(root->r);
}
void PostOrderBT(BTree root)
{
	if (root == NULL)
		return;
	PostOrderBT(root->l);
	PostOrderBT(root->r);
	printf("%d\n", root->data);
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
		scanf_s("%d %d %d", &x, &fx,&flag);
		root = Insert(x, fx, flag, root);
	}
	//LevelOrderBT(root);
	//PreOrderBT(root);
	InOrderBT(root);
	//PostOrderBT(root);
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