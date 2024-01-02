/*debug and optimize*/

/*strcpy������ģ��ʵ��*/

//�Ϸ����汾
void string_copy(char* dst, char* src)
{
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = *src;
}

//�Ľ��汾
void string_copy(char* dst, char* src)
{
	while (*dst++ = *src++);//��\0��ֵ��ASCII��ֵΪ��0��ѭ������
}

//����ָ����Ч�Լ����Ż�
#include <stdio.h>
#include <assert.h>
int string_copy(char* dst, const char* src)//ʹ��const���κ����ڲ����޸ĵı���
{
	
	//����:�������ڵ�����������ʱ��������ʱ����ʾ�����ڵ���������������λ��
	assert(src != NULL);
	assert(dst != NULL);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;//����Ŀ��ռ����ʼ��ַ
}

int main()
{
	char arr1[] = "sndeyakso";
	char arr2[] = "vp";
	printf("%s\n", string_copy(arr1, arr2));
	return 0;
}



/*strlen��ģ��ʵ��*/
int string_length(const char* const p)
{
	assert(p != NULL);
	int count = 0;
	while (*(p + (count++)) != '\0');
	return count - 1;
}


size_t __cdecl string_length(const char* const p)//size_t�޷�������
{
	assert(p != NULL);
	size_t count = 0;
	while (*(p + (count++)) != '\0');
	return count - 1;
}