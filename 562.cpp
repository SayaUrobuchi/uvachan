#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	bool k[50001];
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		k[0]=1;
		j=0;
		for(a=1;a<50001;a++)
		{
			k[a]=0;
		}
		scanf("%d",&g);
		for(i=0;g>0;g--)
		{
			scanf("%d",&a);
			i+=a;
			for(b=j;b>=0;b--)
			{
				if(k[b]==1)
				{
					if(a+b<50001)
					{
						c=a+b;
						k[c]=1;
						if(c>j)
						{
							j=c;
						}
					}
				}
			}
		}
		a=i/2+i%2;
		for(b=a;b<=j;b++)
		{
			if(k[b]==1)
			{
				printf("%d\n",b*2-i);
				break;
			}
		}
	}
	return 0;
}