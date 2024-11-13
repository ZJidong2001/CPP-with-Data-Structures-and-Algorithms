#include <iostream>
#include <string>
#include <list>
using namespace std;

//int main()  // string类对象的遍历操作
//{
//	string s("hello world");
//
//	for (size_t i = 0; i < s.size(); ++i)  // 方式1：[]+下标索引
//	{
//		s[i] += 1;
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	string::iterator it = s.begin();  // 方式2：迭代器
//	while (it != s.end())
//	{
//		*it -= 1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto& e : s)  // 方式3：范围for
//	{
//		e += 1;
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()  // 反向迭代器
//{
//	string s("hello world");
//
//	string::reverse_iterator rit = s.rbegin();  // 若定义麻烦可使用auto自动推导类型，即auto rit = s1.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()  // 迭代器是通用的遍历方式（所有的容器都可以使用迭代器去访问修改）
//{
//	list<int> lt(10, 5);  // 链表不支持[]+下标索引遍历
//
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	return 0;
//}

//int main()  // 非const/const 正向/反向 迭代器
//{
//	string s1("hello world");
//	const string s2("HELLO WORLD");
//
//	string::iterator it = s1.begin();  // 非const 正向 迭代器
//	while (it != s1.end())
//	{
//		*it += 1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	string::reverse_iterator rit = s1.rbegin();  // 非const 反向 迭代器
//	while (rit != s1.rend())
//	{
//		*rit -= 1;
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	string::const_iterator cit = s2.begin();  // const 正向 迭代器
//	while (cit != s2.end())
//	{
//		//*cit += 1;  // err，不可被修改
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//	string::const_reverse_iterator crit = s2.rbegin();  // const 反向 迭代器
//	while (crit != s2.rend())
//	{
//		//*crit -= 1;  // err，不可被修改
//		cout << *crit << " ";
//		++crit;
//	}
//	cout << endl;
//
//	// C++11增加了cbegin、cend、crbegin、crend，根据使用习惯选择即可
//
//	return 0;
//}

//int main()  // string类对象空间不够自动增容
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "capacity: " << sz << endl;
//	for (int i = 0; i < 1000; ++i)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity: " << sz << endl;
//		}
//	}
//
//	return 0;
//}

//int main()  // 利用reserve提高插入数据的效率，避免增容带来的开销
//{
//	string s;
//	s.reserve(1000);  // 申请至少能存储1000个字符的空间
//	size_t sz = s.capacity();
//	cout << "capacity: " << sz << endl;
//	for (int i = 0; i < 1000; ++i)
//	{
//		s += 'c';
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity: " << sz << endl;
//		}
//	}
//
//	return 0;
//}

//int main()  // resize将有效字符的个数改成n个，多出的空间用字符c填充
//{
//	string s1;
//	s1.reserve(100);
//
//	string s2;
//	s2.resize(100);
//
//	string s3;
//	s3.resize(100, 'x');
//
//	string s4("hello world");
//	s4.reserve(100);
//
//	string s5("hello world");
//	s5.resize(100, 'x');
//
//	string s6("hello world");
//	s6.resize(5);
//
//	return 0;
//}

//int main()  // c_str返回C格式字符串
//{
//	string s("hello world");
//	cout << s << endl;  // string类重载了流提取和流插入运算符，可以直接打印
//	cout << s.c_str() << endl;  // 返回C形式字符串的指针，也可以打印
//
//	return 0;
//}

//int main()  // c_str的使用场景（参数类型是const char*，则不能使用string类传参）
//{
//	string file("test.txt");
//	FILE* fout = fopen(file, "w");  // err，fopen的参数类型是const char*，而不是string
//	FILE* fout = fopen(file.c_str(), "w");  // fopen的参数类型是const char*，而不是string
//
//	return 0;
//}

//int main()  // string类对象的查找
//{
//	string file1("test.txt");  // 取出文件的后缀名
//
//	size_t pos1 = file1.find('.');
//	if (pos1 != string::npos)  // npos为-1，但类型是size_t，即很大的值
//	{
//		string suffix = file1.substr(pos1, file1.size() - pos1);
//		//string suffix = file1.substr(pos1);
//		cout << suffix << endl;
//	}
//
//	string file2("test.txt.zip");  // 取出文件的后缀名
//
//	size_t pos2 = file2.rfind('.');
//	if (pos2 != string::npos)  // npos为-1，但类型是size_t，即很大的值
//	{
//		string suffix = file2.substr(pos2, file2.size() - pos2);
//		//string suffix = file2.substr(pos2);
//		cout << suffix << endl;
//	}
//
//	string url("http://www.cplusplus.com/reference/string/string/find/");  // 取出网址的协议、域名、路径
//
//	size_t p1 = url.find(':');
//	string protocol = url.substr(0, p1);
//	cout << protocol << endl;
//
//	size_t p2 = url.find('/', p1 + 3);
//	string domain = url.substr(p1 + 3, p2 - (p1 + 3));
//	cout << domain << endl;
//
//	string uri = url.substr(p2 + 1);
//	cout << uri << endl;
//
//	return 0;
//}

//int main()  // string类对象的插入（insert不建议过多使用，效率低）
//{
//	string s("hello world");
//
//	s += ' ';  // 尾插效率高
//	s += "!!!!";
//	cout << s << endl;
//
//	s.insert(0, 1, 'x');  // 头插效率低，O(N)复杂度
//	s.insert(s.begin(), 'y');
//	s.insert(0, "test");
//	cout << s << endl;
//
//	s.insert(4, "&&&&&");  // 中间位置插入效率低，O(N)复杂度
//	cout << s << endl;
//
//	return 0;
//}

//int main()  // string类对象的删除（erase不建议过多使用，效率低）
//{
//	string s("hello world");
//
//	s.erase(0, 1);  // 尽量少用头部和中间删除，因为要挪动数据，效率低
//	s.erase(s.size() - 1);
//	cout << s << endl;
//
//	s.erase(3);
//	cout << s << endl;
//
//	return 0;
//}

//int main()  // 计算字符串最后一个单词的长度（错误做法）
//{
//	string s;
//
//	cin >> s;  // cin和scanf一样，默认以空格或换行进行间隔，导致无法获取全部字符串
//
//	size_t pos = s.rfind(' ');
//	if (pos == string::npos)
//	{
//		cout << s.size() << endl;
//	}
//	else
//	{
//		cout << s.size() - pos - 1 << endl;
//	}
//
//	return 0;
//}

//int main()  // 计算字符串最后一个单词的长度（正确做法）
//{
//	string s;
//
//	char ch = getchar();  // 逐个读取字符存入到字符串中，遇到换行符结束
//	//char ch = cin.get();
//	while (ch != '\n')
//	{
//		s += ch;
//		ch = getchar();
//		//ch = cin.get();
//	}
//
//	size_t pos = s.rfind(' ');
//	if (pos == string::npos)
//	{
//		cout << s.size() << endl;
//	}
//	else
//	{
//		cout << s.size() - pos - 1 << endl;
//	}
//
//	return 0;
//}

int main()  // 计算字符串最后一个单词的长度（正确做法）
{
	string s;

	getline(cin, s);  // 使用getline函数最简单，将逐个读取字符遇换行符结束的过程封装成了getline函数

	size_t pos = s.rfind(' ');
	if (pos == string::npos)
	{
		cout << s.size() << endl;
	}
	else
	{
		cout << s.size() - pos - 1 << endl;
	}

	return 0;
}