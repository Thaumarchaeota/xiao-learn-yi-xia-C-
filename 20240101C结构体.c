/*�ṹ��*/
//����Ϊ��ͬ���͵�һЩֵ(��Ա����)�ļ���

//�ṹ��Ķ��塢�������ʼ��
struct gpa_mean //struct (name)������һ������
{
	//������Ա����
	float gpa_1;
	float gpa_2;
	char gpa_grade;

}s1, s2;//�˴���s1, s2Ϊȫ�ֵĽṹ�����

struct student  
{
	char name[10];
	int age;
	char major[10];
	struct gpa_mean;//�ṹ���ڳ�Ա����Ϊ��һ�ṹ��
}

int main()
{
	struct student s3;	//ʹ������struct student��������a
						//�˴�����Ϊ�ֲ��Ľṹ�����
	struct student s4 = { "name", 21, biology, {3.32, 3.45, B} };
}

//�ṹ���Ա�ķ���
struct book
{
	char name[20];
	char author[20];
	int price;
};

int main()
{
	struct book A = { "biochemistry", "lehninger", 200 };
	printf("%s\n", A.name);//�ṹ��.��Ա��
	struct book* pb = &A;
	printf("%s\n", (*pb).name);
	printf("%s\n", pb->name);//�ṹ��ָ�� -> ��Ա��
	return 0;
}

//�ṹ�崫��
struct student1
{
	char name[10];
	int age;
	char major[10];
	float gpa_mean;
};

void print1(struct student1 t)
{
	printf("%s %d %s %f\n", t.name, t.age, t.major, t.gpa_mean);
}

void print2(struct student1* pt)
{
	printf("%s %d %s %f\n", pt->name, pt->age, pt->major, pt->gpa_mean);
}

int main()
{
	struct student1 student01 = { "name", 21, "biology", 3.32 };
	print1(student01);//��ֵ���õķ������ṹ�����ʱ������ѹջ��ϵͳ�����ϴ������½�
	print2(&student01);//��ַ����Ӧ����ʹ�ã���ʡʱ����ռ䲢���ں����ڱ༭ԭ�ṹ��
	return 0;
}