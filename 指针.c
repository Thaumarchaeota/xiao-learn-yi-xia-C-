/*ָ��*/

//�������32λ������32����ַ�ߣ��ɴ���2^32���ڴ��ַ��ÿ����ַ�д洢1 byte
//���õ��� -> ���� -> �ڴ��У�����"&����"�鿴����ı����洢��ַ
//�˴��Ĵ洢��ַΪ��һ���ֽڵĴ洢��ַ(��������ռ�ռ�>1byte)��
//ÿ����ַ��16���Ʊ�ʾ��16���Ƶ�һλ����4��������λ��ʾ��������16����λռ1 byte�ռ�

int main()
{
	int a = 0x11223344;//0x��ʾ16������
	int* pa = &a;//pa��Ϊָ���������*���壬��ʽΪ	(��������)*
	printf("%p\n", &dz);//%p���ڴ�ӡ��ַ

	int* sizeof_pointer = sizeof pa;//���е�ָ�������Ϊ4���ֽ�(x86)��8���ֽ�(x64)

	*pa = 0;			//*Ϊ�����ò���������ʽΪ	*(ָ�����)
						//��������ָ���������Ӧ�ı��������йأ�������1b��char*����int*���ڽ�����ʱ�����1b�Ŀռ����
						// -> ָ�����;��������õ�Ȩ�޴�С

	int pa2 = pa + 1;	//����ָ����мӼ�����ʱ�����Զ���Ӧһ���ַ���ռ�ռ�Ĵ�С
	printf("%p\n", pa2);//��int* +1ʱ��+4����char* +1ʱ����+1
						// -> ָ�����;���ָ��Ĳ���


	return 0;
}

/*Ұָ��*/
// ָ��ָ���λ�ò���֪(���/����ȷ/������)
int main()
{
	int* p;//ָ��(��Ϊ�ֲ�����)δ��ʼ��
	*p = 10;// -> �Ƿ������ڴ�

	int arr[2] = { 0 }; int i = 0;
	int* parr = &arr;
	for (i = 0, i <= 2, i++)// -> ָ��Խ�����
		*(parr + i) = 0;

	// -> ָ��ָ��Ŀռ䱻�ͷ�
	//�����ڶ�̬�ڴ�����ֲ����������ٵ����

	return 0;
}

//����Ұָ��ĳ���
//1.ָ��Ӧ��ʼ��
#include<stdio.h>

int main()
{
	int* p = NULL;//�����ȶ���Ϊ��ָ�룬����ʱ����ʹ��
	return 0;
}
//2.С��ָ��Խ��
	//C���Ա����������Խ��
//3.ָ��ָ��ռ��ͷż�����NULL
//4.ָ��ʹ��֮ǰ�����Ч��
int main()
{
	int* p = NULL;
	if (p != NULL) { ; }
	return 0;
}

/*ָ������*/
//ָ���+-����	ָ��Ĺ�ϵ����
#define N_values 5
int main()
{
	float values[N_values];
	float* vp;
	for (vp = &values[0]; vp < values[N_values];)//ָ��Ĺ�ϵ����
	{
		*vp++ = 0;//ָ���+-����
	}
	return 0;
}
//ָ��-ָ��	�õ�ָ����ָ��֮���Ԫ�ظ���		��Ҫָ��������ͬ��ָ��ͬһ��ռ�

//����ָ��-ָ��ʵ��strlen����
int strlen_dp(char* arr1)
{
	char* arr2 = 0;
	for (arr2 = arr1; *arr2 != '\0'; arr2++);
	return arr2 - arr1;
}

//ָ��Ĺ�ϵ����
#define N_values 5
int main()
{
	float values[N_values];
	float* vp;
	for (vp = &values[N_values]; vp > &values[0];)
	{
		*--vp = 0;
		//������������Ԫ��ָ�������һ��Ԫ�غ�����ڴ�λ��ָ��Ƚϣ������������һ��Ԫ��ǰλָ��Ƚ�
	}
	return 0;
}

/*����ָ��*/

int main()
{
	int a = 0;
	int* pa = &a;
	int** ppa = &pa;//����ָ�����
	return 0;
}

/*ָ��������*/
int main()
{
	//��ַ
	int arr[10] = { 0 };	//������Ԫ�ص�ַ	->	��Ԫ��ָ��
	printf("%p\n", arr);
	printf("%p\n", arr + 1);	//����Ϊ4(int)

	int(*parr2)[10] = &arr;//	�����ַ		->	����ָ��
	printf("%p\n", parr2);
	printf("%p\n", parr2 + 1);	//����Ϊ40

	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,3,7,1,1 };
	int c[] = { 4,9,2,7,3 };

	//������Ԫ����ָ�������ʹ��
	int* arr[] = { a, b, c };//�˴�Ϊ����abc��������ָ���ָ������
	int i = 0; int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);//arr[i]�������abc��������Ԫ��ָ�룬����Ϊ������
		}
		printf("\n");
	}
	return 0;
}

