#include <stdio.h>

char str[][5] = {"�s", "��", "�L", "��", "�v", "��", "��", "�m", "��", "�h"};  // �B�B�աB�a�B�U�B��

int main()
{
	int n, m, f;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			printf("�s\n");
			continue; 
		}
		f = 0;
		if(n >= 100000000)
		{
			f = 1;
			if(n >= 1000000000)
			{
				m = n / 1000000000;
				n %= 1000000000;
				printf("%s%s", str[m], "�B");
			}
			m = n / 100000000;
			n %= 100000000;
			if(m)
			{
				printf("%s", str[m]);
			}
			printf("%s", "��");
		}
		if(n >= 10000 && n)
		{
			if(n >= 10000000)
			{
				m = n / 10000000;
				n %= 10000000;
				printf("%s%s", str[m], "�a");
				f = 1;
			}
			else if(f == 1 && n)
			{
				printf("�s");
				f = 2; 
			}
			if(n >= 1000000)
			{
				m = n / 1000000;
				n %= 1000000;
				printf("%s%s", str[m], "��");
				f = 1;
			}
			else if(f == 1 && n)
			{
				printf("�s");
				f = 2; 
			}
			if(n >= 100000)
			{
				m = n / 100000;
				n %= 100000;
				printf("%s%s", str[m], "�B");
				f = 1;
			}
			else if(f == 1 && n)
			{
				printf("�s");
				f = 2; 
			}
			if(n >= 10000)
			{
				m = n / 10000;
				n %= 10000;
				printf("%s%s", str[m], "");
			}
			printf("%s", "�U");
			f = 1;
		}
		f = !!f;
		if(n >= 1000)
		{
			m = n / 1000;
			n %= 1000;
			printf("%s%s", str[m], "�a");
		}
		else if(f == 1 && n)
		{
			printf("�s");
			f = 2; 
		}
		if(n >= 100)
		{
			m = n / 100;
			n %= 100;
			printf("%s%s", str[m], "��");
		}
		else if(f == 1 && n)
		{
			printf("�s");
			f = 2; 
		}
		if(n >= 10)
		{
			m = n / 10;
			n %= 10;
			printf("%s%s", str[m], "�B");
		}
		else if(f == 1 && n)
		{
			printf("�s");
			f = 2; 
		}
		if(n >= 1)
		{
			m = n / 1;
			n %= 1;
			printf("%s%s", str[m], "");
		}
		printf("\n");
	}
	return 0;
}
