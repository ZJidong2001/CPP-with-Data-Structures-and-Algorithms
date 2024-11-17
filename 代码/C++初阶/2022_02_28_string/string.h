#pragma once
#include <iostream>
#include <assert.h>

namespace zjd
{
	class string
	{
	public:
		typedef char* iterator;  // 普通迭代器
		typedef const char* const_iterator;  // const迭代器

		void swap(string& s)  // 两个string类对象的成员变量交换函数
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const char* str = "")  // 构造函数
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//string(const string& s)  // 拷贝构造函数（传统写法）
		//	:_size(s._size)
		//	, _capacity(s._capacity)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}

		string(const string& s)  // 拷贝构造函数（现代写法）
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		//string& operator=(const string& s)  // 赋值运算符重载函数（传统写法）
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}

		string& operator=(string s)  // 赋值运算符重载函数（现代写法）
		{
			swap(s);
			return *this;
		}

		~string()  // 析构函数
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char& operator[](size_t pos)  // []运算符重载函数
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const  // []运算符重载函数
		{
			assert(pos < _size);
			return _str[pos];
		}

		iterator begin()  // 迭代器
		{
			return _str;
		}

		iterator end()  // 迭代器
		{
			return _str + _size;
		}

		const_iterator begin() const  // 迭代器
		{
			return _str;
		}

		const_iterator end() const  // 迭代器
		{
			return _str + _size;
		}

		size_t size() const  // 返回有效字符个数函数
		{
			return _size;
		}

		void resize(size_t n, char ch = '\0')  // 调整有效字符个数函数
		{
			if (n <= _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
					reserve(n);
				memset(_str + _size, ch, n - _size);
				_size = n;
				_str[_size] = '\0';
			}
		}

		void reserve(size_t n)  // 调整字符最大存储容量函数
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)  // 尾插字符
		{
			if (_size == _capacity)
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)  // 尾插字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)  // +=运算符重载函数
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)  // +=运算符重载函数
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)  // 插入字符函数
		{
			assert(pos <= _size);
			if (_size == _capacity)
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)  // 插入字符串函数
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)  // 删除部分字符函数
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		const char* c_str() const  // 返回C字符串函数
		{
			return _str;
		}

		size_t find(char ch)  // 查找字符函数
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)  // 查找子串函数
		{
			const char* ptr = strstr(_str + pos, str);
			if (ptr == nullptr)
				return npos;
			else
				return ptr - _str;
		}

	private:
		char* _str;  // 字符串
		size_t _size;  // 有效字符个数
		size_t _capacity;  // 字符最大存储容量

	public:
		static const size_t npos = -1;  // size_t的最大值
	};

	bool operator<(const string& s1, const string& s2)
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] < s2[i2])
			{
				return true;
			}
			else if (s1[i1] > s2[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		return i2 < s2.size() ? true : false;
	}

	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	std::ostream& operator<<(std::ostream& out, const string& s)  // 没有用私有成员，可以不用友元
	{
		for (auto ch : s)
		{
			out << ch;
		}

		//for (size_t i = 0; i < s.size(); ++i)
		//{
		//	out << s[i];
		//}

		//out << s.c_str();  该写法错误，有时'\0'也算作有效字符

		return out;
	}

	std::istream& operator>>(std::istream& in, string& s)
	{
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
}