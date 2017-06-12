#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char y[21];
	int z;
}abc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).y,(*(abc*)q).y);
}
int main()
{
	int a,b,c,d,e,f,g,h,j[100];
	bool i[100][100];
	char k[100][21],w[21];
	abc x[100];
	h=0;
	while(scanf("%d",&a)==1)
	{
		for(b=0;b<a;b++)
		{
			for(c=0;c<a;c++)
			{
				i[b][c]=0;
			}
			scanf("%s",&k[b]);
			x[b].z=b;
			strcpy(x[b].y,k[b]);
		}
		qsort(x,a,sizeof(abc),abcc);
		scanf("%d",&b);
		for(b;b>0;b--)
		{
			scanf("%s",&w);
			c=0;
			d=a-1;
			while(1)
			{
				e=c+d;
				e/=2;
				f=strcmp(x[e].y,w);
				if(f==0)
				{
					g=x[e].z;
					break;
				}
				else if(f<0)
				{
					c=e+1;
				}
				else
				{
					d=e-1;
				}
			}
			scanf("%s",&w);
			c=0;
			d=a-1;
			while(1)
			{
				e=c+d;
				e/=2;
				f=strcmp(x[e].y,w);
				if(f==0)
				{
					e=x[e].z;
					break;
				}
				else if(f<0)
				{
					c=e+1;
				}
				else
				{
					d=e-1;
				}
			}
			i[g][e]=1;
		}
		for(b=0;b<a;b++)
		{
			j[b]=0;
			for(c=0;c<a;c++)
			{
				j[b]+=i[c][b];
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:",++h);
		for(b=0;b<a;b++)
		{
			if(j[b]==0)
			{
				printf(" %s",k[b]);
				j[b]--;
				for(c=0;c<a;c++)
				{
					j[c]-=i[b][c];
					i[b][c]=0;
				}
				b=-1;
			}
		}
		printf(".\n\n");
	}
	return 0;
}