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

//一维int数组传参

void test(int arr[]) { ; }//使用一维数组接收，可省略[]内数值
void test(int* arr) { ; }//使用首元素指针接收

int main()
{
	int arr[10] = { 0 };
	test(arr);
	return 0;
}

//一维int指针数组传参

void test(int* arr[]) { ; }//使用一维指针数组接收，可省略[]内数值
void test(int** arr) { ; }//使用首元素(指针)的指针(二维指针)接收

int main()
{
	int* arr[10] = { 0 };
	test(arr);
	return 0;
}

//二维数组传参

void test(int arr[][3]) { ; }//使用二维数组接收，可省略行的[]内数值
void test(int(*arr)[3]) { ; }//使用首元素(第一列的一维数组)的指针(数组指针)接收

int main()
{
	int arr[2][3] = {0};
	test(arr);
	return 0;
}

//一级指针传参

void test(int* p) { ; }


int main()
{
	char a = ' ';
	test(&a);
	
	char* pa = &a;
	test(pa);

	return 0;
}

//二级指针传参

test(int** p) { ; }
test() { ; }

int main()
{
	int a = 3;
	int* pa = &a;
	test(&pa);

	int** ppa = &pa;
	test(ppa);
	
	int* arr[10] = { 0 };
	test(arr);//可以将 存放一级指针的数组 传参

	return 0;
}

/*函数指针*/
int func(int x, int y)
{
	return x * y;
}

int main()
{
	printf("%p\n", func);
	printf("%p\n", &func);//&func与func意义相同，均为函数地址
	int (*pfunc)(int, int) = func;//函数指针的指针类型，可以直接=func或=&func

	int a = 2; int b = 7;
	int c = pfunc(a, b);//直接使用函数地址调用函数

	(*(void(*)())0)();
	//1.对于数字0进行强制类型转换：( void(*)() )，将其转化为一个void类型无参的函数指针
	//2.对该指针进行解引用后调用( *( (xxx)0 ) )()
	//该语句目的为调用0地址处的函数

	void (*signal(int, void(*)(int)))(int);
	//1.signal后首先结合圆括号，故signal为函数名，含有两个参数：整型变量int 与 返回类型为void，参数为int的函数指针
	//2.signal函数的返回类型为void(*)(int)的函数指针
	//该语句为函数声明

	//对声明可读性的优化
	typedef void (*pfun_t)(int);//类型重定义
	pfun_t signal(int, pfun_t);

	return 0;
}

/*函数指针数组*/
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("-----------------------\n");
	printf("     1.加法  2.减法     \n");
	printf("     3.乘法  4.除法     \n");
	printf("         0.退出        \n");
	printf("-----------------------\n");
}

int main()
{
	int input = 0; int a = 0; int b = 0;
	int(*cal_arr[])(int, int) = { Add, Sub, Mul, Div };
	do
	{
		menu();
		scanf("%d", &input);
		if (input >= 1 || input <= 4)
		{
			printf("请输入需要计算的值");
			scanf("%d %d", &a, &b);
			printf("%d\n", (cal_arr[input - 1])(a, b));
		}
		else if (input == 0)
			break;
		else
			printf("输入错误，请重新输入")
	} while (1);
	return 0;
}

//回调函数
//qsort函数快速排序
int main()
{
	void qsort(void* base,//指向需要被排序的数组首元素的无具体类型的指针
				size_t num,//base指向的数组元素个数
				size_t size,//base指向的数组中每个元素大小(byte)
				int (*compar)(const void*, const void*) //p1/p2
				//指向能比较待排序数据元素大小的函数指针，当p1 > p2时返回正数，反之则返回负数，相等时返回0
	);
	return 0;
}

//使用qsort排序int型数据

void print_arr_int(int* arr, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

int cmp(const void* x, const void* y)
{
	return (*(int*)x) - (*(int*)y);
}


int main()
{
	int arr1[] = { 3,5,2,6,1,8,4,1,4,5 };
	print_arr_int(arr1, sizeof(arr1) / sizeof(arr1[0]));
	qsort(arr1, sizeof arr1 / sizeof arr1[0], sizeof arr1[0], cmp);
	print_arr_int(arr1, sizeof(arr1) / sizeof(arr1[0]));

	return 0;
}

//使用qsort排序结构体
struct stu
{
	char name[20];
	int age;
	float gpa_total;
};

void print_struct_stu_list(struct stu* arr, int sz)
{
	int i = 0;
	printf("姓名    年龄    成绩\n");
	for (i = 0; i < sz; i++)
	{
		printf("%s     ", (arr + i)->name);
		printf("%d     ", (arr + i)->age);
		printf("%f\n", (arr + i)->gpa_total);
	}

}

int cmp_struct_stu(const void* a, const void* b)
{
	if (((struct stu*)a)->gpa_total < ((struct stu*)b)->gpa_total)
		return 1;
	else if (((struct stu*)a)->gpa_total == ((struct stu*)b)->gpa_total)
		return 0;
	else if (((struct stu*)a)->gpa_total > ((struct stu*)b)->gpa_total)
		return -1;
	//成绩由高到低排序	
}

int main()
{
	struct stu stu_list[] = { {"sda", 21, 3.212}, {"rsd", 19, 2.97}, {"das", 23, 3.20}, {"shz", 22, 3.562}, {"shf", 20, 3.05} };
	print_struct_stu_list(stu_list, sizeof(stu_list) / sizeof(stu_list[0]));
	qsort(stu_list, sizeof(stu_list) / sizeof(stu_list[0]), sizeof(stu_list[0]), cmp_struct_stu);
	print_struct_stu_list(stu_list, sizeof(stu_list) / sizeof(stu_list[0]));
}

//qsort函数的模拟实现

void swap(char* parr1, char* parr2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		*(parr1 + i) ^= *(parr1 + size + i) ^= *(parr1 + i) ^= *(parr1 + size + i);
	}
}

void quicksort(void* arr, size_t num, size_t size, int (*compare)(const void*, const void*))
{
	int cycle = 0; int i = 0;
	for (cycle = 1; cycle < num - 1; cycle++)
	{
		for (i = 0; i <= num - 1 - cycle; i++)
		{
			if (compare((char*)arr + i * size, (char*)arr + (i + 1) * size) > 0)
			{
				swap((char*)arr + i * size, (char*)arr + (i + 1) * size, size);
			}
		}
	}
}