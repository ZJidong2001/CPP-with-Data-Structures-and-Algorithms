#include "Stack.h"

void StackInit(ST* ps)  // 初始化栈
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x)  // 入栈
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)  // 出栈
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType StackTop(ST* ps)  // 获取栈顶元素
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)  // 获取栈中有效元素个数
{
	assert(ps);
	return ps->top;
}

int StackEmpty(ST* ps)  // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
{
	assert(ps);
	return ps->top == 0;
}

void StackDestroy(ST* ps)  // 销毁栈
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}