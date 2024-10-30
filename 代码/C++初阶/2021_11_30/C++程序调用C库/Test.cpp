// 该项目是C++程序，但需要调用C语言实现的静态库

#include <iostream>
using namespace std;

extern "C"  // C++与C语言的函数命名规则不同，故C++程序调用C语言库需要使用extern "C"
{
	// 告诉C++编译器，extern "C"{}里面的函数是C编译器编译的，链接的时候用C的函数名规则去找，就可以链接上
#include "./Stack_C/Stack.h"  // 包含相对路径的头文件
}

bool isValid(const char* s)  // C++函数实现需要调用数据结构的C语言库
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
				return false;
			}
			StackDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()  // 判断括号是否匹配的C++程序
{
	cout << isValid("{[]}") << endl;
	cout << isValid("([)]") << endl;

	return 0;
}