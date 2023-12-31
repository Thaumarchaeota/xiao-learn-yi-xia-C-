/*操作符*/
//操作符可根据对象分为单目操作符及双目操作符等


/*赋值操作符*/
//复合操作符：+=、-=、/=、*=、|=、<<=等
int main()
{
	int fh = 0;
	fh += 1; //即fh = fh + 1
	
	int a = 0; int b = 0; int c = 0; int d = 0; int e = 0;
	a ^= b *= c &= d = e//连续赋值，从右向左 

	return 0;
}


/*算术操作符*/
int main()
{
	float di1 = 7 / 3;//当/两端为整数时执行整数除法，仅能得到整数
	printf("%f\n", di1);
	float di2 = 7 / 3.0;//当/两端有任意小数时则不执行整数除法
	printf("%f\n", di2);
	float di3 = 7 % 3;//%为取模，两端操作数必须为整数
	printf("%f\n", di3);
	
	return 0;
}

/*移位操作符*/
// <<   >>  移动n个二进制位

//左移操作符 <<
int main()
{
	int mvl = 2 << 3;//2的二进制为10，前进三位即为10000，转换为十进制为16

	int x = 31;
	x <<= 1;//x *= 2;

	return 0;
}
//右移操作符分为算数右移(左侧按符号位补)与逻辑右移(左侧补0)
int main()
{
	int mvr = -1 << 1;
	//-1的补码为 11111111111111111111111111111111
	//右移后为   11111111111111111111111111111111
	//一般采用算术右移，即结果还为 -1

	x >>= 1;//x /= 2;

	return 0;
}

/*位操作符*/

int main()
{
	//按位与：& （按二进制位，若a与b为1则输出1）
	int a = 12;   //00000000000000000000000000001100
	int b = 21;   //00000000000000000000000000010101
	int c = a & b;//00000000000000000000000000000100 -> 4
	//按位或：| （按二进制位，若a或b为1则输出1）
	int d = 12;   //00000000000000000000000000001100
	int e = 21;   //00000000000000000000000000010101
	int f = a ^ b;//00000000000000000000000000011101 -> 29	
	//按位异或：^
	int d = 12;   //00000000000000000000000000001100
	int e = 21;   //00000000000000000000000000010101
	int f = a ^ b;//00000000000000000000000000000100 -> 4	

	//对于按位异或有如下性质：
	// a ^ 0 = a     a ^ a = 0
	// (a ^ b) ^ a = b    (a ^ b) ^ b = a

	//swap(a, b)
	a ^= b;//将 a ^ b 的值存储至a中
	b ^= a;//即(a ^ b) ^ b = 原a值，存储至b中，完成a的转移
	a ^= b;//即(a ^ b) ^ a = 原b值，存储至a中，完成b的转移
	a ^= b ^= a ^= b;//连续赋值写法
}

//求一整数存储在内存的二进制中1的个数
int sr(int a)
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 32; i++)
	{
		if ((a & 1) == 1)
		{
			count++;
		}
		a = a >> 1;
	}
	return count;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", sr(a));
	return 0;
}


/*单目操作符*/
//C语言中0为假、非0为真，可用逻辑取反操作符：!
//如需要取假时可用
int main()
{
	if (!a) { ; }
	return 0；
}

//sizeof可计算字符/数的大小或数组的总大小
//计算一个数组的元素个数
int main()
{
	int calarr[10] = { 0 };
	int en1 =  sizeof calarr;//sizeof作为操作符可不使用括号
	int en2 = sizeof calarr / sizeof calarr[0];//用于计算数组大小

	int a = 2; int b = 3; int c = 1;
	int d = sizeof(a = b + c);//sizeof内不会运算，故此句后打印a依然为2
	
	return 0;
}

//前置/后置++与--
int main()
{
	int dm1 = 2;
	int dm2 = ++dm1;//前置++为先将原数在其自身基础上+1，后使用
	printf("dm1:%d dm2:%d\n", dm1, dm2);//3 3
	int dm3 = 2;
	int dm4 = dm3++;//后置++为先使用，再+1
	printf("dm1:%d dm2:%d\n", dm3, dm4);//3 2

	return 0;
}

//取地址：&	解引用： *

//强制类型转换；(类型)
int tc = (int)1.1;//将浮点数强制转换为括号内的int型
printf("%d\n", tc);//强制转换为int后使用%d不会报错或提示，输出1


// ~ 对一个数按二进制位取反
int main()
{
	int a = -1; //100000000000000000000001 - 原码
				//111111111111111111111110 - 反码
				//111111111111111111111111 - 补码
	int b = ~a; //000000000000000000000000 - 按位取反


	printf("%u\n", qfr);//当使用无符号的%u输出时，输出其对应的正数
}

