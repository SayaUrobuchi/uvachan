#include<stdio.h>
#include<string.h>
int main()
{
	char k[100],x;
	double y;
	int a,b,c,d,e,f;
	a=0;
	b=0;
	c=0;
	while(scanf("%c",&x)==1)
	{
		if(x==10)
		{
			if(c==0)
			{
				c=b;
				b=0;
				continue;
			}
			else
			{
				for(;;)
				{
					for(d=0;b>0;b/=10)
					{
						d+=b%10;
					}
					b=d;
					if(b<10)
					{
						break;
					}
				}
				for(;;)
				{
					for(d=0;c>0;c/=10)
					{
						d+=c%10;
					}
					c=d;
					if(c<10)
					{
						break;
					}
				}
				if(b>c)
				{
					y=c*100;
					y/=b;
					printf("%.2f %c\n",y,37);
				}
				else
				{
					y=b*100;
					y/=c;
					printf("%.2f %c\n",y,37);
				}
				c=0;
				b=0;
				continue;
			}
		}
		if(x>64&&x<91)
		{
			b+=x-64;
		}
		else if(x>96&&x<123)
		{
			b+=x-96;
		}
	}
	return 0;
}