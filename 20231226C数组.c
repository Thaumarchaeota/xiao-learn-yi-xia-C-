/*����*/
//����Ϊһ����ͬԪ�صļ���	
//һά����Ĵ����ͳ�ʼ��
int main()
{
	//���鴴����Ԫ�����͡���������Ԫ�ظ���(�������ʽ)
	//Ԫ�ظ�����Ҫ�������ʽ������Ϊ������C99�﷨֧��������������Ϊ�䳤����
	int arr_name[4];
	
	//����ĳ�ʼ����
	int arr1[3] = { 1,2,3 };//��ȫ��ʼ��
	int arr2[] = { 1,2,4,1,2 };//����Ԫ�ظ������������С����ȫ��ʼ��
	int arr3[5] = { 1,2,3 };//����ȫ��ʼ��
	
	//�ַ��������ַ���:
	int chr1[] = { 'd', 'y', 'n' };//�˴�����3Ԫ�����飬�ֱ�Ϊ[d y n]
	int chr2[5] = { 'd', 'y', 'n' };//�˴�����5Ԫ�����飬�ֱ�Ϊ[d y n \0 \0]
	int chr3[] = "dyn";//�˴�����strlenΪ3���ַ�������4Ԫ������[d y n \0]
	int chr4[5] = "dyn";//�˴�����5Ԫ������[d y n \0 \0]
	//��ʹ��printf��ӡ%s��ʹ��strlenʱ���䱾����ΪѰ��\0���ʶ���chr1ʱΪ���ֵ��

	//ʹ���±��������[],��0��ʼ
	arr3[4] = 3;
	//��ӡ����
	int arr_size = 0;
	arr_size = sizeof(arr2) / sizeof(arr2[0]);
	int count_output = 0;
	for (count_output = 0; count_output < arr_size; count_output++)
	{
		printf("%d ", arr2[count_output]);//��ӡԪ��
	}
	printf("\n");
	for (count_output = 0; count_output < arr_size; count_output++)
	{
		printf("%p ", &arr2[count_output]);//��ӡ��ַ
	}
	/**
	 *һά�������ڴ�����������ŵ�
	 *����������Ԫ�صĵ�ַ
	 *sizeof(����) - ��ʱ��������ʾ��������
	 *&������ - ��ʱ��������ʾ�������� - ȡ����������ĵ�ַ
	 */
	printf("%p\n", arr1);//��ӡ������Ԫ�ص�ַ
	printf("%p\n", &arr1[0]);//��ӡ������Ԫ�ص�ַ
	printf("%p\n", &arr1);//��ӡ�����ַ����ֵ����Ԫ�ص�ַ��ͬ����+1���ַ�������������С

	return 0;
}

/*��ά����*/
int main()
{
	int arr5[3][4];//��ά����Ĵ���[��][��]
	//����1��ʼ����ţ�����ȫ��ʼ��ʱʣ����Ϊ0
	int arr6[3][4] = { 1,2,3,4,5,6,7,8,9,10 };
	//�Դ����ų�ʼ��ʱ���зֱ���룬�����п�ʡ�ԣ��в���
	int arr7[][4] = { {1,2}, {3,4}, {5,6} };

	//��ά������±���ʣ����к����кž���0��ʼ
	int arr7[3][3] = 4;

	//��ӡ��ά����
	int arr6[3][4] = { 1,2,3,4,5,6,7,8,9,10 };

	int count_arr6pi = 0;
	int count_arr6pj = 0;
	for (count_arr6pi = 0; count_arr6pi < 3; count_arr6pi++)
	{
		printf("��%d�е�Ԫ�ذ���", count_arr6pi + 1);
		for (count_arr6pj = 0; count_arr6pj < 4; count_arr6pj++)
		{
			printf("%d ", arr6[count_arr6pi][count_arr6pj]);
		}
		printf("\n");
	}

	for (count_arr6pi = 0; count_arr6pi < 3; count_arr6pi++)
	{
		printf("��%d�е�Ԫ�ص�ַ�ֱ�Ϊ", count_arr6pi + 1);
		for (count_arr6pj = 0; count_arr6pj < 4; count_arr6pj++)
		{
			printf("%p ", &arr6[count_arr6pi][count_arr6pj]);
		}
		printf("\n");
	}
	return 0;
}

//ð������
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
		printf("%d ", arr9[count_output]);//��ӡԪ��
	}
	printf("\n");
	return 0;
}