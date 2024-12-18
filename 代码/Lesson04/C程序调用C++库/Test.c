// 该项目是C程序，但需要调用C++实现的静态库

#include <stdio.h>

//不是在C程序中extern "C"，而是需要在C++的静态库里extern "C"。C++的静态库在C程序中展开，但是C的编译器不认识extern "C"，故还需要条件编译
#include "./Stack_CPP/Stack.h"  // 包含相对路径的头文件

int isValid(const char* s)  // C函数实现需要调用数据结构的C++库
{
	Stack st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return 0;
			}
			StackDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
			{
				StackDestroy(&st);
				return 0;
			}
			else
			{
				++s;
			}
		}
	}
	int ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()  // 判断括号是否匹配的C语言程序
{
	printf("%d\n", isValid("{[]}"));
	printf("%d\n", isValid("([)]"));

	return 0;
}