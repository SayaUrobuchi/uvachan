#include<stdio.h>
int main()
{
	char x;
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d%c",&a,&x)==2)
	{
		if(x==32)
		{
			scanf("%d",&b);
			if(a<0&&b<0)
			{
				a*=-1;
				b*=-1;
				a+=2;
				b+=2;
				if(a%4==0&&b%4==0)
				{
					c=2;
				}
				else if(a%4==0||b%4==0)
				{
					c=1;
				}
				else
				{
					c=0;
				}
				a/=4;
				b/=4;
				if(a==b&&c>0)
				{
					printf("1\n");
				}
				else
				{
					c/=2;
					printf("%d\n",a-b+c);
				}
			}
			else if(a>=0&&b>=0)
			{
				a+=2;
				b+=2;
				if(a%4==0&&b%4==0)
				{
					c=2;
				}
				else if(a%4==0||b%4==0)
				{
					c=1;
				}
				else
				{
					c=0;
				}
				a/=4;
				b/=4;
				if(a==b&&c>0)
				{
					printf("1\n");
				}
				else
				{
					c/=2;
					printf("%d\n",b-a+c);
				}
			}
			else
			{
				a*=-1;
				a+=2;
				a/=4;
				b+=2;
				b/=4;
				printf("%d\n",a+b);
			}
		}
		else
		{
			b=a;
			if(b<0)
			{
				b*=-1;
			}
			if(b%2==1)
			{
				c=b;
				b++;
				b/=2;
				c--;
				c/=2;
				if(a<0)
				{
					printf("%d %d\n",c,b);
				}
				else
				{
					printf("%d %d\n",b,c);
				}
			}
			else
			{
				if(b==0)
				{
					printf("0 0\n");
				}
				else
				{
					b/=2;
					if(b%2==1)
					{
						printf("Bachelor Number.\n");
					}
					else
					{
						c=b/2+1;
						d=b/2-1;
						if(a<0)
						{
							printf("%d %d\n",d,c);
						}
						else
						{
							printf("%d %d\n",c,d);
						}
					}
				}
			}
		}
	}
	return 0;
}