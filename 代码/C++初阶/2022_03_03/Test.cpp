#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//int main()  // vector构造函数
//{
//	vector<int> v1;  // 无参构造
//
//	vector<int> v2(10, 8);  // 构造并初始化n个val
//
//	vector<int> v3(v2);  // 拷贝构造
//
//	vector<int> v4(v2.begin(), v2.end());  // 使用迭代器进行初始化构造
//	vector<int> v5(++v2.begin(), --v2.end());
//	string s("hello world");
//	vector<char> v6(s.begin(), s.end());
//
//	return 0;
//}

//int main()  // vector遍历
//{
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(8);
//
//	for (size_t i = 0; i < v.size(); ++i)  // 下标索引
//	{
//		v[i] += 1;
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();  // 迭代器
//	while (it != v.end())
//	{
//		*it -= 1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : v)  // 范围for
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()  // vector的空间增长问题
//{
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(1);
//	v.reserve(100);
//	v.resize(50);
//	v.resize(100, 5);
//
//	return 0;
//}

//int main()  // vector的访问
//{
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(1);
//
//	v[6];  // 断言
//	v.at(6);  // 抛异常
//
//	return 0;
//}

//int main()  // vector的assign函数
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	v.assign(10, 5);  // 删除vector中的所有元素，重新赋值
//
//	return 0;
//}

//int main()  // vector、list等本身未实现find函数，都复用了algorithm里的find
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator ret = find(v.begin(), v.end(), 3);
//	if (ret != v.end())
//		cout << "找到了" << endl;
//	else
//		cout << "没找到" << endl;
//
//	return 0;
//}

//int main()  // vector的增删操作
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator ret = find(v.begin(), v.end(), 3);
//	if (ret != v.end())  // 在某个位置增删需要判断该位置是否找到
//	{
//		v.insert(ret, 30);
//		//v.insert(ret, 40);  // err - 不能再使用该迭代器增删数据，迭代器失效问题
//	}
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	v.insert(v.begin(), -1);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 4);
//	if (pos != v.end())
//	{
//		v.erase(pos);
//	}
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	v.clear();
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

int main()  // vector增容规律
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	cout << "capacity: " << sz << endl;
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity: " << sz << endl;
		}
	}

	return 0;
}