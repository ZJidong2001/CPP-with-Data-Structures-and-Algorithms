#include <iostream>
#include <string>
using namespace std;

//int Add(int left, int right)  // 专门处理int的加法函数
//{
//	return left + right;
//}
//
//template<class T>  // 通用加法函数
//T Add(T& left, T& right)
//{
//	return left + right;
//}
//
//int main()  // 模板参数的匹配原则
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	// 1、一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数
//	cout << Add<int>(a1, a2) << endl;  // 调用模板函数
//
//	// 2、对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
//	cout << Add(a1, a2) << endl;  // 调用非模板函数
//	cout << Add(d1, d2) << endl;  // 调用模板函数
//
//	// 3、模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
//	cout << Add(a1, d1) << endl;  // 调用非模板函数
//
//	return 0;
//}

//typedef int STDataType;
//typedef double STDataType;
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new STDataType[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()  // C语言不支持泛型编程，无法同时使用不同类型的栈
//{
//	Stack st1;  // 该栈想存储int类型
//	Stack st2;  // 该栈想存储double类型
//
//	return 0;
//}

//class StackInt
//{
//public:
//	StackInt(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~StackInt()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class StackDouble
//{
//public:
//	StackDouble(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new double[capacity];
//	}
//
//	~StackDouble()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	double* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()  // C语言若想同时使用不同类型的栈，唯一解决办法是分别实现不同类型的栈，但代码复用性差
//{
//	StackInt st1;  // 该栈想存储int类型
//	StackDouble st2;  // 该栈想存储double类型
//
//	return 0;
//}

//template<class T>
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new T[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(const T& x);  // 成员函数声明
//
//private:
//	T* _a;
//	int _top;
//	int _capacity;
//};
//
//template<class T>
//void Stack<T>::Push(const T& x)  // 成员函数实现
//{
//	// ...
//}
//
//int main()  // C++支持泛型编程，提供了类模板
//{
//	// 类模板实例化必须在类模板名字后跟<>，然后将实例化的类型放在<>中
//	Stack<int> st1;  // 该栈想存储int类型
//	Stack<double> st2;  // 该栈想存储double类型
//	Stack<char> st3;  // 该栈想存储char类型
//	Stack<int*> st4;  // 该栈想存储int*类型
//
//	st1.Push(1);
//	st2.Push(2.2);
//	st3.Push('a');
//
//	return 0;
//}

//template<class T>
//class basic_string
//{
//public:
//	// ...
//
//private:
//	T* _str;  // 指向动态申请空间的指针
//	// ...
//};
//
//typedef basic_string<char> string;  // string类并不是原生设计的类，而是basic_string类模板的实例化

// 为什么不直接实现string类，而是设计出basic_string类模板呢？
// 因为编码表（记录值与符号之间的映射关系）的不同，通过basic_string类模板可以处理不同类型的字符
// ASCII——英文编码表
// GBK——中文编码表
// Unicode——全世界文字编码表 utf-8、utf-16、utf-32

//int main()
//{
//	char str1[] = "hello";  // 计算机实际存的是ASCII码值，而不是字符
//	cout << str1 << endl;
//
//	char str2[] = "吃饭";  // 常见汉字占两个字节
//	cout << str2 << endl;
//
//	str2[1] += 1;  // 通过调试发现有意思的现象
//	str2[3] += 1;  // 打游戏骂人匹配词库变为*****，谐音字在编码的一段范围内，谐音字也能被屏蔽
//
//	str2[1] += 1;
//	str2[3] += 1;
//
//	str2[1] += 1;
//	str2[3] += 1;
//
//	cout << sizeof(char) << endl;  // 1Byte
//	cout << sizeof(wchar_t) << endl;  // 2Byte
//
//	return 0;
//}

//int main()  // string类对象的常见构造
//{
//	string s1;  // string()
//	cout << s1 << endl;
//
//	string s2("hello world");  // string(const char* s)
//	cout << s2 << endl;
//
//	string s3(s2);  // string(const string& str)
//	cout << s3 << endl;
//
//	string s4(s2, 2, 6);  // string(const string& str, size_t pos, size_t len = npos)
//	cout << s4 << endl;
//	string s5(s2, 2);
//	cout << s5 << endl;
//	string s6(s2, 2, 100);
//	cout << s6 << endl;
//
//	string s7("hello world", 3);  // string(const char* s, size_t n)
//	cout << s7 << endl;
//
//	string s8(10, '!');  // string(size_t n, char c)
//	cout << s8 << endl;
//
//	return 0;
//}

//int main()  // string类对象的容量操作
//{
//	string s;
//	cin >> s;
//	cout << s << endl;
//
//	cout << s.length() << endl;
//	cout << s.size() << endl;  // 二者无差别，但推荐size，学习其他容器（比如树对于size有意义，length无意义）成本降低
//
//	cout << s.max_size() << endl;  // 字符串的最大长度，和电脑内存有关，没啥意义
//
//	cout << s.capacity() << endl;  // 字符串的最大存储容量，当存储容量不够时就扩容
//
//	s.clear();  // 清空字符串的有效数据
//	cout << s << endl;
//
//	return 0;
//}

//char& operator[] (size_t pos)  // operator[]重载底层大概实现逻辑，由于传引用返回，故可读可写
//{
//	assert(pos < _size);
//	return _str[pos];
//}

//int main()  // string类对[]操作符重载，使得字符串像数组一样支持下标访问
//{
//	string s("hello world");
//
//	for (size_t i = 0; i < s.size(); ++i)  // 读
//	{
//		cout << s[i] << " ";  // 等价写法为s1.operator[](i)
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); ++i)  // 写
//	{
//		s[i] += 1;
//	}
//	cout << s << endl;
//
//	return 0;
//}

//int main()  // at与operator[]功能类似，只是检查越界的方式不一样
//{
//	string s("hello world");
//
//	for (size_t i = 0; i < s.size(); ++i)  // 读
//	{
//		cout << s.at(i) << " ";  // 等价写法为s1.operator[](i)
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); ++i)  // 写
//	{
//		s.at(i) += 1;
//	}
//	cout << s << endl;
//
//	s[100];  // assert断言（出错直接终止程序）
//
//	try
//	{
//		s.at(100);  // 抛异常（出错可以通过try-catch捕获，可以不终止程序）
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

int main()  // string类对象尾插
{
	string s;

	s.push_back('a');  // push_back尾插字符
	cout << s << endl;

	s.append("bcde");  // append尾插字符串
	cout << s << endl;

	s += ':';  // +=尾插字符
	cout << s << endl;

	s += "hello world";  // +=尾插字符串
	cout << s << endl;

	return 0;
}