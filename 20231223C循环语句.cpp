/*whileѭ��*/
int main()
{
	int i = 0;//1.ѭ����ʼ��
	while (i<10)//2.ѭ�����жϲ���
	{
		if (i == 5)
			continue;//��������ѭ����ֱ�ӽ���while���жϲ����ж��Ƿ���һ��ѭ��
			break;//������ֹ��ѭ��
		printf("%d", i);
		i++;//3.ѭ���ĵ�������
	}
	
	return 0
}

int main()
{
	char input = 0;
	//getchar��ȡ���̵����룬����ֵΪһ���ַ���ASCII��ֵ����EOF����ȡ������ļ�������
	//��ʹ��getcharʱʹ�����ͱ���int����
	//EOFΪ�ļ��Ľ�����־��������Ϊ-1
	//������A��س��󣬻����������A\n��getchar�����ν�A��\n��ȡ
	while ((input = getchar()) != EOF)
		putchar(input);//���һ���ַ�
	//ctrl+zʹgetchar��ȡ�����һ��EOF������
	return 0;
}

int main()
{
	printf("please enter password:)");
	int pw[20] = { 0 };
	scanf("%s", pw);
	//����������е��ַ�
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

/*forѭ��*/
//forѭ���Ļ����﷨
int main()
{
	int fi = 0;
	//for��ں�ֱ�Ӱ�����ʼ�����жϲ��֡��������֣����Էֺ����
	for (fi = 1; fi < 10; fi++)//����д������ҿ�
	{
		//������Ϊѭ�����
		if (5 == i)
			continue;
		//��ʱ��������ѭ���������ֵ��������Ѿ���ɣ��ʲ��������ѭ��
		printf("%d", fi);
	}
	return 0;
}

/*do whileѭ��*/
int main()
{
	int i = 1;
	//ѭ��������ִ��һ��
	do
	{
		printf("%d\n", i);
		i++;
	} while(i <= 0);
	
	return 0;
}

//��ϰ��
//1.���������n������n!����ֵ
int main()
{
	int input = 0;
	printf("������Ҫ����׳˵���(�Ǹ�����):)");
	scanf("%d", &input);
	if (0 == input)
	{
		printf("0�Ľ׳�Ϊ1");
	}
	else if (input > 0)
	{
		int cal = 0;
		int result = 1;
		for (cal = input; cal > 0; cal--)
		{
			result *= cal;
		}
		printf("%d�Ľ׳�Ϊ%d", input, result);
	}
	else
		printf("�������");


	return 0;
}
