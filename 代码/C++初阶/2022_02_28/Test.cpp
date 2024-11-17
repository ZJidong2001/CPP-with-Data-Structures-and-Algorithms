#include <iostream>
using namespace std;

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
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
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
//int main()  // 深拷贝（传统写法）
//{
//	zjd::string s1("hello world");
//	zjd::string s2(s1);
//	zjd::string s3("string");
//	s1 = s3;
//	s1 = s1;
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
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(_str, tmp._str);
		//	}
		//	return *this;
		//}

		string& operator=(string s)  // 更简洁的推荐写法，只是无法避免自己给自己赋值（极少出现，无伤大雅）
		{
			swap(_str, s._str);
			return *this;
		}

		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

	private:
		char* _str;
	};
}

int main()  // 深拷贝（现代写法）
{
	zjd::string s1("hello world");
	zjd::string s2(s1);
	zjd::string s3("string");
	s1 = s3;
	s1 = s1;

	return 0;
}