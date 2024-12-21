#include <iostream>
using namespace std;

//class A
//{
//public:
//	A() { cout << "A()" << endl; }
//	~A() { cout << "~A()" << endl; }
//};
//
//class B
//{
//public:
//	B() { cout << "B()" << endl; }
//	~B() { cout << "~B()" << endl; }
//};
//
//class C
//{
//public:
//	C() { cout << "C()" << endl; }
//	~C() { cout << "~C()" << endl; }
//};
//
//class D
//{
//public:
//	D() { cout << "D()" << endl; }
//	~D() { cout << "~D()" << endl; }
//};
//
//C c;
//int main()  // 四个对象的构造顺序和析构顺序
//{
//	A a;
//	B b;
//	static D d;
//	return 0;
//}

//class Widget
//{
//public:
//	Widget() { cout << "Widget()" << endl; }
//	Widget(const Widget&) { cout << "Widget(const Widget&)" << endl; }
//	Widget& operator=(const Widget&) { cout << "Widget& operator=(const Widget&)" << endl; return *this; }
//	~Widget() { cout << "~Widget()" << endl; }
//};
//
//Widget f(Widget u)
//{
//	Widget v(u);
//	Widget w = v;
//	return w;
//}
//
//int main()  // 拷贝构造函数调用次数
//{
//	Widget x;
//	Widget y = f(f(x));  // 拷贝构造函数次数被编译器优化（未优化9次）
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//void Print()  // this指针类型为Date* const this
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;
//	//}
//
//	void Print() const  // this指针类型为const Date* const this
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // const修饰类的成员函数
//{
//	Date d1;
//	d1.Print();
//
//	const Date d2(2022, 1, 17);  // const成员
//	d2.Print();  // 若不const修饰Print()成员函数，权限放大，无法调用
//
//	return 0;
//}

//class A
//{
//public:
//	// 普通对象和const对象取地址操作符重载一般不需要自己实现，编译器自动生成的即可
//	// 只有特殊情况才需要重载，比如只想让const对象取到地址，普通对象返回nullptr
//	A* operator&()
//	{
//		//return this;
//		return nullptr;
//	}
//
//	const A* operator&() const
//	{
//		return this;
//	}
//};
//
//int main()  // 普通对象和const对象取地址操作符重载
//{
//	A a1;
//	cout << &a1 << endl;
//
//	const A a2;
//	cout << &a2 << endl;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void operator<<(ostream& out) const
//	{
//		out << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // cout输出date类
//{
//	Date d(2022, 1, 17);
//
//	d.Print();
//
//	d.operator<<(cout);  // cout是一个对象
//	d << cout;  // 这样写不符合使用习惯，因此流插入操作符不能重载为成员函数
//
//	return 0;
//}

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);  // 友元函数
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day;
	return out;  // 支持连续输出
}

int main()  // 友元（friend）——提供了一种突破封装的方式，能够在类外访问private成员
{
	Date d1;
	Date d2(2022, 1, 17);

	operator<<(cout, d1) << endl;
	cout << d1 << endl;

	cout << d1 << "***" << d2 << endl;

	return 0;
}