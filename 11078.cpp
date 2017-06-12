#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&g);
		scanf("%d%d",&a,&b);
		i=a-b;
		if(a>b)
		{
			j=a;
		}
		else
		{
			j=b;
		}
		for(g-=2;g>0;g--)
		{
			scanf("%d",&a);
			b=j-a;
			if(b>i)
			{
				i=b;
			}
			if(a>j)
			{
				j=a;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}