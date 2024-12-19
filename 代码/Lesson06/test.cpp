#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		year = year;  // 虽然编译通过，但只是将形参赋值给形参，并未修改类里的属性值
//		month = month;
//		day = day;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()  // 属性名与方法形参名相同，会造成冲突
//{
//	Date d;
//	d.Init(2022, 1, 15);
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // 属性名前面或后面加_是为了和方法形参名进行区分，避免冲突
//{
//	Date d;
//	d.Init(2022, 1, 15);
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		Date::year = year;
//		Date::month = month;
//		Date::day = day;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()  // 属性名与方法形参名相同，通过指定类域依旧可以区分，但实际中尽量不要这样做，自己坑自己
//{
//	Date d;
//	d.Init(2022, 1, 15);
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->year = year;
//		this->month = month;
//		this->day = day;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()  // 属性名与方法形参名相同，通过this指针依旧可以区分，但实际中尽量不要这样做，自己坑自己
//{
//	Date d;
//	d.Init(2022, 1, 15);
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)  // void Init(Date* const this, int year, int month, int day)
//	{
//		//this = nullptr;  // err，this指针不能更换指向对象
//		_year = year;
//		_month = month;
//		_day = day;
//		//this->_year = year;
//		//this->_month = month;
//		//this->_day = day;
//	}
//
//	void Print()  // void Print(Date* const this)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		//cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // 编译器增加隐藏this指针
//{
//	// 每个对象都为其成员变量开辟独立的空间，调用的成员函数是相同的（反汇编调试可以查看调用成员函数地址相同）
//	// 不同对象调用相同方法，如何确定该方法使用哪一个对象呢？——方法内隐藏this指针
//	Date d1;
//	d1.Init(2022, 1, 15);  // Init(&d1, 2022, 1, 15);
//	d1.Print();  // Print(&d1);
//
//	Date d2;
//	d2.Init(2022, 1, 16);  // Init(&d2, 2022, 1, 16);
//	d2.Print();  // Print(&d2);
//
//	// 注意：
//	// 1、调用成员函数时，不能显式传实参给this
//	// 2、定义成员函数时，不能显式声明形参this
//	// 3、在成员函数内部，可以显式使用this
//	return 0;
//}

//class A
//{
//public:
//	void Show()  // 将空指针p传给隐藏this指针，没有解引用this，可以正常运行
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()  // 正常运行
//{
//	A* p = nullptr;
//	p->Show();  // p虽然是空指针，但是p调用成员函数不会出现空指针访问，因为成员函数没有存在对象所创建的空间里
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()  // 将空指针p传给隐藏this指针，对this指针解引用操作，运行崩溃
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()  // 运行崩溃
//{
//	A* p = nullptr;
//	p->PrintA();  // p虽然是空指针，但是p调用成员函数不会出现空指针访问，因为成员函数没有存在对象所创建的空间里
//
//	return 0;
//}

//int main()  // C语言存在忘记初始化、销毁等问题，因此C++给类对象自动调用构造函数和析构函数
//{
//	Stack st;
//
//	// 忘记调用初始化函数
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	// 忘记调用销毁函数
//
//	return 0;
//}

//class Date
//{
//public:
//	//Date()  // 1、函数名与类名相同 2、无返回值
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	// 
//	//Date(int year, int month, int day)  // 4、构造函数可以重载
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	Date(int year = 1, int month = 1, int day = 1)  // 上面两种构造函数可通过缺省参数合二为一（推荐）
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // 构造函数——不是开空间创建对象，而是初始化对象
//{
//	Date d1;  // 3、对象实例化时编译器自动调用对应的构造函数
//	Date d2(2022, 1, 15);
//	Date d3(2022, 1);
//	Date d4(2022);
//
//	return 0;
//}

