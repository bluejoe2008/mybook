#include "stdafx.h"
#include <cstdio>
#include <cctype>

int main()
{
	char src[] = "Hello World!";
	char * cp = src;
	while(*cp)
	{
		//Сд��ĸת�ɴ�д
		if(islower(*cp))
			printf("%c", toupper(*cp));
		else 
		{
			//��д��ĸת��Сд
			if(isupper(*cp))
				printf("%c", tolower(*cp));
			//�����ַ�
			else
				printf("@");
		}

		cp++;
	}

	return 0;
}