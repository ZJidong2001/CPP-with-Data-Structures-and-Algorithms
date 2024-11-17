#include <iostream>
#include "string.h"
using namespace std;

void TestString1()
{
	zjd::string s1;
	zjd::string s2("hello world");
	zjd::string s3(s2);
	s1 = s3;
	s1 = s1;
}

void TestString2()
{
	zjd::string s1("hello world");
	const zjd::string s2("string");

	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s2.size(); ++i)
	{
		//s2[i] += 1;
		cout << s2[i] << " ";
	}
	cout << endl;

	for (zjd::string::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		*it -= 1;
		cout << *it << " ";
	}
	cout << endl;

	for (zjd::string::const_iterator it = s2.begin(); it != s2.end(); ++it)
	{
		//*it -= 1;
		cout << *it << " ";
	}
	cout << endl;

	for (auto e : s1)  // 支持迭代器就支持范围for，编译时被替换成迭代器（如果把begin换成Begin，则无法使用，因为迭代器有固定的格式）
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestString3()
{
	zjd::string s;
	cout << s.c_str() << endl;
	s.push_back('I');
	cout << s.c_str() << endl;
	s.append(" love wsl");
	cout << s.c_str() << endl;
	s += '!';
	cout << s.c_str() << endl;
	s += " ~.~";
	cout << s.c_str() << endl;
}

void TestString4()
{
	zjd::string s("abcdefg");
	cout << s.c_str() << endl;

	s.resize(5);
	cout << s.c_str() << endl;

	s.resize(9, 'x');
	cout << s.c_str() << endl;

	s.resize(20, 'y');
	cout << s.c_str() << endl;
}

void TestString5()
{
	zjd::string s("abcdefg");
	cout << s.find('f') << endl;
	cout << s.find("def") << endl;
	cout << s.find("dg") << endl;
}

void TestString6()
{
	zjd::string s("hello world");
	s.insert(3, 'x');
	cout << s.c_str() << endl;
	s.insert(0, 'x');
	cout << s.c_str() << endl;
	s.insert(0, "abcd");
	cout << s.c_str() << endl;
	s.erase(3);
	cout << s.c_str() << endl;
}

void TestString7()
{
	zjd::string s1("2019CAU");
	zjd::string s2("2023BUPT");
	cout << (s1 < s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 != s2) << endl;
}

void TestString8()
{
	zjd::string s;
	cin >> s;
	cout << s << endl;
}

int main()
{
	TestString1();
	TestString2();
	TestString3();
	TestString4();
	TestString5();
	TestString6();
	TestString7();
	TestString8();

	return 0;
}