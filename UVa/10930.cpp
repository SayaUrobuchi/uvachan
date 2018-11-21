#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j[30];
	char k[30001];
	k[0]=1;
	h=0;
	d=0;
	while(scanf("%d",&g)==1)
	{
		for(d;d>0;d--)
		{
			k[d]=0;
		}
		for(a=0,d=0;a<g;a++)
		{
			scanf("%d",&j[a]);
			for(c=d;c>-1;c--)
			{
				if(k[c]>0)
				{
					b=j[a]+c;
					if(k[b]<k[c]+1)
					{
						k[b]=k[c]+1;
						if(b>d)
						{
							d=b;
						}
					}
				}
			}
		}
		printf("Case #%d:",++h);
		for(a=0,b=0,c=0;a<g;a++)
		{
			printf(" %d",j[a]);
			if(k[j[a]]>2)
			{
				b=1;
			}
			if(j[a]<=c)
			{
				b=1;
			}
			c=j[a];
		}
		printf("\n");
		if(b==1)
		{
			printf("This is not an A-sequence.\n");
		}
		else
		{
			printf("This is an A-sequence.\n");
		}
	}
	return 0;
}