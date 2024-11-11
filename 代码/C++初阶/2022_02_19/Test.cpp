#include <iostream>
using namespace std;

//struct ListNode
//{
//	ListNode* prev;
//	ListNode* next;
//	int val;
//};
//
//int main()  // C语言动态内存管理
//{
//	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//	node->prev = node->next = NULL;
//	node->val = 0;
//
//	free(node);
//	node = NULL;
//
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _prev;
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val)
//		:_prev(nullptr)
//		, _next(nullptr)
//		, _val(val)
//	{};
//};
//
//int main()  // C++动态内存管理
//{
//	ListNode* node = new ListNode(0);
//
//	delete node;
//	node = nullptr;
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()  // C++推荐使用new、delete
//{
//	// 栈上开辟空间
//	Stack st1;
//
//	// 堆上开辟空间
//	Stack* pst2 = new Stack;  // 开辟空间 + 构造函数初始化
//	delete pst2;  // 析构函数清理资源 + 释放空间
//	pst2 = nullptr;
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()  // operator new与operator delete函数（反汇编查看）
//{
//	Stack* pst1 = (Stack*)operator new(sizeof(Stack));  // 与malloc类似，并未对空间进行初始化，只是增加了抛异常
//	operator delete(pst1);  // 与free类似，并未对空间进行资源清理，只是增加了抛异常
//	pst1 = nullptr;
//
//	Stack* pst2 = new Stack;
//	delete pst2;
//	pst2 = nullptr;
//
//	// new = operator new + 调用构造函数
//	// operator new = malloc + 开辟空间失败抛异常
//
//	// delete = 调用析构函数 + operator delete
//	// operator delete = free + 释放空间失败抛异常
//
//	return 0;
//}

//int main()  // C处理错误方式（返回值+错误码）、C++处理错误方式（抛异常）
//{
//	char* p1 = (char*)malloc(0x7fffffff);  // malloc开辟空间失败返回空指针
//	if (p1 == NULL)  // 需要通过if语句检查
//	{
//		printf("%d\n", errno);
//		perror("malloc fail");
//		exit(-1);
//	}
//	else
//	{
//		printf("%p\n", p1);
//	}
//
//	try
//	{
//		char* p2 = new char[0x7fffffff];  // new开辟空间失败直接抛异常（若不通过try-catch捕获，则崩溃终止程序）
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//void f()
//{
//	char* p = new char[0x7fffffff];  // 抛异常后直接跳到catch部分，后续代码不会执行
//	cout << "hello" << endl;
//}
//
//int main()  // try-catch捕获异常可以跳跃函数
//{
//	try
//	{
//		f();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()  // new和delete的实现原理
//{
//	Stack* pst1 = new Stack;  // new的原理
//	// 1、调用operator new函数申请空间
//	// 2、在申请的空间上执行构造函数，完成对象的构造
//
//	delete pst1;  // delete的原理
//	// 1、在空间上执行析构函数，完成对象中资源的清理工作
//	// 2、调用operator delete函数释放对象的空间
//
//	Stack* pst2 = new Stack[10];  // new T[N]的原理
//	// 1、调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
//	// 2、在申请的空间上执行N次构造函数
//
//	delete[] pst2;  // delete[]的原理
//	// 1、在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理
//	// 2、调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间
//
//	return 0;
//}

//struct ListNode
//{
//	int _data;
//	ListNode* _prev;
//	ListNode* _next;
//
//	ListNode(int val)
//		:_data(val)
//		, _prev(nullptr)
//		, _next(nullptr)
//	{}
//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);  // STL中内存池——空间配置器
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode(-1);
//		_head->_prev = _head;
//		_head->_next = _head;
//	}
//
//	void PushBack(int val)
//	{
//		ListNode* newnode = new ListNode(val);  // new封装了operator new，每次插入元素都需要向系统堆申请小空间，效率低下，因此我们可以重载定义专属的operator new
//		ListNode* tail = _head->_prev;
//		tail->_next = newnode;
//		newnode->_prev = tail;
//		newnode->_next = _head;
//		_head->_prev = newnode;
//	}
//
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//
//private:
//	ListNode* _head;
//};
//
//int main()  // operator new与operator delete的类专属重载
//{
//	List l;
//	l.PushBack(1);
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//	l.PushBack(5);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()  // 定位new表达式——在已分配的原始内存空间中调用构造函数初始化一个对象
//{
//	A* p1 = (A*)malloc(sizeof(A));  // malloc和operator new仅开辟了空间，未调用构造函数，还不能算作一个对象
//	A* p2 = (A*)operator new(sizeof(A));
//
//	//p1->A();  // err，构造函数只能自动调用，不支持显式调用
//	//p2->A();  // err，构造函数只能自动调用，不支持显式调用
//
//	new(p1)A();  // 定位new表达式，对已分配的空间调用构造函数，成功创建对象
//	new(p2)A(3);
//
//	p1->~A();  // 析构函数可以显式调用
//	p2->~A();  // 析构函数可以显式调用
//
//	free(p1);
//	operator delete(p2);
//
//	p1 = NULL;
//	p2 = nullptr;
//
//	return 0;
//}

//int main()  // 内存泄漏——动态申请的内存不再使用，且没有将该空间主动释放归还给系统，就存在内存泄漏
//{
//	// 内存泄漏的危害：
//	// a、出现内存泄漏的进程正常结束，这些内存会还给系统，不会有什么伤害
//	// b、出现内存泄漏的进程非正常结束（比如僵尸进程），危害很大，系统会越来越慢，甚至卡死宕机
//	// c、需要长期运行的程序（比如服务器程序）出现内存泄漏，危害很大，系统会越来越慢，甚至卡死宕机
//
//	char* p = new char[1024 * 1024 * 1024];  // 1G
//	printf("%p\n", p);
//
//	return 0;
//}

//void Swap(int& x1, int& x2)
//{
//	int x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//void Swap(double& x1, double& x2)
//{
//	double x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//void Swap(char& x1, char& x2)
//{
//	char x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()  // C++可通过函数重载支持通用的函数调用，而C语言只能通过不同的函数名单独实现
//{
//	// 缺点：
//	// 1、重载的函数仅仅只是类型不同，代码的复用率比较低，只要有新类型出现时，就需要增加对应的函数
//	// 2、代码的可维护性比较低，一个出错可能所有的重载均出错
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.22;
//	char e = 'A', f = 'B';
//
//	Swap(a, b);
//	Swap(c, d);
//	Swap(e, f);
//
//	return 0;
//}

//// 也可以写成template<typename T>
//template<class T>  // 模板参数列表——定义参数类型
//void Swap(T& x1, T& x2)  // 函数参数列表——定义参数对象
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()  // 函数模板
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.22;
//	char e = 'A', f = 'B';
//
//	Swap(a, b);
//	Swap(c, d);
//	Swap(e, f);
//
//	return 0;
//}

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()  // 模板函数的实例化
{
	// 隐式实例化：让编译器根据实参推演模板参数的实际类型
	// 显式实例化：在函数名后的<>中指定模板参数的实际类型

	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.2;

	cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;

	cout << Add(a1, d1) << endl;  // err，T无法既是int又是double

	cout << Add((double)a1, d1) << endl;  // 解决方式1：对实参强制类型转换

	cout << Add<int>(a1, d1) << endl;  // 解决方式2：显式实例化指定模板参数的实际类型
	cout << Add<double>(a1, d1) << endl;

	return 0;
}