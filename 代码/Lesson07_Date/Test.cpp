#include <iostream>
#include "Date.h"
using namespace std;

void TestDate1()
{
	Date d1;
	d1.Print();

	Date d2(2022, 1, 16);
	d2.Print();

	Date d3(2022, 13, 15);
	d3.Print();

	Date d4(2022, 2, 29);
	d4.Print();

	Date d5(2020, 2, 29);
	d5.Print();

	Date d6(2000, 2, 29);
	d6.Print();
}

void TestDate2()
{
	Date d1(2001, 5, 15);
	Date d2(2011, 7, 19);

	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
}

void TestDate3()
{
	Date d(2022, 1, 16);

	Date d1 = d + 100;
	d1.Print();

	d += 100;
	d.Print();

	Date d2 = d - 100;
	d2.Print();

	d -= 100;
	d.Print();

	Date d3 = d + -100;
	d3.Print();

	d += -100;
	d.Print();

	Date d4 = d - -100;
	d4.Print();

	d -= -100;
	d.Print();
}

void TestDate4()
{
	Date d(2022, 1, 16);

	Date d1 = ++d;
	d.Print();
	d1.Print();

	Date d2 = d++;
	d.Print();
	d2.Print();

	Date d3 = --d;
	d.Print();
	d3.Print();

	Date d4 = d--;
	d.Print();
	d4.Print();
}

void TestDate5()
{
	Date d1(2001, 5, 15);
	Date d2(2001, 10, 8);

	cout << (d2 - d1) << endl;
	cout << (d1 - d2) << endl;
}

void TestDate6()
{
	Date(2001, 5, 15).PrintWeekDay();
	Date(2001, 10, 8).PrintWeekDay();
	Date(2022, 1, 16).PrintWeekDay();
}

int main()
{
	TestDate1();
	TestDate2();
	TestDate3();
	TestDate4();
	TestDate5();
	TestDate6();

	return 0;
}