#include<stdio.h>
int main()
{
	char a;
	int b=0;
	while(scanf("%c",&a)!=EOF)
	{
		if(a=='"')
		{
			if(b==0)
			{
				printf("``");
				b++;
			}
			else
			{
				printf("''");
				b--;
			}
		}
		else
		{
			printf("%c",a);
		}
	}
	return 0;
}