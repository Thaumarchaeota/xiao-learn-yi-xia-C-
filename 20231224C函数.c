/*�⺯��*/
//www.cplusplus.com
//�����Ŀ⺯������
//IO����
//�ַ�����������
//�ַ���������
//����/ʱ�亯��
//��ѧ����
//�����⺯��

#include<stdio.h>
#include<string.h>

int main()
{
	char dest[20] = { 0 };
	char sour[] = { "chloroplast" };
	strcpy(dest, sour);
	printf("%s\n%s\n", dest, sour)
	return 0;
}

/*�Զ��庯��*/
//���к�����������ֵ���ͺͺ�������

int get_maxoftwo(int x, int y)//�������͡�����������������
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

void exc(int* x, int* y)
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
	exc(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}