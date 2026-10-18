#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}Node,*Stack;
Stack InitStack()
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->next = NULL;
	return s;
}
void Push(Stack s, int x)
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
		printf("¿ÕÕ»£¡\n");
		return;
	}
	Node* f = s->next;
	s->next = s->next->next;
	free(f);
}
int Front(Stack s)
{
	if (s->next == NULL)
	{
		printf("¿ÕÕ»£¡\n");
		return -1;
	}
	return s->next->data;
}
int main()
{
	int x = 0;
	Stack s = InitStack();
	Push(s, 1);
	Push(s, 2);
	Pop(s);
	x=Front(s);
	printf("%d\n", x);
	Pop(s);
	x=Front(s);
	printf("%d\n", x);
	Pop(s);
	x=Front(s);
	printf("%d\n", x);
	return 0;
}