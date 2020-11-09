#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//形式参数湿疹函数名后括号中的变量，因为形式参数只有函数在函数被调用的过程中才实例化（分配内存单元），所以才叫形式参数。
//形式参数当函数调用完成之后就会自动销毁，因此形式参数只在函数中有效

//传值调用：函数的形参和实参分别占用不同的内存块，对形参的修改不会影响实参
//传址调用：这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量

//递归
//程序员调用自身的编程技巧称为递归。递归作为一种算法在程序设计语言中广泛应用。
//一个过程或函数在其定义或说明中有直接或者间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解，
//递归策略只需少量的程序就可以描述出解题过程所需要的多次重复计算，大大的减少了程序的代码量。递归的主要思考方式在于：大事化小

//递归的两个必要条件
//1.存在限制条件，当满足这个限制条件的时候，递归便不再继续
//2.每次递归调用之后越来越接近这个限制条件


//栈区--局部变量，函数的形参   堆区---malloc，calloc   静态区--全局变量，static修饰的变量


//最简单的一个递归
//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;
//}
//会不间断的打印hehe，但是当打印一段的时间之后，程序会崩溃，爆出一个错误  stack overflow 栈溢出

//练习1
//接收一个整形值（无符号），按照顺序打印它的每一位，例如：输入1234，输出1 2 3 4
//接收了一个1234，然后你先%10得到个位数4，然后在/10去掉个位数4，得到123，然后不断重复这个过程，在把这几个数字4 3 2 1 存起来，倒着打印出来


//Print(123)  4
//Print(12) 3  4
//Print(1) 2 3 4      一位数字就没有必要继续拆下去了
//void Print(int n)
//{  
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int mian()
//{
//	unsigned int num = 0;
//	scanf("%d", num);
//	Print(num);
//	return 0;
//}


//编写函数不允许创建临时变量，求字符串的长度 (自己写一个strlen的函数来求解字符串的长度)
//正常的求字符串长度方法
//int main()
//{
//	char arr[] = "bit";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

////你会发现这个还是无法满足题目所说的要求，因为你写的函数内部创建了一个count的变量
//int my_strlen(char* str)
//{
//	int count = 0;
//	while(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d\n", len);
//	return 0;
//}


//大事化小
//my_strlen("bit")
//1 + my_strlen("it")
//1 + 1 + my_strlen("t")
//1 + 1 + 1 + my_strlen("")
//1 + 1 + 1 + 0
//3

//*str != '\0' 是限制条件，当不满足时就会不再进行递归，结果在不断地接近目标
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}


//递归与迭代
//求n的阶乘
//正常的方法
//int Fac1(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)  //n! 不好想我们可以倒着思考问题 1*2*3 ....*n
//	{
//		ret *= i;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac1(n); //循环的方式
//	printf("%d\n", ret);
//}

//递归的方法来实现
//int Fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n*Fac2(n - 1);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac2(n); 
//	printf("%d\n", ret);
//}



//练习4
//求斐波那契数列
//1 1 2 3 5 8 13 21 34 55  前两个数之和是下一个数
//求第n个斐波那契数

//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//                   50
//              49         48
//           48  47      47 46
//        47 46 46 45  46 45 45 44  
//你会发现在做很多重复的工作

int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret = %d\n", ret);
	return 0;
}