/*结构体*/
//可以为不同类型的一些值(成员变量)的集合

//结构体的定义、声明与初始化
struct gpa_mean //struct (name)本身是一个类型
{
	//创建成员变量
	float gpa_1;
	float gpa_2;
	char gpa_grade;

}s1, s2;//此处的s1, s2为全局的结构体变量

struct student  
{
	char name[10];
	int age;
	char major[10];
	struct gpa_mean;//结构体内成员可以为另一结构体
}

int main()
{
	struct student s3;	//使用类型struct student创建对象a
						//此处创建为局部的结构体变量
	struct student s4 = { "name", 21, biology, {3.32, 3.45, B} };
}

//结构体成员的访问
struct book
{
	char name[20];
	char author[20];
	int price;
};

int main()
{
	struct book A = { "biochemistry", "lehninger", 200 };
	printf("%s\n", A.name);//结构体.成员名
	struct book* pb = &A;
	printf("%s\n", (*pb).name);
	printf("%s\n", pb->name);//结构体指针 -> 成员名
	return 0;
}

//结构体传参
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
	print1(student01);//传值调用的方法当结构体过大时，参数压栈的系统开销较大，性能下降
	print2(&student01);//传址调用应优先使用，节省时间与空间并可在函数内编辑原结构体
	return 0;
}