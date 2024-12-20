#include <iostream>
using namespace std;

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
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator>(const Date& d1, const Date& d2)
//{
//	// 函数名：operator操作符
//	// 返回类型：取决于操作符运算后的返回值类型
//	// 参数：取决于操作符的操作数个数（1个或2个参数，3个操作数不支持运算符重载）
//	if (d1._year > d2._year)
//		return true;
//	else if (d1._year == d2._year && d1._month > d2._month)
//		return true;
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//		return true;
//	else
//		return false;
//}
//
//int main()  // 运算符重载
//{
//	Date day1(2022, 1, 16);
//	Date day2(2022, 1, 31);
//
//	// 判断两个日期先后以及计算日期相隔几天等（默认情况下，C++是不支持自定义类型对象使用运算符）
//	cout << (day1 > day2) << endl;  // 由于运算符<<比>优先级高，因此需要加括号
//	cout << operator>(day1, day2) << endl;
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
//	// 运算符重载在类内部实现，保证封装性
//	bool operator>(const Date& d)  // 隐藏this指针：bool operator>(Date* const this, const Date& d)
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		else
//			return false;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // 运算符重载
//{
//	Date day1(2022, 1, 16);
//	Date day2(2022, 1, 31);
//
//	cout << (day1 > day2) << endl;
//	cout << day1.operator>(day2) << endl;
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)  // 构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)  // 拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)  // 传值返回会将*this拷贝给临时变量，调用拷贝构造函数；传引用返回则不调用拷贝构造函数（手动增删&调试看二者差别）
	{
		if (this != &d)  // 极端情况下，自己给自己赋值不用处理，判断一下直接跳过  day1 = day1
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;  // 赋值运算符结果为左值  i = j = k = 10
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()  // 赋值运算符重载
{
	Date day1(2022, 1, 16);
	Date day2(2022, 1, 31);

	// 创建实例化的对象时，用已经存在的对象进行拷贝初始化
	Date day3(day1);  // 拷贝构造
	Date day4 = day2;  // 拷贝构造

	// 两个已经存在的对象之间进行赋值拷贝
	day1 = day2;  // day1.operator=(day2)

	return 0;
}