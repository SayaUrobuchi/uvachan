#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[5],l[5];
	k[0]=1;
	for(a=1;a<5;a++)
	{
		k[a]=k[a-1]*10;
		l[a]=k[a]*6;
	}
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		c%=l[d];
		if(!c)
		{
			printf("%d\n",a%k[d]);
		}
		else if(c==1)
		{
			printf("%d\n",b%k[d]);
		}
		else
		{
			for(c;c>1;c--)
			{
				e=a+b;
				e%=k[d];
				a=b;
				b=e;
			}
			printf("%d\n",e);
		}
	}
	return 0;
}