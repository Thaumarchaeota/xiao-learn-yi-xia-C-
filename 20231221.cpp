//Ԥ����ָ��#define�����峣���ͺ�
#define a 100
#define H(X,Y) ((X)+(Y))//define�����

#include<stdio.h>

/*�ṹ�壺���帴�ӱ���*/
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
	//�������д����ͳ�ʼ���ṹ��
	struct studentinfo S1 = { "����ʾ��", 20, "����ʾ��", 180.0, 70.0};
	struct studentinfo * S1Z = &S1;//S1ZΪ�ṹ��ָ��
	printf("%s %d %s %f %f\n", S1.name, S1.age, S1.major, S1.height, S1.weight);//�ṹ�����.��Ա����
	printf("%s %d %s %f %f\n", (*S1Z).name, (*S1Z).age, (*S1Z).major, (*S1Z).height, (*S1Z).weight);
	printf("%s %d %s %f %f\n", S1Z->name, S1Z->age, S1Z->major, S1Z->height, S1Z->weight);//�ṹ��ָ��->��Ա������

	//static���ξֲ������ɽ���ӷ���
	//static����ȫ�ֱ����ɽ��������һ��Դ�ļ��ڣ��޷�������Դ�ļ���������ʹ��
	
	//�������32λ������32����ַ�ߣ��ɴ���2^32���ڴ��ַ��ÿ����ַ�д洢1 byte
	int dz = 1;
	//���õ��� -> ���� -> �ڴ��У�����"&����"�鿴����ı����洢��ַ
	//�˴��Ĵ洢��ַΪ��һ���ֽڵĴ洢��ַ(��������ռ�ռ�>1byte)��
	//ÿ����ַ��16���Ʊ�ʾ����ַ����2λ16��������ʾ1byte
	printf("%p\n", &dz);//%p��ӡ��ַ
	int* ad = &dz;//ad���Դ�ŵ�ַ����Ϊָ�����������*����
	//int����ָ�����ִ�еĶ������ͣ�*����adΪָ�����
	
	//*Ϊ�����ò�������ͨ��ָ������еĵ�ַ�ҵ����Ķ�����
	*ad = 2;//��ʱͨ��ad�д洢�ĵ�ַ�ҵ�dz������ֵ��Ϊ2

	//ָ��Ĵ�С��Ϊ��ͬ��4���ֽ�(32λ)��8���ֽ�(64λ)
	printf("%d\n", sizeof(int*));



	return 0;
}