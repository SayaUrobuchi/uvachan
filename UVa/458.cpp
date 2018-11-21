#include<stdio.h>
int main()
{
	char a;
	while(scanf("%c",&a)==1)
	{
		if(a==10)
		{
			printf("\n");
		}
		else
		{
			printf("%c",a-7);
		}
	}
	return 0;
}