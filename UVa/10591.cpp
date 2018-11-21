#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[1000];
	scanf("%d",&g);
	for(h=1;h<=g;h++)
	{
		scanf("%d",&a);
		for(b=0;b<1000;b++)
		{
			k[b]=0;
		}
		if(a<1000)
		{
			k[a]=1;
		}
		for(b=a,c=0,f=0;;)
		{
			for(b;b>0;b/=10)
			{
				d=b%10;
				c+=d*d;
			}
			if(c==1)
			{
				break;
			}
			if(c<1000)
			{
				if(k[c]==1)
				{
					f=1;
					break;
				}
				else
				{
					k[c]=1;
				}
			}
			b=c;
			c=0;
		}
		if(f==1)
		{
			printf("Case #%d: %d is an Unhappy number.\n",h,a);
		}
		else
		{
			printf("Case #%d: %d is a Happy number.\n",h,a);
		}
	}
	return 0;
}