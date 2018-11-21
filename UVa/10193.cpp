#include<stdio.h>
#include<string.h>
char x[31];
int c,e,f,g,h,i,j,k;
long long int a,b,d;
int main()
{
	scanf("%d%c",&h,&x[0]);
	for(g=1;g<=h;g++)
	{
		gets(x);
		i=strlen(x);
		for(a=0,c=i-1,d=1;c>=0;c--,d*=2)
		{
			x[c]-=48;
			a+=d*x[c];
		}
		gets(x);
		i=strlen(x);
		for(b=0,c=i-1,d=1;c>=0;c--,d*=2)
		{
			x[c]-=48;
			b+=d*x[c];
		}
		for(;;)
		{
			if(a>b)
			{
				a%=b;
				if(a<2)
				{
					c=a;
					break;
				}
			}
			else
			{
				b%=a;
				if(b<2)
				{
					c=b;
					break;
				}
			}
		}
		if(c==1)
		{
			printf("Pair #%d: Love is not all you need!\n",g);
		}
		else
		{
			printf("Pair #%d: All you need is love!\n",g);
		}
	}
	return 0;
}