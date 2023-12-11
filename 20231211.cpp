#define _CRT_SECURE_NO_WARNINGS
//调用C#系统自带头文件使用<>，调用个人头文件使用""
#include <stdio.h>
#include <string.h>

//变量的作用域即其可发挥作用的位置，可分为全局变量与局部变量
//{}外部定义为即为全局变量，其作用域为该项目内所有位置,生命周期为整个main函数
int wp = 231;
//在定义全局变量位置以外的源文件使用该变量前需首先声明
extern int wp;

int main()//C#主函数，每个项目内可以有多个.c文件，但仅能有一个头文件
{
	//C#支持的数据类型
	//创建变量(此处{}内的为局部变量,作用域为{}内的代码块)
	char ch = 'a';//字符:8 byte
	int num = 1;//整型:4 byte
	short snum = 1;//短整型:2 byte
	long lnum = 1000;//长整型:4 byte（sizeof(long)>sizeof(int)）
	long long llnum = 1000;//长长整型
	float fd = 0.1;//单精度浮点数
	double df = 0.01;//双精度浮点数

	//printf("")为打印，\n为换行
	printf("%d\n", num);//%d打印整型变量，%f打印float，%lf打印double
	//sizeof()：计算类型或变量所占空间的大小(byte)
	printf("int所占空间的大小为%d\n", sizeof(int));

	printf("输入任意数字继续\n");
	int r = 0;
	scanf("%d", &r);

	float a = 0;
	float b = 0;
	float sum = 0;
	printf("输入所需要的加法算式\n");
	scanf("%f+%f", &a, &b);
	//scanf为输入函数，在编译后需手动输入该格式以赋值对应的q与w
	sum = a + b ;
	printf("%f+%f=%f\n", a, b, sum);

	/*常量*/
	//字面常量
	//const可以修饰变量使其不能改变，而称为常变量，具有常属性
	const int c = 0 ;
	//define定义的标识符常量：
#define A 100000
	int d = A ;
	printf("%d\n", d) ;
	//枚举常量：枚举一个变量的所有可能取值，需填入标识符，可在main前
	enum T {一 = 2, one, un};//枚举默认为1开始，可赋初值
	enum T f = un;//若不赋初值，输出3，赋初值为2，输出4
	printf("%d\n", f );

	/*字符串：用双引号引起来的一串字符*/
	//数组：一组相同类型的元素（字符数组）
	char arr1[] = "apo";//arr为数组，[]不填数量即自动根据后面内容确定
	char arr2[] = { 'a', 'p', 'o', '\0'};
	char arr3[] = { 'a', 'p', 'o'};
	//字符串在结尾有隐藏的转义字符\0作为结束标志，故输出结果相同，arr3在apo后会有乱码
	//%c为打印字符，%s为打印字符串
	printf("%c\n", 'n');
	printf("%s\n", "nn");
	printf("arr1为%s\narr2为%s\narr3为%s\n", arr1, arr2, arr3);
	//求字符串长度使用strlen()，\0仅作为结束标志而不计入字符串长度
	int loa = strlen(arr1);
	printf("%d\n", loa);
	
	/*转义字符：printf时用作别的功能的字符*/
	//还原为单引号及双引号，防止组合：\' and \"
	//还原为斜杠，防止被识别为其他转义字符：\\
	//警告字符：\a
	printf("\a");
	//退格符：\b   进纸符：\f
	//换行：\n    回车：\r
	//水平制表符：\t    垂直制表符：\v
	//对于1~3位的8进制数字(如130)，可用\130将其转换为十位数
	printf("%s\n", "\130");//130转换为十位数为88，为X的ASCII码值
	//对于1~2位的16进制数字(如2f)，可用\x2f转换为十位数
	printf("%s\n", "\x2f");//2f转换为十位数为47，为/的ASCII码值

	//选择语句
	int input = 0;
	printf("Does the cell have nucleus?(Y/N)\n");
	scanf("%c", &input);
	if (input == 'Y')
		printf("%s\n", "Eukaryote");
	else
		printf("%s\n", "Prokarypte");

	//循环语句
	int v1 = 0;
	while (v1 <= 99)
	{
		printf("%d\%\n", v1);
		v1++;
	}
	if (v1 == 100)
		printf("%d\%\ndone!\n", v1);

	return 0 ;
}
//编译+运行代码：ctrl+F5