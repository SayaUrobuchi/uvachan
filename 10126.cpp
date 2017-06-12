#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct abc
{
	char y[41];
}abc;
abc k[20000];
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).y,(*(abc*)q).y);
}
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char x, check;
	check = 0;
	while(scanf("%d",&a)==1)
	{
		if(check) printf("\n");
		check = 1;
		b=0;
		c=0;
		while(scanf("%c",&k[b].y[c])==1)
		{
			if(k[b].y[c]>64&&k[b].y[c]<91)
			{
				k[b].y[c]+=32;
				c++;
			}
			else if(k[b].y[c]>96&&k[b].y[c]<123)
			{
				c++;
			}
			else
			{
				if(c>0)
				{
					k[b].y[c]='\0';
					if(strcmp(k[b].y,"endoftext")==0)
					{
						break;
					}
					b++;
					c=0;
				}
			}
		}
		qsort(k,b,sizeof(abc),abcc);
		for(c=1,d=1,e=0;c<b;c++)
		{
			if(strcmp(k[c].y,k[c-1].y)==0)
			{
				d++;
			}
			else
			{
				if(d==a)
				{
					printf("%s\n",k[c-1].y);
					e++;
				}
				d=1;
			}
		}
		if(d==a)
		{
			printf("%s\n",k[c-1].y);
			e++;
		}
		if(e==0)
		{
			printf("There is no such word.\n");
		}
	}
	return 0;
}