//����ָ���ʹ��
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;

	
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *((*parr) + i));
		//parrΪ����ָ��/�����ַ��parr�����õõ�*parrΪ���飬��arr��ʵ�ʴ�����Ԫ�ص�ַ����+i�������õõ�����Ԫ��
	}
	//����д��

	return 0;
}

//��ά�����ָ��
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

//int(*parr[10])[5]��һ��ʮԪ�ص�ָ�����飬ÿ��ָ��Ϊָ��ӵ��5��int��Ԫ�ص�����ָ��

//һάint���鴫��

void test(int arr[]) { ; }//ʹ��һά������գ���ʡ��[]����ֵ
void test(int* arr) { ; }//ʹ����Ԫ��ָ�����

int main()
{
	int arr[10] = { 0 };
	test(arr);
	return 0;
}

//һάintָ�����鴫��

void test(int* arr[]) { ; }//ʹ��һάָ��������գ���ʡ��[]����ֵ
void test(int** arr) { ; }//ʹ����Ԫ��(ָ��)��ָ��(��άָ��)����

int main()
{
	int* arr[10] = { 0 };
	test(arr);
	return 0;
}

//��ά���鴫��

void test(int arr[][3]) { ; }//ʹ�ö�ά������գ���ʡ���е�[]����ֵ
void test(int(*arr)[3]) { ; }//ʹ����Ԫ��(��һ�е�һά����)��ָ��(����ָ��)����

int main()
{
	int arr[2][3] = {0};
	test(arr);
	return 0;
}

//һ��ָ�봫��

void test(int* p) { ; }


int main()
{
	char a = ' ';
	test(&a);
	
	char* pa = &a;
	test(pa);

	return 0;
}

//����ָ�봫��

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
	test(arr);//���Խ� ���һ��ָ������� ����

	return 0;
}

/*����ָ��*/
int func(int x, int y)
{
	return x * y;
}

int main()
{
	printf("%p\n", func);
	printf("%p\n", &func);//&func��func������ͬ����Ϊ������ַ
	int (*pfunc)(int, int) = func;//����ָ���ָ�����ͣ�����ֱ��=func��=&func

	int a = 2; int b = 7;
	int c = pfunc(a, b);//ֱ��ʹ�ú�����ַ���ú���

	(*(void(*)())0)();
	//1.��������0����ǿ������ת����( void(*)() )������ת��Ϊһ��void�����޲εĺ���ָ��
	//2.�Ը�ָ����н����ú����( *( (xxx)0 ) )()
	//�����Ŀ��Ϊ����0��ַ���ĺ���

	void (*signal(int, void(*)(int)))(int);
	//1.signal�����Ƚ��Բ���ţ���signalΪ�������������������������ͱ���int �� ��������Ϊvoid������Ϊint�ĺ���ָ��
	//2.signal�����ķ�������Ϊvoid(*)(int)�ĺ���ָ��
	//�����Ϊ��������

	//�������ɶ��Ե��Ż�
	typedef void (*pfun_t)(int);//�����ض���
	pfun_t signal(int, pfun_t);

	return 0;
}

/*����ָ������*/
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
	printf("     1.�ӷ�  2.����     \n");
	printf("     3.�˷�  4.����     \n");
	printf("         0.�˳�        \n");
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
			printf("��������Ҫ�����ֵ");
			scanf("%d %d", &a, &b);
			printf("%d\n", (cal_arr[input - 1])(a, b));
		}
		else if (input == 0)
			break;
		else
			printf("�����������������")
	} while (1);
	return 0;
}

//�ص�����
//qsort������������
int main()
{
	void qsort(void* base,//ָ����Ҫ�������������Ԫ�ص��޾������͵�ָ��
				size_t num,//baseָ�������Ԫ�ظ���
				size_t size,//baseָ���������ÿ��Ԫ�ش�С(byte)
				int (*compar)(const void*, const void*) //p1/p2
				//ָ���ܱȽϴ���������Ԫ�ش�С�ĺ���ָ�룬��p1 > p2ʱ������������֮�򷵻ظ��������ʱ����0
	);
	return 0;
}

//ʹ��qsort����int������

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

//ʹ��qsort����ṹ��
struct stu
{
	char name[20];
	int age;
	float gpa_total;
};

void print_struct_stu_list(struct stu* arr, int sz)
{
	int i = 0;
	printf("����    ����    �ɼ�\n");
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
	//�ɼ��ɸߵ�������	
}

int main()
{
	struct stu stu_list[] = { {"sda", 21, 3.212}, {"rsd", 19, 2.97}, {"das", 23, 3.20}, {"shz", 22, 3.562}, {"shf", 20, 3.05} };
	print_struct_stu_list(stu_list, sizeof(stu_list) / sizeof(stu_list[0]));
	qsort(stu_list, sizeof(stu_list) / sizeof(stu_list[0]), sizeof(stu_list[0]), cmp_struct_stu);
	print_struct_stu_list(stu_list, sizeof(stu_list) / sizeof(stu_list[0]));
}

//qsort������ģ��ʵ��

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