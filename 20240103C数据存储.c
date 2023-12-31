/*数据的存储*/

int main()
{
	int a = -10;	//10000000000000000000000000001010
					//11111111111111111111111111110101
					//11111111111111111111111111110110
					//   f   f   f   f   f   f   f   6

	return 0;
}

//数据以补码形式储存
//1.原码-补码转换步骤相同
	// 
//2.+-运算可实现同一，如对于23-16，可视为23+(-16)
	
	//-16:	10000000000000000000000000001000 -原码
	//		11111111111111111111111111110111 -反码
	//		11111111111111111111111111111000 -补码
	//23:	00000000000000000000000000010111 -原码/反码/补码
	//	 (1)00000000000000000000000000001111 -补码相加结果 -> 

//对于大于8位的系统(16/32位)，其寄存器宽度大于一个字节
//当大于1byte数据存至内存时，存储方式可分为大端/小端存储
//大端字节序:将数据的低位字节序存储在高地址处，将数据的高位字节序存储在低地址处
//小端字节序:将数据的低位字节序存储在低地址处，将数据的高位字节序存储在高地址处

int main()
{
	int a = 0x11223344;//存储为44 33 22 11，采用小端字节序
	return 0;
}
//判断存储模式
int check_sys()
{
	int a = 1;
	char* p = (char*)&a;
	return p;//大端存储时返回0
}
#include <stdio.h>
int main()
{
	char a = -1;			//10000000000000000000000000000001 - -1的原码
							//11111111111111111111111111111110 - -1的反码
							//11111111111111111111111111111111 - -1的补码
							//                        11111111 - 存储至char中的-1
	printf("%d\n", a);		//11111111111111111111111111111111 - 整型提升并打印 -> -1
	unsigned char b = -1;	//                        11111111 - 存储至unsigned char中的-1
	printf("%d\n", b);		//00000000000000000000000011111111 - 整型提升并打印 -> 255

	char c = -128;			//10000000000000000000000010000000 - 原码
							//11111111111111111111111101111111 - 反码
							//11111111111111111111111110000000 - 补码
							//                        10000000 - 存储至char中
	printf("%u\n", c);		//11111111111111111111111110000000 - 以有符号char整型提升并打印无符号数 -> 4294967168

	char c = 128;			//00000000000000000000000010000000 - 原码
							//                        10000000 - 存储至char中
	printf("%u\n", c);		//11111111111111111111111110000000 - 以有符号char整型提升并打印无符号数 -> 4294967168

	return 0;
}
//对于char 未规定默认，大部分编译器为signed char
//对于int 规定默认为为signed char

int main()
{
	int i = -20;			//10000000000000000000000000010100 - 原码
							//11111111111111111111111111101011 - 反码
							//11111111111111111111111111101100 - 补码
	unsigned int j = 10;	//00000000000000000000000000001010 - 补码
	printf("%d\n", i + j);	//11111111111111111111111111110110 - 相加
							//11111111111111111111111111110101 - 反码
							//10000000000000000000000000001010 - 原码 -> -10
	return 0;
}

int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)	//10000000000000000000000000000001 - 死循环
	{
		printf("%u\n", i);
	}
	return 0;
}
#include <string.h>
int main()
{
	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	//-1 -2 -3 ... -127 -128 127 126 125 ... 2 1 0 || -1 -2 -3 ...
	printf("%d\n", strlen(a));//打印128 + 127 = 255
	return 0;
}