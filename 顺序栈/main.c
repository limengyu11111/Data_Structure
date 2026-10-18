#include<stdio.h>
#include<stdlib.h>
#define maxx 10
typedef struct stack
{
	int* data;
	int top;
}Stack;
Stack InitStack()
{
	Stack s;
	s.data = (int*)malloc(sizeof(int) * maxx);
	s.top = -1;
	return s;
}
void Push(Stack* s, int x)
{
	if (s->top == maxx - 1)
	{
		printf("Õ»ÒÑÂú£¡\n");
		return;
	}
	s->top += 1;
	s->data[s->top] = x;
}
//1 ¿Õ 0 ·Ç¿Õ
int IsEmpty(Stack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int Pop(Stack* s)
{
	if (IsEmpty(s))
	{
		printf("¿ÕÕ»£¡\n");
		return -1;
	}
	int x = s->data[s->top];
	s->top -= 1;
	return x;
}
int main()
{
	Stack s = InitStack();
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	int x = 0;
	x=Pop(&s);
	printf("%d\n", x);
	x=Pop(&s);
	printf("%d\n", x);
	x=Pop(&s);
	printf("%d\n", x);
	x=Pop(&s);
	printf("%d\n", x);
	return 0;
}