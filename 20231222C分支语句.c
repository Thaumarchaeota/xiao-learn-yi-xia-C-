//C语言中非0为真，0为假，真值默认输出1
int main()
{
	int a = 0;
	scanf("%d", &a);

	if (0 == a)//将常量放在左边可避免错误
		printf("a=0");
	else if (a < 5 && a > 0)
	//此处不能写作0<a<5，因程序会首先判断0<a，取真即输出1，并继续进行1<5的运算
		printf("0<a<5");
	else if (a < 0)//可写多个else if
	{
		printf("a<0");
		printf("!!")//if和else均仅执行一条语句，对于多条应打大括号
	}
	else//可不写
		printf("a<0或a>5");
	//若无大括号时，else对应其最近的if语句(悬空else)

	return 0;
}

//多项分支语句可用switch函数
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)//整型表达式中输出n即进入第n个语句
	{
	case 1://case n作为入口，n必须为整型常量表达式
		printf("monday\n");
		break;//break作为出口
	case 2:
		printf("tuesday\n");
		break;
	case 5:
		printf("friday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");
		break;//break不为必须加，依据需求而定
	default://除了case以外的情况默认进入该语句
		printf("error");
		break;
	}
	return 0;
}

//判断奇数偶数
int main()
{
	int input = 0;
	scanf("%d", &input);
	int y = input % 2;
	if (0 == y)
		printf("偶数");
	else
		printf("奇数");
	return 0;
}

//输出1~100的奇数
int main()
{
	int a = 0;
	while (a <= 100)
	{
		if (a % 2 == 1)
		{
			printf("%d\n", a);
			a++;
		}
		else
			a++;
	}
	return 0;
}
