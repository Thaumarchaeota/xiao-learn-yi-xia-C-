/*自定义函数*/
//具有函数名、返回值类型和函数参数

int get_maxoftwo(int x, int y)//返回类型、函数名、函数参数
//传值调用：形参相当于实参的拷贝，改变与操作形参不改变实参
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


//交换两个整型变量的函数
void exc(int* x, int* y) //xy为形式参数(形参)
//形参只有在调用时实例化，调用完毕后销毁
//传址调用：调用外部创建变量的地址
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
	exc(&a, &b);//调用函数时传递的值为实际参数(实参)
	//实参可以为常量、变量、表达式、函数等
	printf("%d %d\n", a, b);
	return 0;
}

/*输出指定区间的素数*/
int judge_prime(int x)
{
	int y = 0;
	for (y = 2; y <= sqrt(x); y++)
	{
		if (x % y == 0)
		{
			return 0;
		}
	}
	return 1;

}

int max_oftwo(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int min_oftwo(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	return y;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d", &a, &b);
	int min = min_oftwo(a, b);
	int max = max_oftwo(a, b);
	if (a < 0 || b < 0)
	{
		printf("请输入大于0的整数");
	}
	else
	{
		int count = 0;
		for (c = min; c <= max; c++)
		{
			if ((judge_prime(c)) == 1)
			{
				printf("%d\n", c);
				count++;
			}
		}
		printf("在%d到%d之间共有如上所示的%d个素数", min, max, count);
	}
	return 0;

}

/*判断闰年*/
int judge_leap(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
	{
		return 1;
	}
	return 0;
}

/*整型有序数组的二分查找*/

int binary_search(int arr[], int key, int num)
//此处第一位对应的实参为数组，传递的为首元素地址
//因此此处的形参实际数据类型为int*
{
	int left_boundary = 0;
	int right_boundary = num;
	do
	{
		int mid = (left_boundary + right_boundary) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			left_boundary = mid;
		}
		else if (arr[mid] > key)
		{
			right_boundary = mid;
		}
	} while (left_boundary <= right_boundary);
	return -1;
}

int main()
{
	int array[] = { 1,2,3,4,5,6,7 };
	int key = 6;
	int num = sizeof(array) / sizeof(array[0]);
	//由于数组传参时只会传首元素地址，因此只能在函数外求出元素个数并作为变量传递
	int c = binary_search(array, key, num);
	if (-1 == c)
	{
		printf("%d不存在于该数组中", key);
	}
	else
		printf("%d在该数组中对应的下标为%d\n", key, c);
	return 0;
}