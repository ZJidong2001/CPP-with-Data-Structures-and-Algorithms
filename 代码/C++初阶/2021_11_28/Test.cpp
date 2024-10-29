#include <iostream>
using namespace std;

//int main()  // 引用——起别名
//{
//	int a = 10;
//
//	int& b = a;  // 引用，给变量a起别名为b
//	int* p = &a;  // 取地址，将a的地址取出来
//
//	return 0;
//}

//int main()  // 通过调试窗口看a和b的值和地址，理解引用的意义
//{
//	int a = 10;
//	int& b = a;
//
//	a = 20;
//	b = 30;
//
//	return 0;
//}

//int main()  // 引用在定义时必须初始化
//{
//	int a = 10;
//	int& b;  // err
//
//	return 0;
//}

//int main()  // 一个变量可以有多个引用
//{
//	int a = 10;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	return 0;
//}

//int main()  // 引用一旦引用一个实体，再不能引用其他实体
//{
//	int a = 10;
//	int b = 20;
//
//	// r变成b的引用？否 b赋值给r？是
//	int& r = a;
//	r = b;
//
//	// 引用不能更换实体，但是指针可以更换指向
//	int* p = &a;
//	p = &b;
//
//	return 0;
//}

// 引用使用场景——做参数
//void swap(int a, int b)  // 传值
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	return 0;
//}

//void swap(int* p1, int* p2)  // 传地址
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//
//	return 0;
//}

//void swap(int& r1, int& r2)  // 传引用
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	return 0;
//}

//void swap(int a, int b)  // _Z4swapii
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void swap(int* p1, int* p2)  // _Z4swappipi
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void swap(int& r1, int& r2)  // _Z4swapriri
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//int main()  // 他们三个构成函数重载，但是swap(x, y)调用时存在歧义，编译器不知道调用传值还是传引用
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	swap(x, y);
//
//	return 0;
//}

//#include "SingleList.h"
//
//int main()  // 引用做参数例子：二级指针和一级指针的引用
//{
//	SLTNode* plist = NULL;
//
//	SListPushBack(&plist, 1);  // 二级指针
//	SListPushBack(&plist, 2);  // 二级指针
//	SListPushBack(plist, 3);  // 一级指针的引用
//	SListPushBack(plist, 4);  // 一级指针的引用
//
//	SListPrint(plist);
//
//	return 0;
//}

// 引用使用场景——做返回值
//int Add(int a, int b)  // 传值返回
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//
//	return 0;
//}

//int& Add(int a, int b)  // 传引用返回（错误用法，返回对象还给系统）
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	Add(10, 20);
//	cout << ret << endl;
//
//	return 0;
//}

//int& Add(int a, int b)  // 传引用返回（正确用法，返回对象未还给系统）
//{
//	static int c = a + b;  // 静态变量或全局变量或堆上动态开辟的空间等不会还给系统
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	Add(10, 20);
//	cout << ret << endl;
//
//	return 0;
//}

//#include <time.h>  // 值和引用的作为参数类型的性能比较
//struct A { int a[10000]; }a;
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//int main()
//{
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)  // 调用10000次TestFunc1()
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)  // 调用10000次TestFunc2()
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//
//	return 0;
//}

//#include <time.h>  // 值和引用的作为返回值类型的性能比较
//struct A { int a[10000]; }a;
//A TestFunc1() { return a; }  // 传值返回——每次拷贝40000byte
//A& TestFunc2() { return a; }  // 传引用返回——没有拷贝
//int main()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)  // 调用10000次TestFunc1()
//		TestFunc1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)  // 调用10000次TestFunc2()
//		TestFunc2();
//	size_t end2 = clock();
//
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//
//	return 0;
//}

// 总结一下：引用的作用主要体现在传参和传返回值（以下两点，后面深入学习）
// 1、引用传参和传返回值，有些场景下面，可以提高性能。（大对象+深拷贝对象）
// 2、引用传参和传返回值，输出型参数和输出型返回值。通俗点说，有些场景下面，形参的改变可以改变实参，引用返回可以改变返回对象。

//int main()  // 常引用
//{
//	int a1 = 10;  // 权限不变，可以
//	int& b1 = a1;
//
//	const int a2 = 10;  // 权限放大，不可以
//	int& b2 = a2;  // a2不能修改，b2作为其引用更不能修改
//
//	const int a3 = 10;  // 权限不变，可以
//	const int& b3 = a3;
//
//	int a4 = 10;  // 权限缩小，可以
//	const int& b4 = a4;  // a4能修改，b4作为其引用不能修改也可以
//
//	return 0;
//}

// 假设x是一个大对象或者是深拷贝的对象（后面学习），那么尽量用引用传参，减少拷贝。
// 如果f函数中不改变x，建议尽量用cosnt引用传参。
void f1(int& x)  // int可以传参，const int不可以传参
{
	cout << x << endl;
}

void f2(const int& x)  // int和const int都可以传参
{
	cout << x << endl;
}

int main()
{
	int a = 10;
	const int b = 10;


	f1(a);  // int可以传参
	f1(b);  // const int不可以传参
	f1(10);  // 常量不可以传参

	f2(a);  // int可以传参
	f2(b);  // const int可以传参
	f2(10);  // 常量可以传参

	return 0;
}