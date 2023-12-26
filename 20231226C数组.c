/*数组*/
//数组为一组相同元素的集合	
//一维数组的创建和初始化
int main()
{
	//数组创建：元素类型、数组名与元素个数(常量表达式)
	//元素个数需要常量表达式，不可为变量。C99语法支持则可输入变量作为变长数组
	int arr_name[4];
	
	//数组的初始化：
	int arr1[3] = { 1,2,3 };//完全初始化
	int arr2[] = { 1,2,4,1,2 };//根据元素个数决定数组大小，完全初始化
	int arr3[5] = { 1,2,3 };//不完全初始化
	
	//字符数组与字符串:
	int chr1[] = { 'd', 'y', 'n' };//此处创建3元素数组，分别为[d y n]
	int chr2[5] = { 'd', 'y', 'n' };//此处创建5元素数组，分别为[d y n \0 \0]
	int chr3[] = "dyn";//此处创建strlen为3的字符串，即4元素数组[d y n \0]
	int chr4[5] = "dyn";//此处创建5元素数组[d y n \0 \0]
	//当使用printf打印%s或使用strlen时，其本质上为寻找\0，故对于chr1时为随机值。

	//使用下标访问数组[],以0起始
	arr3[4] = 3;
	//打印数组
	int arr_size = 0;
	arr_size = sizeof(arr2) / sizeof(arr2[0]);
	int count_output = 0;
	for (count_output = 0; count_output < arr_size; count_output++)
	{
		printf("%d ", arr2[count_output]);//打印元素
	}
	printf("\n");
	for (count_output = 0; count_output < arr_size; count_output++)
	{
		printf("%p ", &arr2[count_output]);//打印地址
	}
	/**
	 *一维数组在内存中是连续存放的
	 *数组名是首元素的地址
	 *sizeof(数组) - 此时数组名表示整个数组
	 *&数组名 - 此时数组名表示整个数组 - 取出整个数组的地址
	 */
	printf("%p\n", arr1);//打印数组首元素地址
	printf("%p\n", &arr1[0]);//打印数组首元素地址
	printf("%p\n", &arr1);//打印数组地址，其值与首元素地址相同，但+1后地址增加整个数组大小

	return 0;
}

/*二维数组*/
int main()
{
	int arr5[3][4];//二维数组的创建[行][列]
	//从行1开始往后放，不完全初始化时剩余项为0
	int arr6[3][4] = { 1,2,3,4,5,6,7,8,9,10 };
	//以大括号初始化时按行分别放入，其中行可省略，列不可
	int arr7[][4] = { {1,2}, {3,4}, {5,6} };

	//二维数组的下标访问，其行号与列号均以0起始
	int arr7[3][3] = 4;

	//打印二维数组
	int arr6[3][4] = { 1,2,3,4,5,6,7,8,9,10 };

	int count_arr6pi = 0;
	int count_arr6pj = 0;
	for (count_arr6pi = 0; count_arr6pi < 3; count_arr6pi++)
	{
		printf("第%d行的元素包括", count_arr6pi + 1);
		for (count_arr6pj = 0; count_arr6pj < 4; count_arr6pj++)
		{
			printf("%d ", arr6[count_arr6pi][count_arr6pj]);
		}
		printf("\n");
	}

	for (count_arr6pi = 0; count_arr6pi < 3; count_arr6pi++)
	{
		printf("第%d行的元素地址分别为", count_arr6pi + 1);
		for (count_arr6pj = 0; count_arr6pj < 4; count_arr6pj++)
		{
			printf("%p ", &arr6[count_arr6pi][count_arr6pj]);
		}
		printf("\n");
	}
	return 0;
}

//冒泡排序
void bubble_sort(int* p1, int len)
{
	int* x;
	int len_real = len;
	for (len_real = len; len_real > 1; len_real--)
	{
		for (x = p1; x <= p1 + len_real - 2; x++)
		{
			if (*x > *(x + 1))
			{
				int y = 0;
				y = *(x + 1);
				*(x + 1) = *x;
				*x = y;
			}
		}
	}
}

int main()
{
	int arr9[10] = { 5,3,2,124,42,52,27,213,473,1 };
	bubble_sort(arr9, 10);
	int arr_size = 0;
	arr_size = sizeof(arr9) / sizeof(arr9[0]);
	int count_output = 0;
	for (count_output = 0; count_output < arr_size; count_output++)
	{
		printf("%d ", arr9[count_output]);//打印元素
	}
	printf("\n");
	return 0;
}