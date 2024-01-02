/*debug and optimize*/

/*strcpy函数的模拟实现*/

//较繁琐版本
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

//改进版本
void string_copy(char* dst, char* src)
{
	while (*dst++ = *src++);//非\0数值的ASCII码值为非0故循环继续
}

//对于指针有效性检查的优化
#include <stdio.h>
#include <assert.h>
int string_copy(char* dst, const char* src)//使用const修饰函数内不会修改的变量
{
	
	//断言:当括号内的条件不满足时报错，报错时会显示括号内的条件及断言语句的位置
	assert(src != NULL);
	assert(dst != NULL);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;//返回目标空间的起始地址
}

int main()
{
	char arr1[] = "sndeyakso";
	char arr2[] = "vp";
	printf("%s\n", string_copy(arr1, arr2));
	return 0;
}



/*strlen的模拟实现*/
int string_length(const char* const p)
{
	assert(p != NULL);
	int count = 0;
	while (*(p + (count++)) != '\0');
	return count - 1;
}


size_t __cdecl string_length(const char* const p)//size_t无符号整型
{
	assert(p != NULL);
	size_t count = 0;
	while (*(p + (count++)) != '\0');
	return count - 1;
}