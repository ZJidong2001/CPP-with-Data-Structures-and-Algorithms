#include <iostream>

// 1、日常练习，不太在乎命名污染，using namespace std;全部展开
// 2、项目中，不要全部展开，指定访问或者展开常用
using namespace std;
//using std::cout;
//using std::endl;

//int main()  // C++输入输出
//{
//	int i = 0;
//	double d = 0;
//	std::cin >> i >> d;  // 流提取
//	cout << i << d << endl;  // 流插入
//	cout << "hello world" << endl;
//
//	return 0;
//}

//int main()  // &一个符号两用
//{
//	int a = 0;
//	int& r = a;  // 引用
//	int* p = &a;  // 取地址
//
//	return 0;
//}

//int main()  // 引用起别名的过程中，权限可以缩小或者不变，但是不能放大
//{
//	int a = 10;
//	int& a1 = a;  // 权限不变
//	const int& a2 = a;  // 权限缩小
//
//	const int b = 20;
//	int& b1 = b;  // err，权限放大
//	const int& b2 = b;  // 权限不变
//
//	return 0;
//}

//int main()  // 类型转换——中间产生临时变量（临时变量具有常属性，不可被修改）
//{
//	double d = 1.1;
//
//	int i = d;
//	int& r1 = d;  // err，权限放大
//	const int& r2 = d;
//
//	return 0;
//}

//int main()  // 反汇编调试看引用的底层原理（指针）
//{
//	int a = 1;
//
//	int& r = a;
//	int* p = &a;
//
//	r = 2;
//	*p = 3;
//
//	return 0;
//}

//int main()  // 虽然引用底层实现是指针，但是平时用的时候不要想底层，想成起别名即可
//{
//	char ch = 'a';
//	char& rch = ch;
//	cout << sizeof(rch) << endl;  // 1Byte
//
//	return 0;
//}

//int main()  // 早期的auto（C++现已废除，C还支持）：auto修饰的变量，是具有自动存储器的局部变量，函数结束变量自动销毁，没有任何意义
//{
//	int a = 10;
//	auto int b = 20;  // 加与不加auto没有任何区别
//
//	return 0;
//}

//int main()  // auto关键字（C++11）：自动推导类型（包括结构体）
//{
//	int a = 0;
//
//	auto b = a;  // 自动推导b的类型为int
//	auto c = 'A';  // 自动推导c的类型为char
//	auto d = 10.11;  // 自动推导d的类型为double
//
//	// 获取对象的类型
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}

//#include <map>
//#include <string>
//
//int main()  // auto实际使用场景1：定义类型冗长麻烦时可使用auto
//{
//	std::map<std::string, std::string> dict = { {"sort","排序"},{"insert","插入"} };
//
//	// std::map<std::string, std::string>::iterator it = dict.begin();  // 定义it太长，写起来麻烦
//	auto it = dict.begin();  // 根据右边的值去自动推导it的类型，写起来就方便了
//
//	return 0;
//}

//int main()  // auto与指针和引用结合起来使用
//{
//	// 用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&
//	int x = 10;
//	auto a = &x;  // int*
//	auto* b = &x;  // int*
//	auto& c = x;  // int
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	*a = 20;
//	*b = 30;
//	c = 40;
//
//	return 0;
//}

//int main()  // auto自动去除const属性，若想具有常属性可以使用const auto
//{
//	const int x = 10;
//
//	auto y = x;
//	y = 20;  // y可以修改，auto自动去除const属性
//
//	const auto z = x;  // 使用const auto具有常属性
//	z = 30;  // err，不可修改
//
//	return 0;
//}

//int main()  // auto定义变量时必须对其进行初始化，不能独立定义
//{
//	int i = 0;
//	auto j;  // err
//
//	return 0;
//}

//void TestAuto(auto a) {}  // 此处代码编译失败，由于auto不能独立定义，编译器无法对a的实际类型进行推导，因此不能作为形参类型

//int main()  // auto不能直接用来声明数组
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4,5,6 };  // err
//
//	return 0;
//}

//int main()  // auto实际使用场景2：范围for
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	// C/C++传统遍历数组
//	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	{
//		cout << array[i] << endl;
//	}
//
//	// 语法糖——C++11范围for遍历数组
//	for (auto e : array)  // 自动依次取数组array中的每个元素赋值给e
//	{
//		cout << e << endl;
//	}
//	for (int x : array)  // 此处可以用int，但是写范围for代码时常用auto
//	{
//		cout << x << endl;
//	}
//
//	// 范围for把array数组中每个值加1
//	for (auto e : array)  // err，将array数组中的元素依次赋值给e，e的改变不影响数组里的值
//	{
//		e++;
//	}
//	for (auto& e : array)  // right
//	{
//		e++;
//	}
//
//	return 0;
//}

//void TestFor(int a[])  // 范围for必须是数组
//{
//	for (auto& e : a)  // 此处的a退化成指针，不是数组
//		cout << e << endl;
//}
//
//int main()
//{
//	int array[5] = { 1,2,3,4,5 };
//	TestFor(array);
//
//	return 0;
//}

//int main()  // 指针空值nullptr（C++11）
//{
//	// C++98/03——初始化空指针使用NULL（NULL本质是宏替换）
//	int* p1 = NULL;  // 绝大部分场景使用NULL没问题，极端情况下会有问题
//	int* p2 = 0;
//
//	// C++11——初始化空指针推荐使用nullptr
//	int* p3 = nullptr;
//
//	return 0;
//}