//对于数特定二进制位的查找与改动
int main()
{
	int input_num = 0;
	int input_pos = 0;
	char input_choose = 0;
	int input_choose2 = 0;

	//查找二进制num的第pos位
	do
	{
		scanf("%d %d", &input_num, &input_pos);
		if (1 == (input_num >> (input_pos - 1) & 1))//判断该位是否为1
		{
			printf("二进制%d的%d位为1\n是否将此位转换为0?(Y/N)\n", input_num, input_pos);

			scanf("%s", &input_choose);
			if ('Y' == input_choose)
			{
				input_num = ~((~input_num) | (1 << (input_pos - 1)));
				printf("转换后的结果为%d\n", input_num);
			}
		}
		else
		{
			printf("二进制%d的%d位为0\n是否将此位转换为1?(Y/N)\n", input_num, input_pos);
			scanf("%s", &input_choose);
			if ('Y' == input_choose)
			{
				input_num = input_num | (1 << (input_pos - 1));
				printf("转换后的结果为%d\n", input_num);
			}
		}
		printf("press 0 to exit, press 1 to continue:)");
		scanf("%d", &input_choose2);
	} while (input_choose2);

	return 0;
}


//关系操作符
//	等于		==		不等于	!=
//	大于等于	>=		小于等于	<=

//逻辑操作符：加入后逻辑(布尔)运算
//逻辑与：&&    逻辑或：||
int main()
{
	int l1 = 0;
	int l2 = 6;
	int pd1 = l1 && l2;
	printf("%d\n", pd1);//此时l1与l2不全为真(非0)，因此为假，输出0
	int pd2 = l1 || l2;
	printf("%d\n", pd2);//此时l1与l2有一为真，因此为真，输出1

	//对于&&(||)来说从左向右运算，若计算到表达式为0(1)，则不继续向右计算
	int a = 0; int b = 2; int c = 3;
	int i = a++ && ++b && c++;
	//此时a先使用后第一个表达式为0，故不继续进行后续计算
	//故		a = 1	b = 2	C = 3

	return 0;
}

//条件操作符（三目操作符）
int main()
{
	int sm1 = 2;
	int sm2 = 4;
	//类似if语句，A?B:C，若A成立输出B，否则输出C
	int maxsm = sm1 > sm2 ? sm1 : sm2;
	printf("%d", maxsm);
	return 0;
}

//逗号表达式
int main()
{
	int db1 = 1;
	int db2 = 3;
	int db3 = 4;
	int dr = (db1 = db1 + db3, db2 = db1 + db3, db3 = db2 + db2);
	//逗号表达式依次计算每一项，并输出末项18
	printf("逗号表达式结果为%d\n", dr);
	
	//如可改写循环语句
	while (db3 = db2, db1 = db3, db2 > 0)//仅对末尾db2 > 0判断
	{
		;
	}

	return 0;
}


//下标引用操作符：[] 

//函数调用操作符()

//结构成员访问操作符
struct book
{
	char name[20];
	char author[20];
	int price;
};

int main()
{
	struct book A = { "biochemistry", "lehninger", 200 };
	printf("%s\n", A.name);//结构体.成员名
	struct book* pb = &A;
	printf("%s\n", (*pb).name);
	printf("%s\n", pb->name);//结构体指针 -> 成员名
	return 0;
}


/*类型转换*/
//整型提升：字符与短整型操作数在使用前都会被转换为普通整型
int main()
{
	char a = 3;			//                        00000011 - char类型3的二进制
						//00000000000000000000000000000011 - 整型提升为int
	char b = 127;		//                        01111111 - char类型127的二进制
						//00000000000000000000000001111111 - 整型提升为int
	char c = a + b;		//00000000000000000000000010000010 - int类型相加
						//                        10000010 - c的补码
						//                        10000001 - c的反码
						//                        11111110 - c的原码
						//	故		c = -126
	printf("%d\n", c);	//                        10000010 - c储存的补码
						//11111111111111111111111110000010 - 打印int时需整型提升
						//11111111111111111111111110000001 - int类型c反码
						//10000000000000000000000001111110 - int类型c原码
						//  打印		c = -126
	
	printf("%u\n", sizeof(+a));	//此时因运算故a会进行整型提升，故打印4

	return 0;
}

/*算术转换*/
//寻常算术转换，向精度更高的类型转换
//long double <- double <- float <- unsigned long int <- long int <- unsigned int <- int


//操作符属性: 操作符优先性 -> 操作符结合性 -> 是否影响
//优先性：()	[]	.	->	++/--(后缀)	!	~	+/-(单目)	++/--(前缀)	*	&	sizeof	(类型)
// *	/	%	+	-	<</>>	>/>=/</<=/==/!=		&/^/|	&&/||	?:	=(各类赋值)	,	 

/*关键字*/
int main()
{
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
	return 0;
}
	
	//预处理指令：define、include等，不属于关键字
