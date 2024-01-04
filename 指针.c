/*指针*/

//计算机中32位即具有32根地址线，可代表2^32个内存地址，每个地址中存储1 byte
//利用调试 -> 窗口 -> 内存中，输入"&变量"查看定义的变量存储地址
//此处的存储地址为第一个字节的存储地址(当变量所占空间>1byte)，
//每个地址以16进制表示，16进制的一位可用4个二进制位表示，故两个16进制位占1 byte空间

int main()
{
	int a = 0x11223344;//0x表示16进制数
	int* pa = &a;//pa称为指针变量，用*定义，格式为	(变量类型)*
	printf("%p\n", &dz);//%p用于打印地址

	int* sizeof_pointer = sizeof pa;//所有的指针变量均为4个字节(x86)或8个字节(x64)

	*pa = 0;			//*为解引用操作符，格式为	*(指针变量)
						//解引用与指针变量所对应的变量类型有关，例如以1b的char*定义int*，在解引用时仅会对1b的空间操作
						// -> 指针类型决定解引用的权限大小

	int pa2 = pa + 1;	//当对指针进行加减运算时，其自动对应一个字符所占空间的大小
	printf("%p\n", pa2);//如int* +1时会+4，而char* +1时仅会+1
						// -> 指针类型决定指针的步长


	return 0;
}

/*野指针*/
// 指针指向的位置不可知(随机/不正确/无限制)
int main()
{
	int* p;//指针(作为局部变量)未初始化
	*p = 10;// -> 非法访问内存

	int arr[2] = { 0 }; int i = 0;
	int* parr = &arr;
	for (i = 0, i <= 2, i++)// -> 指针越界访问
		*(parr + i) = 0;

	// -> 指针指向的空间被释放
	//出现于动态内存分配或局部变量被销毁等情况

	return 0;
}

//避免野指针的出现
//1.指针应初始化
#include<stdio.h>

int main()
{
	int* p = NULL;//可首先定义为空指针，但此时不能使用
	return 0;
}
//2.小心指针越界
	//C语言本身不检查数据越界
//3.指针指向空间释放即设置NULL
//4.指针使用之前检查有效性
int main()
{
	int* p = NULL;
	if (p != NULL) { ; }
	return 0;
}

/*指针运算*/
//指针的+-运算	指针的关系运算
#define N_values 5
int main()
{
	float values[N_values];
	float* vp;
	for (vp = &values[0]; vp < values[N_values];)//指针的关系运算
	{
		*vp++ = 0;//指针的+-运算
	}
	return 0;
}
//指针-指针	得到指针与指针之间的元素个数		需要指针类型相同且指向同一块空间

//利用指针-指针实现strlen函数
int strlen_dp(char* arr1)
{
	char* arr2 = 0;
	for (arr2 = arr1; *arr2 != '\0'; arr2++);
	return arr2 - arr1;
}

//指针的关系运算
#define N_values 5
int main()
{
	float values[N_values];
	float* vp;
	for (vp = &values[N_values]; vp > &values[0];)
	{
		*--vp = 0;
		//规则允许数组元素指针与最后一个元素后面的内存位置指针比较，而不允许与第一个元素前位指针比较
	}
	return 0;
}

/*二级指针*/

int main()
{
	int a = 0;
	int* pa = &a;
	int** ppa = &pa;//二级指针变量
	return 0;
}

/*数组指针*/
int main()
{

}


/*指针与数组*/
int main()
{
	//地址
	int arr[10] = { 0 };	//数组首元素地址	->	首元素指针
	printf("%p\n", arr);
	printf("%p\n", arr + 1);	//步长为4(int)

	int(*parr2)[10] = &arr;//	数组地址		->	数组指针
	printf("%p\n", parr2);
	printf("%p\n", parr2 + 1);	//步长为40

	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,3,7,1,1 };
	int c[] = { 4,9,2,7,3 };

	//数组首元素与指针数组的使用
	int* arr[] = { a, b, c };//此处为包含abc三个数组指针的指针数组
	int i = 0; int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);//arr[i]本身代表abc的数组首元素指针，可视为数组名
		}
		printf("\n");
	}
	return 0;
}

//数组指针的使用
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;

	
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *((*parr) + i));
		//parr为数组指针/数组地址，parr解引用得到*parr为数组，即arr，实际代表首元素地址，再+i并解引用得到数组元素
	}
	//不当写法

	return 0;
}

//二维数组的指针
void print_arr(int(*parr)[5], int row, int col)
{
	int i = 0; int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(parr + i) + j));
		}
		printf("\n");
	}
}


int main()
{
	int arr[3][5] = { 1,5,2,4,7,3,1,3,6,7,9,5,2,3,5 };
	print_arr(arr, 3, 5);
	return 0;
}

//int(*parr[10])[5]是一个十元素的指针数组，每个指针为指向拥有5个int型元素的数组指针

//一维数组传参
