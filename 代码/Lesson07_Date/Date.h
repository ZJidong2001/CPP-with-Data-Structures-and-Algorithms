#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay() const;  // 获取指定年月的天数
	Date(int year = 1, int month = 1, int day = 1);  // 全缺省的构造函数
	void Print() const;  // 输出日期

	bool operator>(const Date& d) const;  // >运算符重载
	bool operator==(const Date& d) const;  // ==运算符重载
	bool operator>=(const Date& d) const;  // >=运算符重载
	bool operator<(const Date& d) const;  // <运算符重载
	bool operator<=(const Date& d) const;  // <=运算符重载
	bool operator!=(const Date& d) const;  // !=运算符重载

	Date& operator+=(int day);  // 日期+=天数
	Date operator+(int day) const;  // 日期+天数
	Date& operator-=(int day);  // 日期-=天数
	Date operator-(int day) const;  // 日期-天数

	Date& operator++();  // 前置++
	Date operator++(int);  // 后置++（增加参数占位，通过函数重载区分前置后置++）
	Date& operator--();  // 前置--
	Date operator--(int);  // 后置--（增加参数占位，通过函数重载区分前置后置--）
	
	int operator-(const Date& d) const;  // 日期-日期

	void PrintWeekDay() const;  // 输出日期对应星期

private:
	int _year;
	int _month;
	int _day;
};