//��������ʽ����:һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
int main()
{
	printf("%d", printf("%d", printf("%d", 43));
	//printf�ķ���ֵΪ������ַ��ĸ����������Ϊ4321
	return 0;
}

/*�����������Ͷ���*/
int main()
{
	int a = 2;
	int b = 4;
	int Add(int, int);
	//������������д���䷵�����͡���������������ͣ�������������޹�
	//��������Ӧ���ں�����ʹ��֮ǰ��������������ڵ���ǰ����������
	//��������һ�����ͷ�ļ� .h�ļ���
	int c = Add(a, b)
	return 0;
}

//�����Ķ��壺���幦�ܣ�һ�����.c�ļ�
int Add(int x, int y)
{
	int z = x + y;
	return z;
}

/*�����ݹ�:����ֱ�ӻ��ӵص�������ط���*/
void print(unsigned int x)
{
	if (x > 9)//�ݹ����������������������ʱ���ٵݹ�
	{
		print(x / 10);//ÿ�εݹ���Ӧ�ı����ʹ��Խ��Խ�ӽ���������
	}
	printf("%d ", x % 10);
}

int main()
{
	unsigned int x = 0;
	scanf("%u", &x);
	print(x);
	return 0;
}

//strlen����ʵ�ֵĴ�ͳ��ݹ鷽��
int arr_len(char* x)
{
	int count = 0;
	while (*x != '\0')
	{
		count++;
		x++;
	}
	return count;
}

int arr_len2(char* x)
{
	if (*x != '\0')
		return 1 + arr_len2(x + 1);
	else
		return 0;
}

int main()
{
	char arr[] = { "abcdefghi" };
	printf("%d\n", arr_len(arr));
	printf("%d\n", arr_len2(arr));
	printf("%d\n", strlen(arr));
	return 0;
}

//ʵ��n�Ľ׳�
int fac1(int x)
{
	int cal = 1;
	int result = 1;
	if (0 == x)
	{
		return 1;
	}

	for (cal == 1; cal <= x; cal++)
	{
		result = result * cal;
	}
	return result;
}

int fac2(int x)
{
	if (x <= 1)
		return 1;
	else
		return x * fac2(x - 1);
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", fac1(a));
	printf("%d\n", fac2(a));
	return 0;
}

//쳲���������
int Fibonacci_1(int x)
{
	if (x <= 2)
		return 1;
	else
		return Fibonacci_1(x - 1) + Fibonacci_1(x - 2);
}

int Fibonacci_2(int x)
{
	int a = 0;
	int b = 1;
	int result = 1;
	int count = 0;

	for (count = 2; count <= x; count++)
	{
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", Fibonacci_1(a));
	printf("%d\n", Fibonacci_2(a));
	return 0;
}