/*while循环*/
int main()
{
	int i = 0;//1.循环初始化
	while (i<10)//2.循环的判断部分
	{
		if (i == 5)
			continue;//跳出本轮循环，直接进入while的判断部分判断是否下一轮循环
			break;//永久终止该循环
		printf("%d", i);
		i++;//3.循环的调整部分
	}
	
	return 0
}

int main()
{
	char input = 0;
	//getchar获取键盘的输入，返回值为一个字符的ASCII码值或者EOF（读取错误或文件结束）
	//故使用getchar时使用整型变量int储存
	//EOF为文件的结束标志，本质上为-1
	//当输入A与回车后，缓冲区存放了A\n，getchar会依次将A与\n读取
	while ((input = getchar()) != EOF)
		putchar(input);//输出一个字符
	//ctrl+z使getchar读取并输出一个EOF而结束
	return 0;
}

int main()
{
	printf("please enter password:)");
	int pw[20] = { 0 };
	scanf("%s", pw);
	//清除缓冲区中的字符
	while ((getchar()) != '\n')
	{
		;
	}
	printf("confirm?(Y/N)");
	if ((getchar()) == 'Y')
		printf("confirm successfully");
	else
		printf("confirm failed");

	return 0;
}

/*for循环*/
//for循环的基本语法
int main()
{
	int fi = 0;
	//for后口号直接包括初始化、判断部分、调整部分，并以分号相隔
	for (fi = 1; fi < 10; fi++)//建议写法左闭右开
	{
		//括号内为循环语句
		if (5 == i)
			continue;
		//此时跳过本轮循环，但此轮调整部分已经完成，故不会出现死循环
		printf("%d", fi);
	}
	return 0;
}

/*do while循环*/
int main()
{
	int i = 1;
	//循环体至少执行一次
	do
	{
		printf("%d\n", i);
		i++;
	} while(i <= 0);
	
	return 0;
}

//练习题
//1.对于输入的n，计算n!的数值
int main()
{
	int input = 0;
	printf("输入需要计算阶乘的数(非负整数):)");
	scanf("%d", &input);
	if (0 == input)
	{
		printf("0的阶乘为1");
	}
	else if (input > 0)
	{
		int cal = 0;
		int result = 1;
		for (cal = input; cal > 0; cal--)
		{
			result *= cal;
		}
		printf("%d的阶乘为%d", input, result);
	}
	else
		printf("输入错误");


	return 0;
}
