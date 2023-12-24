//预处理指令#define，定义常量和宏
#define a 100
#define H(X,Y) ((X)+(Y))//define定义宏

#include<stdio.h>

/*结构体：定义复杂变量*/
struct studentinfo
{
	char name[20];
	int age;
	char major[20];
	float height;
	float weight;
};

int main()
{
	//主函数中创建和初始化结构体
	struct studentinfo S1 = { "名字示例", 20, "主修示例", 180.0, 70.0};
	struct studentinfo * S1Z = &S1;//S1Z为结构体指针
	printf("%s %d %s %f %f\n", S1.name, S1.age, S1.major, S1.height, S1.weight);//结构体变量.成员变量
	printf("%s %d %s %f %f\n", (*S1Z).name, (*S1Z).age, (*S1Z).major, (*S1Z).height, (*S1Z).weight);
	printf("%s %d %s %f %f\n", S1Z->name, S1Z->age, S1Z->major, S1Z->height, S1Z->weight);//结构体指针->成员变量名

	//static修饰局部变量可将其从放入
	//static修饰全局变量可将其局限在一个源文件内，无法在其他源文件中声明并使用
	
	//计算机中32位即具有32根地址线，可代表2^32个内存地址，每个地址中存储1 byte
	int dz = 1;
	//利用调试 -> 窗口 -> 内存中，输入"&变量"查看定义的变量存储地址
	//此处的存储地址为第一个字节的存储地址(当变量所占空间>1byte)，
	//每个地址以16进制表示，地址中以2位16进制数表示1byte
	printf("%p\n", &dz);//%p打印地址
	int* ad = &dz;//ad用以存放地址，称为指针变量，利用*定义
	//int代表指针变量执行的对象类型，*代表ad为指针变量
	
	//*为解引用操作，可通过指针变量中的地址找到并改动变量
	*ad = 2;//此时通过ad中存储的地址找到dz并将其值改为2

	//指针的大小均为相同的4个字节(32位)或8个字节(64位)
	printf("%d\n", sizeof(int*));



	return 0;
}
