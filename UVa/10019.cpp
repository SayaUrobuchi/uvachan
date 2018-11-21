#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&a);
		for(b=a,c=0;b>0;b/=2)
		{
			c+=b%2;
		}
		printf("%d ",c);
		for(b=a,c=0,d=1;b>0;b/=10,d*=16)
		{
			c+=(b%10)*d;
		}
		for(b=c,c=0;b>0;b/=2)
		{
			c+=b%2;
		}
		printf("%d\n",c);
	}
	return 0;
}