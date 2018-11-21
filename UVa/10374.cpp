#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	int i;
	char j[2][81];
}abc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).j[0],(*(abc*)q).j[0]);
}
int main()
{
	int a,b,c,d,e,f,g,h;
	abc k[20];
	char x,y[81], check;
	check = 0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		scanf("%d",&a);
		gets(y);
		for(b=0;b<a;b++)
		{
			gets(k[b].j[0]);
			gets(k[b].j[1]);
			k[b].i=0;
		}
		qsort(k,a,sizeof(abc),abcc);
		a--;
		scanf("%d",&b);
		gets(y);
		for(b;b>0;b--)
		{
			gets(y);
			c=0;
			d=a;
			while(1)
			{
				e=c+d;
				e/=2;
				f=strcmp(y,k[e].j[0]);
				if(f==0)
				{
					k[e].i++;
					break;
				}
				else if(f<0)
				{
					d=e-1;
					if(c>d)
					{
						break;
					}
				}
				else
				{
					c=e+1;
					if(c>d)
					{
						break;
					}
				}
			}
		}
		for(a+=1,b=0,c=0,d=0,e=0;b<a;b++)
		{
			if(k[b].i>c)
			{
				e=0;
				c=k[b].i;
				d=b;
			}
			else if(k[b].i==c)
			{
				e=1;
			}
		}
		if(e==1)
		{
			printf("tie\n");
		}
		else
		{
			printf("%s\n",k[d].j[1]);
		}
	}
	return 0;
}
