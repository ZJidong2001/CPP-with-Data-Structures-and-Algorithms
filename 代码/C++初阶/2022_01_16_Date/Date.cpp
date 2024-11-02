#include "Date.h"

int Date::GetMonthDay() const  // 获取指定年月的天数
{
	static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = monthDayArray[_month];
	if ((_month == 2) && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
		++day;
	return day;
}

Date::Date(int year, int month, int day)  // 全缺省的构造函数
{
	_year = year;
	_month = month;
	_day = day;
	if (!((_year >= 1) && (_month >= 1 && _month <= 12) && (_day >= 1 && _day <= GetMonthDay())))
	{
		cout << "非法日期：";
		Print();
	}
}

void Date::Print() const  // 输出日期
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date::operator>(const Date& d) const  // >运算符重载
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d) const  // ==运算符重载
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator>=(const Date& d) const  // >=运算符重载
{
	return *this > d || *this == d;
}

bool Date::operator<(const Date& d) const  // <运算符重载
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d) const  // <=运算符重载
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d) const  // !=运算符重载
{
	return !(*this == d);
}

Date& Date::operator+=(int day)  // 日期+=天数
{
	if (day < 0)
		return *this -= -day;

	_day += day;
	while (_day > GetMonthDay())
	{
		_day -= GetMonthDay();
		++_month;
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}

Date Date::operator+(int day) const  // 日期+天数
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator-=(int day)  // 日期-=天数
{
	if (day < 0)
		return *this += -day;

	_day -= day;
	while (_day < 1)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay();
	}
	return *this;
}

Date Date::operator-(int day) const  // 日期-天数
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator++()  // 前置++
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)  // 后置++
{
	Date ret(*this);
	*this += 1;
	return ret;
}

Date& Date::operator--()  // 前置--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)  // 后置--
{
	Date ret(*this);
	*this -= 1;
	return ret;
}

int Date::operator-(const Date& d) const  // 日期-日期
{
	Date max = *this;
	Date min = d;

	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int count = 0;
	while (min != max)
	{
		++min;
		++count;
	}

	return flag * count;
}

void Date::PrintWeekDay() const  // 输出日期对应星期
{
	static const char* weekDayArray[7] = { "周一","周二","周三","周四","周五","周六","周日" };
	int count = *this - Date(1900, 1, 1);  // 匿名对象，当前行创建，当前行销毁（生命周期仅在当前行）
	cout << weekDayArray[count % 7] << endl;
}