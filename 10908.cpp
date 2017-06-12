#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,m;
	char k[21][21],l;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d%d%d",&a,&b,&g);
		printf("%d %d %d\n",a,b,g);
		for(c=0;c<a;c++)
		{
			scanf("%s",k[c]);
		}
		for(g;g>0;g--)
		{
			scanf("%d%d",&c,&d);
			c--;
			d--;
			l=k[c][d];
			for(e=1,i=0;c<a;c++,e++)
			{
				for(f=d,j=0;f<b;f++,j++)
				{
					if(k[c][f]!=l)
					{
						break;
					}
				}
				if(e>j)
				{
					if(j>i)
					{
						i=j;
					}
				}
				else
				{
					if(e>i)
					{
						i=e;
					}
				}
				if(j<i)
				{
					break;
				}
			}
			printf("%d\n",i);
		}
	}
	return 0;
}