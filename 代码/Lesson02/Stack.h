#pragma once
#include <stdlib.h>
#include <assert.h>

struct Stack
{
	int* a;
	int top;
	int capacity;
};

void StackInit(struct Stack* ps, int capacity = 4);  // 缺省参数不能在函数声明和定义中同时出现

// 推荐将缺省参数写在声明位置，因为查看函数如何使用时都是先看声明