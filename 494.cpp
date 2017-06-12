#include<stdio.h>
int main()
{
	char a;
	int b=0,c=0;
	while(scanf("%c",&a)==1)
	{
		if(a>64&&a<91||a>96&&a<123)
		{
			if(b==0)
			{
				b=1;
			}
		}
		else if(a==10)
		{
			if(b==1)
			{
				c++;
			}
			printf("%d\n",c);
			c=0;
			b=0;
		}
		else
		{
			if(b==1)
			{
				c++;
				b=0;
			}
		}
	}
	return 0;
}