#include "Stack.h"

void StackInit(struct Stack* ps, int capacity)  // 缺省参数不能在函数声明和定义中同时出现
{
	assert(ps);
	ps->a = (int*)malloc(sizeof(int) * capacity);
	ps->top = 0;
	ps->capacity = capacity;
}