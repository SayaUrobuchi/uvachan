#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d",&a,&b);
		for(i=0,j=0;b>0;b--)
		{
			scanf("%d",&c);
			if(c>i)
			{
				i=c;
			}
			if(c>j&&c<=a/2)
			{
				j=c;
			}
			d=a-c;
			if(d>i)
			{
				i=d;
			}
			if(d>j&&d<=a/2)
			{
				j=d;
			}
		}
		printf("%d %d\n",j,i);
	}
	return 0;
}