#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int abcc(const void *p,const void *q)
{
	return *(char*)p-*(char*)q;
}
int main()
{
	int a,b,c,d,e,f,g,h;
	char k[40][17],x[17],y[50],z;
	scanf("%d",&h);
	gets(x);
	a=0;
	while(scanf("%s%c",k[a++],&z)==2)
	{
		if(z==10)
		{
			f=0;
			gets(x);
			b=strlen(x);
			for(c=0;c<a;c++)
			{
				if(strlen(k[c])==b)
				{
					d=x[0]-k[c][0];
					if(d>0)
					{
						d-=26;
					}
					for(e=0;e<b;e++)
					{
						k[c][e]+=d;
						if(k[c][e]<97)
						{
							k[c][e]+=26;
						}
					}
					if(strcmp(x,k[c])==0)
					{
						y[f++]=d*-1+97;
					}
				}
			}
			qsort(y,f,sizeof(char),abcc);
			printf("%c",y[0]);
			for(a=1;a<f;a++)
			{
				if(y[a]!=y[a-1])
				{
					printf("%c",y[a]);
				}
			}
			printf("\n");
			a=0;
		}
	}
	return 0;
}