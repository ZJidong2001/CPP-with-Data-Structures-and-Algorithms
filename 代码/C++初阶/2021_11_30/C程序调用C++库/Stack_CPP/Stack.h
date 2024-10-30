#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// 条件编译用法一
#ifdef __cplusplus  // C++的静态库在C程序中展开，但是C的编译器不认识extern "C"，故还需要条件编译
extern "C"  // C++静态库，就会按照C的函数名修饰规则去处理以下函数（但是里面不能用函数重载了）
{
#endif
	void StackInit(ST* ps);  // 初始化栈
	void StackPush(ST* ps, STDataType data);  // 入栈
	void StackPop(ST* ps);  // 出栈
	STDataType StackTop(ST* ps);  // 获取栈顶元素
	int StackSize(ST* ps);  // 获取栈中有效元素个数
	int StackEmpty(ST* ps);  // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
	void StackDestroy(ST* ps);  // 销毁栈
#ifdef __cplusplus
}
#endif

// 条件编译用法二
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

EXTERN_C void StackInit(ST* ps);  // 初始化栈
EXTERN_C void StackPush(ST* ps, STDataType data);  // 入栈
EXTERN_C void StackPop(ST* ps);  // 出栈
EXTERN_C STDataType StackTop(ST* ps);  // 获取栈顶元素
EXTERN_C int StackSize(ST* ps);  // 获取栈中有效元素个数
EXTERN_C int StackEmpty(ST* ps);  // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
EXTERN_C void StackDestroy(ST* ps);  // 销毁栈