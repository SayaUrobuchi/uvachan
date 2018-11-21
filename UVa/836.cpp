#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[50][51],x[2], check;
	check = 0;
	scanf("%d",&h);
	gets(x);
	gets(x);
	while(gets(k[0]))
	{
		if(check) printf("\n");
		check = 1;
		a=strlen(k[0]);
		for(b=1;b<a;b++)
		{
			gets(k[b]);
		}
		for(b=0,i=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				if(k[b][c]==49)
				{
					for(d=c,g=1000,j=0;d<a;d++)
					{
						if(k[b][d]==48)
						{
							break;
						}
						for(f=b+1;f<a;f++)
						{
							if(k[f][d]==48)
							{
								break;
							}
						}
						e=f-b;
						if(e<g)
						{
							g=e;
						}
						else
						{
							e=g;
						}
						e*=d-c+1;
						if(e>j)
						{
							j=e;
						}
					}
					if(j>i)
					{
						i=j;
					}
				}
			}
		}
		printf("%d\n",i);
		gets(x);
	}
	return 0;
}
