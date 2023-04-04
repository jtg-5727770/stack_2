#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	element data=0;
	int top= 0;
	s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return ;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����");
		return 0;
	}
	else 
		return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return 0;
	}
	else return s->data[(s->top)];
}
int main(void) {
	StackType s;
	srand(time(NULL));
	init_stack(&s);
	for (int i = 1; i <= 30; i++) {
		int rand_num = rand() % 100 + 1;

		if (rand_num % 2 == 0) {
			push(&s,rand_num);

			printf("push %d\n", rand_num);
		}
		else 
		    printf("pop %d\n", pop(&s));
	}
	system("pause");
	return 0;
}