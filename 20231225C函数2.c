/*�Զ��庯��*/
//���к�����������ֵ���ͺͺ�������

int get_maxoftwo(int x, int y)//�������͡�����������������
//��ֵ���ã��β��൱��ʵ�εĿ������ı�������ββ��ı�ʵ��
{
	//������
	int z = 0;
	if (x > y)
		z = x;
	else
		z = y;
	return z;//����ֵ
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = get_maxoftwo(a, b);//���ú���
	//���ӵ��ú����ڲ���ҪF11
	printf("max=%d", c)
	return 0;
}


//�����������ͱ����ĺ���
void exc(int* x, int* y) //xyΪ��ʽ����(�β�)
//�β�ֻ���ڵ���ʱʵ������������Ϻ�����
//��ַ���ã������ⲿ���������ĵ�ַ
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
	exc(&a, &b);//���ú���ʱ���ݵ�ֵΪʵ�ʲ���(ʵ��)
	//ʵ�ο���Ϊ���������������ʽ��������
	printf("%d %d\n", a, b);
	return 0;
}

/*���ָ�����������*/
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
		printf("���������0������");
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
		printf("��%d��%d֮�乲��������ʾ��%d������", min, max, count);
	}
	return 0;

}

/*�ж�����*/
int judge_leap(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
	{
		return 1;
	}
	return 0;
}

/*������������Ķ��ֲ���*/

int binary_search(int arr[], int key, int num)
//�˴���һλ��Ӧ��ʵ��Ϊ���飬���ݵ�Ϊ��Ԫ�ص�ַ
//��˴˴����β�ʵ����������Ϊint*
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
	//�������鴫��ʱֻ�ᴫ��Ԫ�ص�ַ�����ֻ���ں��������Ԫ�ظ�������Ϊ��������
	int c = binary_search(array, key, num);
	if (-1 == c)
	{
		printf("%d�������ڸ�������", key);
	}
	else
		printf("%d�ڸ������ж�Ӧ���±�Ϊ%d\n", key, c);
	return 0;
}