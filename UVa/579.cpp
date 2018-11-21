#include<stdio.h>
int main()
{
	char a;
	int b=0;
	double c=0,d=0;
	while(scanf("%c",&a)==1)
	{
		a-=48;
		if(a==10)
		{
			b=1;
		}
		else if(a>=0&&a<10&&b==0)
		{
			c*=10;
			c+=a;
		}
		else if(a>=0&&a<10&&b>=1)
		{
			d*=10;
			d+=a;
			b++;
		}
		if(b==3)
		{
			if(c==0&&d==0)
			{
				break;
			}
			else
			{
				c*=30;
				d*=0.5;
				c+=d;
				d*=12;
				c-=d;
				if(c<0)
				{
					c*=-1;
				}
				if(c>180)
				{
					c=360-c;
				}
				printf("%0.3f\n",c);
				b=0;
				c=0;
				d=0;
			}
		}
	}
	return 0;
}
