//C�����з�0Ϊ�棬0Ϊ�٣���ֵĬ�����1
int main()
{
	int a = 0;
	scanf("%d", &a);

	if (0 == a)//������������߿ɱ������
		printf("a=0");
	else if (a < 5 && a > 0)
	//�˴�����д��0<a<5�������������ж�0<a��ȡ�漴���1������������1<5������
		printf("0<a<5");
	else if (a < 0)//��д���else if
	{
		printf("a<0");
		printf("!!")//if��else����ִ��һ����䣬���ڶ���Ӧ�������
	}
	else//�ɲ�д
		printf("a<0��a>5");
	//���޴�����ʱ��else��Ӧ�������if���(����else)

	return 0;
}

//�����֧������switch����
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)//���ͱ��ʽ�����n�������n�����
	{
	case 1://case n��Ϊ��ڣ�n����Ϊ���ͳ������ʽ
		printf("monday\n");
		break;//break��Ϊ����
	case 2:
		printf("tuesday\n");
		break;
	case 5:
		printf("friday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");
		break;//break��Ϊ����ӣ������������
	default://����case��������Ĭ�Ͻ�������
		printf("error");
		break;
	}
	return 0;
}

//�ж�����ż��
int main()
{
	int input = 0;
	scanf("%d", &input);
	int y = input % 2;
	if (0 == y)
		printf("ż��");
	else
		printf("����");
	return 0;
}

//���1~100������
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
