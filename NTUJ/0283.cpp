#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[10000];
	h=0;
	while(scanf("%d",&g)==1)
	{
		if(g==0)
		{
			break;
		}
		for(a=1;a<10000;a++)
		{
			k[a]=1;
		}
		h++;
		printf("Case #%d:\n",h);
		scanf("%d%d%d",&a,&b,&c);
		if(g==1)
		{
			printf("The actual year is %d.\n\n",a);
			continue;
		}
		c-=b;
		for(a;a<10000;a+=c)
		{
			k[a]++;
		}
		for(d=0,i=2,j=10000;i<=g;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(d==0)
			{
				c-=b;
				for(b=0;a<10000;a+=c)
				{
					if(k[a]==i)
					{
						k[a]++;
						if(b==0)
						{
							b++;
							if(i==g)
							{
								j=a;
								break;
							}
						}
					}
				}
				if(b==0)
				{
					d=1;
				}
			}
		}
		if(d==1)
		{
			printf("Unknown bugs detected.\n\n");
		}
		else
		{
			printf("The actual year is %d.\n\n",j);
		}
	}
	return 0;
}
