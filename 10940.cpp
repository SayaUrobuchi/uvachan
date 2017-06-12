#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[20];
	for(a=0,b=1;b<524289;a++,b*=2)
	{
		k[a]=b;
	}
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		c=0;
		d=19;
		while(1)
		{
			b=c+d;
			b/=2;
			if(k[b]==a)
			{
				printf("%d\n",a);
				break;
			}
			else if(k[b]>a)
			{
				d=b-1;
				if(c>d)
				{
					printf("%d\n",(a-k[b-1])*2);
					break;
				}
			}
			else
			{
				c=b+1;
				if(c>d)
				{
					printf("%d\n",(a-k[b])*2);
					break;
				}
			}
		}
	}
	return 0;
}