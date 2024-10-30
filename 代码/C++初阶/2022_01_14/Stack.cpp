#include "Stack.h"

void Stack::Init()  // 类定义了一个新的作用域，cpp文件中实现类的方法需要指定域
{
	_a = nullptr;
	_top = _capacity = 0;
}