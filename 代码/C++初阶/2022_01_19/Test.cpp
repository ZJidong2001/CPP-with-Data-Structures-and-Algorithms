#include <iostream>
using namespace std;

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()  // 流提取<<、流插入>>运算符重载（友元函数）
//{
//	Date d1, d2;
//	cin >> d1 >> d2;  // 为了符合输入输出使用习惯，一般不通过成员函数实现，而是在类外部实现操作符重载；为了能访问类的私有成员变量，采用友元函数
//	cout << d1 << endl << d2 << endl;
//
//	return 0;
//}

//class Date
//{
//	// 成员变量定义的地方？
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;  // 成员变量赋值的地方
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;  // 成员变量声明的地方
//	int _month;
//	int _day;
//};
//
//int main()  // 构造函数体赋值
//{
//	Date d(2022, 1, 19);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)  // 成员变量定义的地方
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // 初始化列表
//{
//	Date d(2022, 1, 19);
//
//	return 0;
//}

//int main()  // 构造函数体赋值与初始化列表的形象理解
//{
//	// 构造函数体赋值
//	int i;  // 成员变量仅定义出来，值为随机值
//	i = 1;  // 构造函数体内成员变量赋值
//
//	// 初始化列表
//	int j = 1;  // 成员变量定义时就赋初始值
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)  // 无默认构造函数
//	{
//		_a = a;
//	}
//
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_N(10)
//		, _ref(_year)
//		, _aa(-1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	// 初始化列表位置和构造函数体内位置均可初始化
//	int _year;
//	int _month;
//	int _day;
//
//	// 只能在初始化列表位置初始化（因为这三类成员变量在定义时必须赋初始值）
//	const int _N;
//	int& _ref;
//	A _aa;
//};
//
//int main()  // 引用成员变量、const成员变量、自定义类型成员变量（该类没有默认构造函数）必须在初始化列表位置进行初始化
//{
//	Date d(2022, 1, 19);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)  // 默认构造函数
//	{
//		cout << "A(int a = 0)" << endl;
//		_a = a;
//	}
//
//	A(const A& aa)  // 拷贝构造函数
//	{
//		cout << "A(const A& aa)" << endl;
//		_a = aa._a;
//	}
//
//	A& operator=(const A& aa)  // 赋值运算符重载
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		_a = aa._a;
//		return *this;
//	}
//
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	//Date(int year, int month, int day, const A& aa)  // 构造函数体赋值
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//	_aa = aa;  // 调用一次构造函数、一次赋值运算符重载
//	//}
//
//	Date(int year, int month, int day, const A& aa)  // 初始化列表
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _aa(aa)  // 调用一次拷贝构造函数
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//};
//
//int main()  // 尽量使用初始化列表初始化
//{
//	A aa(10);
//	Date d(2022, 1, 19, aa);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()  // 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//{
//	A aa(1);
//	aa.Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year;
//};
//
//int main()  // 单个参数的构造函数可以隐式类型转换
//{
//	double d = 1.1;
//	int i = d;  // 隐式类型转换——相近类型（表示意义相似的类型）
//
//	int* p = nullptr;
//	int j = (int)p;  // 强制类型转换——无关类型
//
//	Date d1(2022);
//	Date d2 = 2022;  // 隐式类型转换
//	// 虽然d1、d2都是调用构造函数，但是过程不一样
//	// 本来用2022构造一个临时对象Date(2022)，再用这个对象拷贝构造d2
//	// 但是C++编译器在连续构造的过程中，多个构造会被优化，合二为一，所以这里被优化为一个构造
//
//	return 0;
//}

//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year;
//};
//
//int main()  // 用explicit修饰构造函数，将会禁止单参构造函数的隐式转换
//{
//	Date d1(2022);
//	Date d2 = 2022;
//
//	return 0;
//}

