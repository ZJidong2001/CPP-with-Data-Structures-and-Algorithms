#include <iostream>
#include <assert.h>
using namespace std;

// 对比C++和C定义类别的区别和联系（以Stack为例）

//typedef int StackDataType;  // C面向过程，数据和方法分离
//typedef struct Stack
//{
//	StackDataType* data;
//	int top;
//	int capacity;
//}Stack;
//
//void StackInit(Stack* ps);
//void StackPush(Stack* ps, StackDataType x);
//void StackPop(Stack* ps);
//StackDataType StackTop(Stack* ps);
//int StackSize(Stack* ps);
//int StackEmpty(Stack* ps);
//void StackDestroy(Stack* ps);
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->data = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackPush(Stack* ps, StackDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		StackDataType* tmp = (StackDataType*)realloc(ps->data, sizeof(StackDataType) * newcapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->data = tmp;
//		ps->capacity = newcapacity;
//	}
//	ps->data[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	ps->top--;
//}
//
//StackDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(!StackEmpty(ps));
//	return ps->data[ps->top - 1];
//}
//
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//int StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->top = ps->capacity = 0;
//}
//
//int main()  // C定义类别
//{
//	Stack st;
//
//	StackInit(&st);  // C常忘记初始化和数据销毁（编译不会报错）
//
//	StackPush(&st, 1);  // 调用传地址，很麻烦
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//
//	printf("%d\n", st.data[st.top]);  // 随意操作类别里的数据，不通过已实现的函数进行访问，容易出错，取错栈顶元素
//
//	StackDestroy(&st);
//
//	return 0;
//}

//class Stack  // C++面向对象，数据和方法封装
//{
//public:
//	Stack()
//		: _data(nullptr)
//		, _top(0)
//		, _capacity(0)
//	{}
//
//	void Push(int x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//			int* tmp = (int*)realloc(_data, sizeof(int) * newcapacity);
//			if (tmp == NULL)
//			{
//				cout << "realloc fail" << endl;
//				exit(-1);
//			}
//			_data = tmp;
//			_capacity = newcapacity;
//		}
//		_data[_top] = x;
//		_top++;
//	}
//
//	void Pop(int x)
//	{
//		assert(_top > 0);
//		_top--;
//	}
//
//	int Top()
//	{
//		assert(_top > 0);
//		return _data[_top - 1];
//	}
//
//	int Size()
//	{
//		return _top;
//	}
//
//	bool Empty()
//	{
//		return _top == 0;
//	}
//
//	~Stack()
//	{
//		free(_data);
//		_data = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _data;
//	int _top;
//	int _capacity;
//};
//
//int main()  // C++定义类别
//{
//	Stack st;  // C++对象自动初始化和数据销毁
//
//	st.Push(1);  // 隐藏this指针，调用方便
//	st.Push(2);
//	st.Push(3);
//
//	cout << st.Top() << endl;  // 数据封装进行保护，不允许操作数据，只能通过已实现的函数进行访问
//
//	return 0;
//}

//int main()  // C语言动态内存管理方式（malloc/calloc/realloc和free）
//{
//	int* p1 = (int*)malloc(sizeof(int));  // malloc——动态地分配一块指定大小的内存空间，并返回指向该内存空间的指针（该函数不会初始化内存空间的值）
//	int* p2 = (int*)calloc(4, sizeof(int));  // calloc——动态地分配一块指定数量和大小的内存空间，并返回指向该内存空间的指针（该函数会把分配到的内存空间的值初始化为空值<0或者NULL>）
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);  // realloc——动态地调整之前分配的内存块的大小
//	free(p1);
//	free(p3);
//	p1 = p2 = p3 = NULL;
//
//	return 0;
//}

//int main()  // C++动态内存管理方式（new和delete）
//{
//	int* p1 = new int;  // int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int[5];  // int* p2 = (int*)malloc(sizeof(int) * 5);
//	delete p1;  // free(p1);
//	delete[] p2;  //  free(p2);
//	p1 = p2 = nullptr;  // p1 = p2 = NULL;
//
//	return 0;
//}

//int main()  // new int(x)与new int[x]的区别
//{
//	int* p1 = new int(5);  // 向堆上动态申请1个int空间（4Byte），并将这块空间的值初始化为5
//	int* p2 = new int[5];  // 向堆上动态申请5个int空间（20Byte），这块空间的值为随机值
//	delete p1;
//	delete[] p2;
//	p1 = p2 = nullptr;
//
//	return 0;
//}

//int main()  // C++98不支持在new表达式中初始化数组元素，C++11支持使用{}在new表达式中初始化数组元素
//{
//	int* p1 = new int[5];  // C++98
//	int* p2 = new int[5] {1, 2};  // C++11
//	delete[] p1;
//	delete[] p2;
//	p1 = p2 = nullptr;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
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
//int main()  // C++动态内存管理方式（new和delete）
//{
//	// malloc/free和new/delete对于内置类型没有本质区别（仅用法不同），对于自定义类型区别很大
//
//	A* p1 = (A*)malloc(sizeof(A));  // malloc动态申请自定义类型的空间，只开辟空间不做初始化处理
//	A* p2 = (A*)malloc(sizeof(A) * 5);
//
//	free(p1);  // free将开辟的自定义类型的空间归还给系统，只释放空间不做资源清理工作
//	free(p2);
//	p1 = p2 = NULL;
//
//	A* p3 = new A;  // new动态申请自定义类型的空间，先开辟空间再调用默认构造函数初始化对象
//	A* p4 = new A[5];
//
//	delete p3;  // delete将开辟的自定义类型的空间归还给系统，先调用析构函数清理资源，再释放空间
//	delete[] p4;
//	p3 = p4 = nullptr;
//
//	return 0;
//}

//int main()  // 面向过程的语言，处理错误的方式是返回值+错误码解决
//{
//	char* p1 = (char*)malloc(0x7fffffff);  // malloc开辟空间失败返回空指针
//
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
//	return 0;
//}

int main()  // 面向对象的语言，处理错误的方式一般是抛异常，C++中也要求出错抛异常
{
	char* p1 = nullptr;

	try
	{
		p1 = new char[0x7fffffff];  // new开辟空间失败直接抛异常（若不通过try-catch捕获，则崩溃终止程序）
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		printf("%p\n", p1);
	}

	return 0;
}