//void f(int)  // 只要函数里面不用形参名，只给类型不给形参名也是可以的（类型必须给）
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()  // 空指针NULL极端情况下会有问题
//{
//	f(NULL);  // 按理应该匹配f(int*)函数
//	f(0);  // 按理应该匹配f(int)函数
//	// 但是以上两种都匹配了f(int)函数，存在缺陷
//
//	f(nullptr);  // 因此C++对于空指针不推荐使用NULL，而是nullptr
//
//	return 0;
//}

//#include <string>
//
//struct Student  // C++定义类的两个关键字struct/class
//{
//	char name[10];
//	int age;
//	int id;
//};
//
//int main()  // struct在C++中，既兼容C的结构体用法，同时也升级成了类
//{
//	struct Student s1;  // 结构体
//	strcpy(s1.name, "张三");
//	s1.age = 20;
//	s1.id = 1;
//
//	Student s2;  // 类
//	strcpy(s2.name, "李四");
//	s2.age = 23;
//	s2.id = 2;
//
//	return 0;
//}

//#include <string>
//
//struct Student
//{
//	// 属性
//	char _name[10];
//	int _age;
//	int _id;
//
//	// 方法
//	void Init(const char* name, int age, int id)  // 避免属性名和方法参数名冲突，在属性名前面或后面加_以示区分
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl << _age << endl << _id << endl;
//	}
//};
//
//int main()  // 类和结构体的区别：类不仅可以定义属性，还可以定义方法
//{
//	Student s1;
//	Student s2;
//
//	s1.Init("张三", 20, 1);
//	s2.Init("李四", 23, 2);
//
//	s1.Print();
//	s2.Print();
//
//	return 0;
//}

//#include <string>
//
//class Student  // C++更习惯用class定义类
//{
//	// 面向对象三大特性：封装、继承、多态
//	// 封装：1、属性和方法都在类里面放到了一起 2、使用访问限定符public/protected/private
//
//	// 一般在定义类的时候，建议明确指定访问限定符，不要用class/struct默认限定
//private:
//	// 属性
//	char _name[10];
//	int _age;
//	int _id;
//
//public:
//	// 方法
//	void Init(const char* name, int age, int id)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void Print()
//	{
//		cout << _name << endl << _age << endl << _id << endl;
//	}
//};
//
//int main()  // class默认访问权限为private，struct默认访问权限为public
//{
//	Student s1;
//	Student s2;
//
//	s1.Init("张三", 20, 1);
//	s2.Init("李四", 23, 2);
//
//	s1.Print();
//	s2.Print();
//
//	return 0;
//}

//class Stack
//{
//public:
//	void StackInit()
//	{
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void StackPush(int x)
//	{
//		if (_top == _capacity)
//		{
//			int newCapacity = _capacity == 0 ? 4 : _capacity * 2;
//			int* tmp = (int*)realloc(_a, sizeof(int) * newCapacity);
//			if (tmp == NULL)
//			{
//				printf("realloc fail\n");
//				exit(-1);
//			}
//			_a = tmp;
//			_capacity = newCapacity;
//		}
//		_a[_top] = x;
//		_top++;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()  // C++封装的好处——插入数据仅能调用对外公开的方法，不能直接修改隐藏的属性（避免C语言乱操作的现象）
//{
//	Stack st;
//	st.StackInit();
//	st.StackPush(1);
//	st.StackPush(4);
//
//	return 0;
//}

//#include "Stack.h"
//
//int main()  // 类的作用域
//{
//	Stack st;
//	st.Init();
//
//	return 0;
//}

//#include "Stack.h"
//
//int main()  // 计算类或者类对象所占内存空间的大小，只看成员变量（考虑内存对齐规则，和C的结构体一致）
//{
//	Stack s1;
//	Stack s2;
//
//	// 对象中存了成员变量，是否存了成员函数呢？否
//	cout << sizeof(Stack) << endl;  // 12
//	cout << sizeof(s1) << endl;  // 12
//	cout << sizeof(s2) << endl;  // 12
//
//	// 每个对象都有其相对应的成员变量，不同对象之间的空间是独立的
//	s1._top = 0;
//	s2._top = -1;
//
//	// 每个对象调用的成员函数是一致的，成员函数存放在公共的代码段
//	s1.Init();
//	s2.Init();
//
//	return 0;
//}

class A1  // 类中既有成员变量，又有成员函数
{
public:
	void f1() {}
private:
	int _a;
};

class A2  // 类中仅有成员函数
{
public:
	void f2() {}
};

class A3  // 类中什么都没有——空类
{};

int main()  // 计算A1、A2、A3三个类所占内存空间的大小
{
	// 空类和仅有成员函数的类，会开辟1Byte的空间
	cout << sizeof(A1) << endl;  // 4
	cout << sizeof(A2) << endl;  // 1
	cout << sizeof(A3) << endl;  // 1

	// 为何开辟1Byte的空间？这1byte不存储有效数据，只是为了占位，表示对象存在
	A2 a;
	A3 b;
	cout << &a << endl;  // 若不开辟空间，则取地址为空指针，那样无法区分对象a和b
	cout << &b << endl;

	return 0;
}