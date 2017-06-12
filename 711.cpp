#include<stdio.h>
int l[60001];
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[7];
	l[0]=1;
	g=0;
	while(scanf("%d",&k[1])==1)
	{
		for(b=2,c=k[1];b<7;b++)
		{
			scanf("%d",&k[b]);
			c+=k[b]*b;
		}
		if(!c)
		{
			break;
		}
		printf("Collection #%d:\n",++g);
		if(c%2)
		{
			printf("Can't be divided.\n\n");
		}
		else
		{
			for(b=1,d=c/2+1;b<d;b++)
			{
				l[b]=0;
			}
			f=d;
			for(b=1;b<7;b++)
			{
				if(k[b])
				{
					for(d=0,e=k[b]*10;d<f;d++)
					{
						if(l[d]&&l[d]<e)
						{
							if(!l[d+b]||l[d+b]>l[d]+10)
							{
								l[d+b]=l[d]+10;
							}
						}
					}
					for(d=0;d<f;d++)
					{
						if(l[d])
						{
							l[d]=1;
						}
					}
				}
			}
			if(l[c/2])
			{
				printf("Can be divided.\n\n");
			}
			else
			{
				printf("Can't be divided.\n\n");
			}
		}
	}
	return 0;
}