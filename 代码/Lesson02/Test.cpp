#include <iostream>
using namespace std;

//int main()  // cin、cout自动识别变量类型
//{
//	const char* str = "hello bit";
//	cout << str << endl;
//
//	int i = 1;
//	double d = 1.11;
//	cout << i << d << endl;  // 有多少位小数，cout就输出多少位
//	cin >> i >> d;  // 不需要像C语言一样使用取地址操作符&
//	cout << i << d << endl;
//
//	return 0;
//}

//struct Student
//{
//	char name[20];
//	int age;
//	// ...
//}s = { "张三",18 };
//
//int main()  // cin、cout与printf()、scanf()各有所长，哪个方便用哪个
//{
//	// CPP
//	cout << "姓名: " << s.name << endl;
//	cout << "年龄: " << s.age << endl << endl;  // CPP的cout不方便，一项一项写很麻烦
//
//	// C
//	printf("姓名: %s\n年龄: %d\n\n", s.name, s.age);  // 写结构体时，C语言的printf更方便，仅一行代码搞定
//
//	return 0;
//}

//void Func(int a = 0)  // 缺省参数
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func();  // 没有传参时，使用参数的默认值
//	Func(10);  // 传参时，使用指定的实参
//
//	return 0;
//}

//void func(int a = 10, int b = 20, int c = 30)  // 全缺省
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	// 只有以下四种传参方式
//	func();
//	func(1);  // 从左往右传参
//	func(1, 2);
//	func(1, 2, 3);
//
//	// func(, 2, );  // error，不能在调用的时候指定传给谁
//
//	return 0;
//}

//void func(int a, int b, int c = 30)  // 半缺省——必须从右往左缺省，且必须连续缺省
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	// 只有以下两种传参方式
//	func(1, 2);
//	func(1, 2, 3);
//
//	return 0;
//}

//#include "Stack.h"
//
//int main()  // 缺省参数的应用
//{
//	struct Stack st1;
//	StackInit(&st1);  // 不知道栈最多存多少个数据，就用缺省值初始化
//
//	struct Stack st2;
//	StackInit(&st2, 100);  // 知道栈最多存100个数据，显式传值，这样可以减少增容次数，提高效率
//
//	return 0;
//}

// 函数重载——一词多义，函数名相同，形参列表（参数个数或类型或顺序）不同

// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1.1, 2.2);
//
//	return 0;
//}

// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	f();
//	f(1);
//
//	return 0;
//}

// 3、参数顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a, char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//int main()
//{
//	f(10, 'A');
//	f('A', 10);
//
//	return 0;
//}

// 注意：参数列表相同，但返回值不同，不能构成重载——调用的时候不能区分
//int f(double d)
//{
//
//}
//
//void f(double d)
//{
//
//}
//
//int main()
//{
//	f(1.1);  // 无法确定调用哪个函数
//
//	return 0;
//}

// 注意：参数列表的缺省值不同，不能构成重载，只看参数列表的个数或类型或顺序不满足一个才重载
//void f(int a)
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	f();
//	f(1);
//
//	return 0;
//}

// 注意：参数列表不同，构成重载，但是缺省参数使用时会有问题
void f()
{
	cout << "f()" << endl;
}

void f(int a = 0)
{
	cout << "f(int a)" << endl;
}

int main()
{
	f();  // 调用存在歧义
	f(1);

	return 0;
}