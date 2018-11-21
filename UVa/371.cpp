#include<stdio.h>
int main()
{
	unsigned long a,b,c,d,e,i,j;
	while(scanf("%lu%lu",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		if(a>b)
		{
			c=a;
			a=b;
			b=c;
		}
		b++;
		e=a;
		for(i=1,j=a;a<b;a++)
		{
			c=a;
			d=0;
			do
			{
				if(c%2==0)
				{
					c/=2;
				}
				else
				{
					c*=3;
					c++;
				}
				d++;
			}while(c>1);
			if(d>i)
			{
				i=d;
				j=a;
			}
		}
		printf("Between %lu and %lu, %lu generates the longest sequence of %lu values.\n",e,b-1,j,i);
	}
	return 0;
}