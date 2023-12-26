//函数的链式访问:一个函数的返回值作为另一个函数的参数
int main()
{
	printf("%d", printf("%d", printf("%d", 43));
	//printf的返回值为其输出字符的个数，故输出为4321
	return 0;
}

/*函数的声明和定义*/
int main()
{
	int a = 2;
	int b = 4;
	int Add(int, int);
	//函数声明仅需写明其返回类型、函数名与参数类型，其具体存在与否无关
	//函数声明应放在函数的使用之前，若函数定义放在调用前无需再声明
	//函数声明一般放在头文件 .h文件中
	int c = Add(a, b)
	return 0;
}

//函数的定义：具体功能，一般放在.c文件
int Add(int x, int y)
{
	int z = x + y;
	return z;
}

/*函数递归:函数直接或间接地调用自身地方法*/
void print(unsigned int x)
{
	if (x > 9)//递归的限制条件，当满足条件时不再递归
	{
		print(x / 10);//每次递归中应改变参数使得越来越接近限制条件
	}
	printf("%d ", x % 10);
}

int main()
{
	unsigned int x = 0;
	scanf("%u", &x);
	print(x);
	return 0;
}

//strlen函数实现的传统与递归方法
int arr_len(char* x)
{
	int count = 0;
	while (*x != '\0')
	{
		count++;
		x++;
	}
	return count;
}

int arr_len2(char* x)
{
	if (*x != '\0')
		return 1 + arr_len2(x + 1);
	else
		return 0;
}

int main()
{
	char arr[] = { "abcdefghi" };
	printf("%d\n", arr_len(arr));
	printf("%d\n", arr_len2(arr));
	printf("%d\n", strlen(arr));
	return 0;
}

//实现n的阶乘
int fac1(int x)
{
	int cal = 1;
	int result = 1;
	if (0 == x)
	{
		return 1;
	}

	for (cal == 1; cal <= x; cal++)
	{
		result = result * cal;
	}
	return result;
}

int fac2(int x)
{
	if (x <= 1)
		return 1;
	else
		return x * fac2(x - 1);
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", fac1(a));
	printf("%d\n", fac2(a));
	return 0;
}

//斐波那契数列
int Fibonacci_1(int x)
{
	if (x <= 2)
		return 1;
	else
		return Fibonacci_1(x - 1) + Fibonacci_1(x - 2);
}

int Fibonacci_2(int x)
{
	int a = 0;
	int b = 1;
	int result = 1;
	int count = 0;

	for (count = 2; count <= x; count++)
	{
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", Fibonacci_1(a));
	printf("%d\n", Fibonacci_2(a));
	return 0;
}