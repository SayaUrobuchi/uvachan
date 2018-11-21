#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sum(char* s1, char* s2)
{
	char *ptr;
	ptr = (char*)malloc(sizeof(char) * 1000001);
	sprintf(ptr, "((%s|%s)|(%s|%s))", s1, s1, s2, s2);
	return ptr;
}

char* pro(char* s1, char* s2)
{
	char *ptr;
	ptr = (char*)malloc(sizeof(char) * 1000001);
	sprintf(ptr, "((%s|%s)|(%s|%s))", s1, s2, s1, s2);
	return ptr;
}

char* recursion1(int now)
{
	char *ptr, A[10], B[10], *next, *temp, *temp2;
	if(!now)
	{
		ptr = (char*)malloc(sizeof(char) * 100);
		strcpy(ptr, "((A0|B0)|(A0|B0))");
		return ptr;
	}
	sprintf(A, "A%d", now);
	sprintf(B, "B%d", now);
	next = recursion1(now-1);
	temp = sum(A, B);
	temp2 = pro(temp, next);
	free(temp);
	free(next);
	temp = pro(A, B);
	ptr = sum(temp, temp2);
	free(temp);
	free(temp2);
	return ptr;
}

char* recursion2(int now)
{
	char *ptr, *next;
	ptr = (char*)malloc(sizeof(char) * 10001);
	if(!now)
	{
		strcpy(ptr, "((A0|B0)|(A0|B0))");
		return ptr;
	}
	next = recursion2(now-1);
	sprintf(ptr, "((A%d|B%d)|(%s|((A%d|A%d)|(B%d|B%d))))", now, now, next, now, now, now, now);
	free(next);
	return ptr;
}

int c(char *str)
{
	int i, res;
	for(i=0, res=0; str[i]; i++)
	{
		if(str[i] == '|')
		{
			res++;
		}
	}
	return res;
}

int main()
{
	int n;
	char *ptr;
	while(scanf("%d", &n) == 1)
	{
		ptr=recursion1(n);
		printf("ans1:\n%s\n%d NAND(s) used.\nans2:\n", ptr, c(ptr));
		free(ptr);
		ptr=recursion2(n);
		printf("%s\n%d NAND(s) used.\n", ptr, c(ptr));
	}
	return 0;
}
