#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[100001];
int main()
{
	scanf("%d",&g);
	g++;
	for(h=1;h<g;h++)
	{
		scanf("%d",&a);
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		for(b=0;b<a;b++)
		{
			scanf("%d",&c);
			k[b]-=c;
		}
		for(b=0,c=0,d=0,i=0;b<a;b++)
		{
			if(d+k[b]<0)
			{
				c+=d+k[b];
				i=b+1;
				d=0;
			}
			else
			{
				d+=k[b];
			}
		}
		if(c+d<0)
		{
			printf("Case %d: Not possible\n",h);
		}
		else
		{
			printf("Case %d: Possible from station %d\n",h,i+1);
		}
	}
	return 0;
}