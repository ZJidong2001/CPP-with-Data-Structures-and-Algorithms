#include <iostream>
using namespace std;

//int main()  // 引用——起别名
//{
//	int a = 10;
//	int& b = a;
//	int& c = b;
//
//	return 0;
//}

// 引用的价值：1、做参数——a.提高效率 b.形参的修改可以影响实参（输出型参数）

//struct Stack
//{
//	int a[100];
//	int top;
//}st;
//
//void Func1(struct Stack st) {}  // 传值——拷贝数据可能需要开辟极大空间
//void Func2(struct Stack* pst) {}  // 传地址——指针开辟4/8Byte空间
//void Func3(struct Stack& rst) {}  // 传引用——语法层面上看未开辟空间
//
//void StackInit1(struct Stack st) {}  // 传值——修改形参并不影响实参
//void StackInit2(struct Stack* pst) {}  // 传地址——通过指针，修改形参可以影响实参
//void StackInit3(struct Stack& rst) {}  // 传引用——形参的修改可以影响实参
//
//int main()
//{
//	Func1(st);
//	Func2(&st);
//	Func3(st);  // a.提高效率
//
//	StackInit1(st);
//	StackInit2(&st);
//	StackInit3(st);  // b.形参的修改可以影响实参（输出型参数）
//
//	return 0;
//}

// 引用的价值：2、做返回值——a.提高效率 b.修改返回变量

//int Add1(int a, int b)  // 传值返回——返回对象的值会拷贝给临时对象，返回的是临时对象
//{
//	int c = a + b;
//	return c;
//}
//int& Add2(int a, int b)  // 传引用返回——返回的是返回对象的引用
//{
//	static int c = a + b;  // 传引用返回前提是返回对象未还给系统
//	return c;
//}
//
//int main()
//{
//	int ret1 = Add1(1, 2);
//	int ret2 = Add2(3, 4);  // a.提高效率
//
//	return 0;
//}

//int& At(int i)  // 可读可写
//{
//	static int a[10];
//	return a[i];
//}
//
//int main()
//{
//	for (size_t i = 0; i < 10; ++i)
//	{
//		At(i) = 10 + i;  // b.修改返回变量
//	}
//
//	for (size_t i = 0; i < 10; ++i)
//	{
//		cout << At(i) << " ";
//	}
//
//	return 0;
//}

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

//int main()
//{
//	double d = 11.11;
//
//	int i1 = d;  // d可以写给i1（隐式类型转换不是直接发生的，转换中产生了一个临时变量）
//	int& i2 = d;  // 转换中产生了一个临时变量，临时变量具有常属性不可被修改，权限放大
//	const int& i3 = d;  // 转换中产生了一个临时变量，i3作为临时变量的引用
//
//	return 0;
//}

//void StackPrint(const struct Stack& st) {}  // 使用引用传参，如果函数中不改变参数的值，建议使用const &

//void f1(int* p)
//{
//	*p = 10;
//}
//
//void f2(int& r)
//{
//	r = 10;
//}
//
//int main()  // 指针与引用相比，指针过于灵活，不易于发现程序bug
//{
//	int a = 0;
//	f1(&a);
//	f2(a);
//
//	f1(NULL);  // err，但不易发现错误
//	f1(0);  // err，但不易发现错误
//
//	f2(NULL);  // err，引用在编译时就报错，更安全
//	f2(0);  // err
//
//	return 0;
//}

// 调用函数，需要建立栈帧，栈帧中要保存一些寄存器，结束后又要恢复——可以看到这些都是有消耗的
// 对于频繁调用的小函数，能否优化一下？
//int ADD(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	ADD(1, 2);
//	ADD(1, 2);
//	ADD(1, 2);
//	ADD(1, 2);
//	ADD(1, 2);
//	ADD(1, 2);
//	ADD(1, 2);
//	ADD(1, 2);
//
//	return 0;
//}

// C语言提供了宏替换（很容易写错，记住宏原理是替换，替换一下看看对不对）
//#define ADD(int x, int y) { return x + y;}  // err1（不是函数）
//#define ADD(int x, int y) return x + y;  // err2（不是函数）
//#define ADD(int x, int y) x + y;  // err3（不是函数）
//#define ADD(x, y) x + y;  // err4（没有分号）
//#define ADD(x, y) x + y  // err5（宏替换后优先级可能存在问题）
//#define ADD(x, y) (x + y)  // err6（宏替换后优先级可能存在问题）
//
//#define ADD(x, y) ((x) + (y))  // right
//
//int main()
//{
//	cout << ADD(3, 4) << endl;  // err4将变成 cout << 3 + 4; << endl;
//
//	cout << 10 * ADD(3, 4) << endl;  // err5将变成 cout << 10 * 3 + 4 << endl;
//
//	int a = 0, b = 1;
//	cout << ADD(a | b, a & b) << endl;  // err6将变成 cout << (a | b + a & b) << endl;
//
//	return 0;
//}

// 由此可见C语言的宏替换很复杂，容易出错，C++引入了内联函数的新语法
inline int Add(int x, int y)  // inline在release版本下就不会建立栈帧，只会在调用的地方展开
{
	int ret = x + y;
	return ret;
}

inline void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;

	int x = 0, y = 1;
	Swap(x, y);

	return 0;
}