#include <stdio.h>

//int main()  // C++兼容C，C语言的语法特性在C++中依旧可以使用
//{
//	printf("Hello world!\n");
//	return 0;
//}

//#include <stdlib.h>  // 不包含该头文件下面代码正常运行，包含该头文件会产生rand命名冲突问题（不知rand是变量还是函数）
//
//int rand = 0;
//
//int main()  // C语言无法解决的问题之一：命名冲突问题
//{
//	// 1. 自定义的变量、函数可能跟库里面的变量、函数产生命名冲突
//	// 2. 公司项目组多人协作写代码，做的项目通常比较大，可能造成命名冲突
//	// C语言没有办法很好地解决这个问题，C++提出一个新语法——命名空间
//	printf("%d\n", rand);
//	return 0;
//}

//#include <stdlib.h>
//
//namespace bit  // 定义了一个叫bit的命名空间——域
//{
//	int rand = 0;
//}
//
//int main()  // 命名空间具有隔离作用
//{
//	// rand先到局部范围内找，若没有再到全局范围内找。若还没有则程序会报错，不会到定义的域里面去找
//	printf("%d\n", rand);  // rand访问的是全局变量，rand()函数
//
//	// bit::rand指定到定义的bit域里面去找
//	printf("%d\n", bit::rand);  // ::域作用限定符
//
//	return 0;
//}

//int a = 10;
//
//int main()  // ::域作用限定符
//{
//	int a = 20;
//
//	printf("%d\n", a);  // 局部变量优先
//	printf("%d\n", ::a);  // ::左边为空白，访问全局变量a
//
//	return 0;
//}

//namespace bit  // 命名空间中可以定义变量、函数、类型
//{
//	int rand = 10;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//int main()
//{
//	bit::rand = 20;
//
//	struct bit::Node node;
//
//	bit::Add(1, 2);
//
//	return 0;
//}

//namespace N1  // 命名空间可以嵌套
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//int main()
//{
//	N1::Add(1, 2);
//	N1::N2::Sub(3, 4);
//
//	return 0;
//}

//#include "Test.h"
//
//namespace bit  // 同一个工程中允许存在多个相同名称的命名空间，编译器最后会合成同一个命名空间中
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)  // 实现
//	{
//		return left + right;
//	}
//}
//
//int main()
//{
//	bit::a = 30;
//	bit::Add(4, 6);
//
//	return 0;
//}

//namespace N  // 命名空间使用方式1：加命名空间名称及作用域限定符（该方式能够做到最好的命名隔离，但是使用不方便，每次都需要指定域）
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", N::b);
//	N::Add(10, 20);
//	N::Sub(30, 10);
//
//	return 0;
//}

//namespace N  // 命名空间使用方式2：使用using namespace 命名空间名称引入（该方式用起来虽然极其方便，但是隔离彻底失效了，慎用）
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//
//using namespace N;
//
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	Add(10, 20);
//	Sub(30, 10);
//
//	return 0;
//}

//namespace N  // 命名空间使用方式3：使用using将命名空间中成员引入（该方式可以用于展开常用的成员，也有较好的隔离效果）
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//
//using N::b;
//
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	N::Add(10, 20);
//	N::Sub(30, 10);
//
//	return 0;
//}

//#include <iostream>  // C++库里的头文件，类似C语言的stdio.h
//using namespace std;  // C++库的实现定义在一个叫std的命名空间中，std全部展开
//
//int main()
//{
//	cout << "Hello world!" << endl;
//
//	return 0;
//}

//#include <iostream>
//// 不展开std命名空间
//
//int main()
//{
//	std::cout << "Hello world!" << std::endl;
//	return 0;
//}

//#include <iostream>
//using std::cout;
//using std::endl;  // 展开std中常用的
//
//int main()
//{
//	cout << "Hello world!" << endl;
//	return 0;
//}

#include <iostream>
using namespace std;

int main()  // <<流插入运算符、>>流提取运算符、endl换行符
{
	cout << "hello world" << endl;
	cout << "hello world\n";
	printf("hello world\n");

	int i = 10;
	double d = 1.11;

	cout << i << " " << d << endl;  // 自动识别类型
	cin >> i >> d;
	cout << i << " " << d << endl;

	return 0;
}