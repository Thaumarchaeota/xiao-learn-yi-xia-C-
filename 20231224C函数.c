/*库函数*/
//www.cplusplus.com
//常见的库函数包括
//IO函数
//字符串操作函数
//字符操作函数
//日期/时间函数
//数学函数
//其他库函数

#include<stdio.h>
#include<string.h>

int main()
{
	char dest[20] = { 0 };
	char sour[] = { "chloroplast" };
	strcpy(dest, sour);
	printf("%s\n%s\n", dest, sour)
	return 0;
}

/*自定义函数*/
//具有函数名、返回值类型和函数参数

int get_maxoftwo(int x, int y)//返回类型、函数名、函数参数
{
	//函数体
	int z = 0;
	if (x > y)
		z = x;
	else
		z = y;
	return z;//返回值
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = get_maxoftwo(a, b);//调用函数
	//监视调用函数内部需要F11
	printf("max=%d", c)
	return 0;
}

void exc(int* x, int* y)
{
	int z = *x;
	*x = *y;
	*y = z;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d %d\n", a, b);
	exc(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}