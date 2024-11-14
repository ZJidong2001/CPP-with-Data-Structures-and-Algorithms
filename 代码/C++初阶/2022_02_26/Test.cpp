#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//int main()  // string类对象的比较大小
//{
//	string s1("hello world");
//	string s2("string");
//
//	cout << (s1 < s2) << endl;  // 比较字符串每个字符的ASCII码值
//
//	cout << ("hhhhh" < s2) << endl;
//	cout << (s1 < "ssssss") << endl;
//
//	return 0;
//}

//int main()  // string类对象与其他内置类型的转换
//{
//	int val = stoi("1234");
//	cout << val << endl;
//
//	string str = to_string(3.14);
//	cout << str << endl;
//
//	return 0;
//}

//class Solution
//{
//public:
//	bool isLetterOrNumber(char ch)
//	{
//		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
//	}
//
//	bool isPalindrome(string s)
//	{
//		int begin = 0, end = s.size() - 1;
//
//		while (begin < end)
//		{
//			while (begin < end && !isLetterOrNumber(s[begin]))
//				++begin;
//
//			while (begin < end && !isLetterOrNumber(s[end]))
//				--end;
//
//			if (tolower(s[begin]) != tolower(s[end]))
//				return false;
//
//			++begin;
//			--end;
//		}
//
//		return true;
//	}
//};
//
//int main()  // 验证一个字符串是否是回文
//{
//	Solution s;
//	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
//
//	cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
//
//	return 0;
//}

//namespace zjd
//{
//	class string
//	{
//	public:
//		string(const char* str)
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//	private:
//		char* _str;
//	};
//}
//
//int main()  // 浅拷贝
//{
//	zjd::string s1("hello world");
//	zjd::string s2(s1);
//
//	return 0;
//}

namespace zjd
{
	class string
	{
	public:
		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//string& operator=(const string& s)  // 自己赋值给自己会出现bug
		//{
		//	delete[] _str;
		//	_str = new char[strlen(s._str) + 1];
		//	strcpy(_str, s._str);
		//	return *this;
		//}

		//string& operator=(const string& s)  // 新空间开辟失败（抛异常通过try-catch捕获不会终止程序），旧空间数据也被销毁，设计不合理
		//{
		//	if (this != &s)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}

		string& operator=(const string& s)  // 正确写法
		{
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

	private:
		char* _str;
	};
}

int main()  // 深拷贝
{
	zjd::string s1("hello world");
	zjd::string s2(s1);
	zjd::string s3("string");
	s1 = s3;
	s1 = s1;

	return 0;
}