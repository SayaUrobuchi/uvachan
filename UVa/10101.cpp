#include<stdio.h>
int main()
{
	long long a,b;
	int c,d,e,f,g,h,i,j,k;
	h=0;
	while(scanf("%lld",&a)==1)
	{
		printf("%4d.",++h);
		d=0;
		b=a/10000000;
		if(b>0)
		{
			c=b/10000000;
			if(c>0)
			{
				printf(" %d kuti",c);
			}
			b%=10000000;
			c=b/100000;
			if(c>0)
			{
				printf(" %d lakh",c);
			}
			b%=100000;
			c=b/1000;
			if(c>0)
			{
				printf(" %d hajar",c);
			}
			b%=1000;
			c=b/100;
			if(c>0)
			{
				printf(" %d shata",c);
			}
			b%=100;
			if(b>0)
			{
				printf(" %d",b);
			}
			printf(" kuti");
			d=1;
		}
		a%=10000000;
		c=a/100000;
		if(c>0)
		{
			printf(" %d lakh",c);
			d=1;
		}
		a%=100000;
		c=a/1000;
		if(c>0)
		{
			printf(" %d hajar",c);
			d=1;
		}
		a%=1000;
		c=a/100;
		if(c>0)
		{
			printf(" %d shata",c);
			d=1;
		}
		a%=100;
		if(a>0||d==0)
		{
			printf(" %d",a);
		}
		printf("\n");
	}
	return 0;
}