#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
	element data=0;
	int top= 0;
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return ;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
		return 0;
	}
	else 
		return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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