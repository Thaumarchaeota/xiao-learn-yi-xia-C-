#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//定义函数
int Add(int x1, int x2)
{
	int fx1;
	fx1 = x1 + x2;
	return fx1;
}

int main()
{
	int a = 1;
	int b = 2;
	//scanf("%d %d", &a, &b);
	int sum = Add(a, b);
	printf("%d\n", sum);

	//数组以下标访问，第一个默认为0
	int ng[5] = { 1,2,3,1,2 };
	char cg[7] = { 'a','p','o' };

	printf("%d\n%d\n%d\n%d\n%d\n", ng[0], ng[1], ng[2], ng[3], ng[4]);
	printf("%c\n%c\n%c\n%c\n%c\n", cg[0], cg[1], cg[2]);
	printf("----------------------------------\n");


	/*操作符*/
	//操作符可根据对象分为单目操作符及双目操作符等
	
	//算数操作符： + - * / 
	float di1 = 7 / 3;//当/两端为整数时执行整数除法，仅能得到整数
	printf("%f\n", di1);
	float di2 = 7 / 3.0;//当/两端有任意小数时则不执行整数除法
	printf("%f\n", di2);
	float di3 = 7 % 3;//%为取模，即余数
	printf("%f\n", di3);
	
	//移位操作符： <<   >>  指的是移动n个二进制位
	int mvl = 2 << 3;
	//2的二进制为10，前进三位即为10000，转换为十进制为16
	printf("%d\n", mvl);
	
	//位操作符
	//按位与：&
	//按位或：|
	//按位异或：^

	//赋值操作符
	//复合操作符：+=、-=、/=、*=、|=、<<=等
	int fh = 0;
	fh += 1;//即fh = fh + 1

	//单目操作符
	//C语言中0为假、非0为真，可用逻辑取反操作符：!
	if (!a)
	{
		//取假可用
	}
	//sizeof可计算字符/数的大小或数组的总大小
	//计算一个数组的元素个数
	int calarr[10] = { 0 };
	int en = sizeof(calarr) / sizeof(calarr[0]);
	printf("数组元素个数=%d\n", en);
	//对一个数按二进制位取反：~
	int qf = 0;
	int qfr = ~qf;//将二进制的0(32个0）全部取反(0/1互换)
	printf("%d\n", qfr);//32个1为-1的补码，因此输出-1
	printf("%u\n", qfr);//当使用无符号的%u输出时，输出其对应的正数
	//前置/后置++与--
	int dm1 = 2;
	int dm2 = ++dm1;//前置++为先将原数在其自身基础上+1，后使用
	printf("dm1:%d dm2:%d\n", dm1, dm2);//输出3与3
	int dm3 = 2;
	int dm4 = dm3++;//后置++为先使用，再+1
	printf("dm1:%d dm2:%d\n", dm3, dm4);//输出3与2
	//强制类型转换；(类型)
	int tc = (int)1.1;//将浮点数强制转换为括号内的int型
	printf("%d\n", tc);//强制转换为int后使用%d不会报错或提示，输出1

	//关系操作符
	//等于与不等于为：==与!=
	//大/小于等于为：>=与<=

	//逻辑操作符：加入后逻辑(布尔)运算
	//逻辑与：&&    逻辑或：||
	int l1 = 0;
	int l2 = 1;
	int pd1 = l1 && l2;
	printf("%d\n", pd1);//此时l1与l2不全为真，因此为假，输出0
	int pd2 = l1 || l2;
	printf("%d\n", pd2);//此时l1与l2有一为真，因此为真，输出1

	//条件操作符（三目操作符）
	int sm1 = 2;
	int sm2 = 4;
	//类似if语句，A?B:C，若A成立输出B，否则输出C
	int maxsm = sm1 > sm2 ? sm1 : sm2;
	printf("%d", maxsm);

	//逗号表达式
	int db1 = 1;
	int db2 = 3;
	int db3 = 4;
	int dr = (db1 = db1 + db3, db2 = db1 + db3, db3 = db2 + db2);
	//逗号表达式依次计算每一项，并输出末项18
	printf("逗号表达式结果为%d\n", dr);

	//下标引用操作符：[]
	//函数调用操作符()

	/*关键字*/
	//修饰局部变量 自动 auto 可省略
	//auto int ate = 10;//自动创建变量与销毁
	//寄存器关键字register
	register int fy = 1;//建议将被修饰的变量放入寄存器
	//signed/unsigned：有无符号
	//静态的：static
	//结构体：struct
	//共用体(联合体)：union
	//类型重定义 typedef
	typedef unsigned int u_int;//将unsigned int定义为u_int
	u_int uint = 1;//直接使用u_int即代表

	
	//预处理指令：define、include等，不属于关键字



	return 0;
	
}