//int cnt = 0;  // 全局变量（计数器）统计缺陷很大，若想统计其他类无法使用，并且cnt可以随意修改
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++cnt;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		++cnt;
//	}
//
//private:
//	int _a;
//};
//
//void f(A a) {}
//
//int main()  // 计算程序中创建了多少个类对象（统计构造函数和拷贝构造函数的调用次数）
//{
//	A a1;
//	A a2 = 1;
//	A a3(a1);
//	f(a1);
//	cout << cnt << endl;
//
//	cnt++;
//	cout << cnt << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_sCnt;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		++_sCnt;
//	}
//
//	//int GetCount()
//	//{
//	//	return _sCnt;
//	//}
//
//	static int GetCount()  // 静态成员函数没有隐藏的this指针，不能访问任何非静态成员（只能访问静态成员变量和静态成员函数）
//	{
//		return _sCnt;
//	}
//
//private:
//	int _a;
//public:
//	static int _sCnt;
//};
//
//void f(A a) {}
//
//int A::_sCnt = 0;  // 静态成员变量必须在类外定义，定义时不添加static关键字
//
//int main()  // static成员——计算程序中创建了多少个类对象（统计构造函数和拷贝构造函数的调用次数）
//{
//	// 静态成员为所有类对象所共享，不属于某个具体的实例
//	A a1;
//	A a2 = 1;
//	A a3(a1);
//	f(a1);
//
//	// 类静态成员可用 类名::静态成员 或者 对象.静态成员 来访问（前提不受访问限定符限制，即public）
//	cout << A::_sCnt << endl;
//	cout << a1._sCnt << endl;
//	cout << a2._sCnt << endl;
//	cout << a3._sCnt << endl;
//
//	// 若_sCnt为private，通过提供一个公有的成员函数使用对象访问_sCnt
//	cout << a1.GetCount() << endl;
//	cout << a2.GetCount() << endl;
//	cout << a3.GetCount() << endl;
//
//	// 若公有的成员函数前有static，则通过类名可以访问_sCnt
//	cout << A::GetCount() << endl;
//
//	return 0;
//}

//class Sum
//{
//public:
//	Sum()
//	{
//		++_i;
//		_ret += _i;
//	}
//
//	static int GetRet()
//	{
//		return _ret;
//	}
//
//	static void Init()
//	{
//		_i = 0;
//		_ret = 0;
//	}
//
//private:
//	static int _i;
//	static int _ret;
//};
//
//int Sum::_i = 0;
//int Sum::_ret = 0;
//
//class Solution
//{
//public:
//	int Sum_Solution(int n)
//	{
//		Sum::Init();
//		Sum* p = new Sum[n];
//		delete[] p;
//		return Sum::GetRet();
//	}
//};
//
//int main()  // 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
//{
//	Solution st;
//	cout << st.Sum_Solution(10) << endl;
//
//	cout << Solution().Sum_Solution(10) << endl;
//
//	return 0;
//}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//
//class A
//{
//public:
//	A() {}  // 初始化列表阶段没有对成员变量初始化，它就会使用缺省值初始化
//
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//		cout << n << endl;
//	}
//
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值；静态成员变量不能给缺省值，必须在类外面全局位置定义初始化
//	int a = 10;  // 注意这里是声明，不是初始化
//	B b = 20;
//	int* p = (int*)malloc(40);
//	static int n;
//};
//
//int A::n = 10;
//
//int main()  // C++11支持非静态成员变量在声明时进行初始化赋值，但是要注意这里不是初始化，而是给声明的成员变量缺省值
//{
//	A aa;
//	aa.Print();
//
//	return 0;
//}

//class Time
//{
//	friend class Date;  // 声明Date类为Time类的友元类，则在Date类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 0;
//		_t._minute = 0;
//		_t._second = 0;
//	}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};

class A
{
private:
	static int k;
	int h;

public:
	// 1、内部类B和在全局定义基本一样，只是定义在A的类域中，受外部类A访问限定符限制
	// 2、内部类B天生就是外部类A的友元（即B可以访问A的私有成员，A不能访问B的私有成员）
	class B
	{
	public:
		void fb(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}

	private:
		int _b;
	};

	void fa(const B& b)
	{
		//cout << b._b << endl;  // err，A不是B的友元类，不能访问B的私有成员
	}
};

int A::k = 1;

int main()  // 内部类
{
	cout << sizeof(A) << endl;

	A aa;
	A::B b;

	return 0;
}