//class A
//{
//public:
//	// 6、不用参数就可以调用的构造函数称为默认构造函数（无参构造函数、全缺省构造函数、编译器生成的默认构造函数），并且默认构造函数只能有一个
//
//	A()  // 不用参数就可以调用，是默认构造函数
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//
//	//A(int a = 10)  // 不用参数就可以调用，是默认构造函数
//	//{
//	//	cout << "A()" << endl;
//	//	_a = 0;
//	//}
//
//	//A(int a)  // 必须传参，不是默认构造函数
//	//{
//	//	cout << "A()" << endl;
//	//	_a = 0;
//	//}
//
//private:
//	int _a;
//};
//
//class Date
//{
//	// 5、如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦用户显式定义编译器将不再生成
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//	// 7、编译器生成的默认构造函数，对于内置类型不做初始化处理，对于自定义类型调用它的默认构造函数初始化（若没有则报错）
//};
//
//int main()  // 构造函数——不是开空间创建对象，而是初始化对象
//{
//	Date d;  // 没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
//
//	return 0;
//}

//class Date
//{
//public:
//	~Date()  // 1、析构函数名是在类名前加上字符~ 2、无参数无返回值 3、一个类有且只有一个析构函数，若未显式定义，系统会自动生成默认的析构函数
//	{
//		cout << "~Date()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()  // 析构函数——不是完成对象的销毁，而是完成对象的一些资源清理工作
//{
//	Date d;  // Date类没有资源需要清理，所以实不实现析构函数都可以
//
//	return 0;  // 4、对象生命周期结束时，C++编译系统自动调用析构函数
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)  // 构造函数
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	~Stack()  // 析构函数
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()  // 析构函数——不是完成对象的销毁，而是完成对象的一些资源清理工作
//{
//	// 构造函数顺序先s1后s2，析构函数顺序先s2后s1（栈）
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)  // 构造函数
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	// 5、编译器生成的析构函数，对于内置类型不做处理，对于自定义类型调用它的析构函数
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()  // 析构函数——不是完成对象的销毁，而是完成对象的一些资源清理工作
//{
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//class MyQueue  // 两个栈实现一个队列（不具体实现，只是见一下构造函数和析构函数的实际作用）
//{
//public:
//	// 编译器自动生成的构造函数和析构函数，会对自定义类型成员变量调用它的构造函数和析构函数
//	void push(int x) {}
//
//private:
//	Stack pushST;
//	Stack popST;
//};
//
//int main()  // 析构函数——不是完成对象的销毁，而是完成对象的一些资源清理工作
//{
//	MyQueue mq;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)  // 构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 1、拷贝构造函数是构造函数的一个重载形式
//	// 2、拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用
//	Date(const Date& d)  // 拷贝构造函数（建议加上const，避免误修改）
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void f1(Date d) {};  // 传值传参需要调用拷贝构造函数
//void f2(Date& d) {};
//
//int main()  // 拷贝构造函数——创建与某个对象一模一样的新对象
//{
//	Date d1(2022, 1, 15);
//	Date d2(d1);
//
//	f1(d1);
//	f2(d1);
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)  // 构造函数
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	// 3、若未显式定义，系统自动生成拷贝构造函数（内置类型成员变量，会完成按字节序的拷贝<浅拷贝>；自定义类型成员变量，会调用它的拷贝构造函数）
//
//	~Stack()  // 析构函数
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()  // 拷贝构造函数——创建与某个对象一模一样的新对象
//{
//	Stack st1(10);
//	Stack st2(st1);  // 编译器自动生成的拷贝构造函数，会导致程序崩溃（必须显式定义拷贝构造函数，进行深拷贝）
//
//	return 0;  // 按字节序的拷贝，导致st1和st2的_a相同，最后导致指向的同一块空间被释放两次，造成程序崩溃
//	           // 甚至还有其他问题，比如st1修改开辟空间的数据，会导致st2内开辟空间的数据发生修改
//}

class A
{
public:
	A() {}  // 构造函数
	A(const A&)  // 拷贝构造函数
	{
		cout << "A(const A&)" << endl;
	}
};

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)  // 构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	~Date()  // 析构函数
	{
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	A _aa;
};

int main()  // 拷贝构造函数——创建与某个对象一模一样的新对象
{
	Date d1(2022, 1, 15);
	Date d2(d1);

	return 0;
}