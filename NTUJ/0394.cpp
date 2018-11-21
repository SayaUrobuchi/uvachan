#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct abc
{
	int w;
	struct abc *x,*y;
	char z[9];
};
int a,b,c,d,e,f,g,h;
char k[9],l[100];
int abcc(struct abc *p)
{
	if(p->x!=NULL)
	{
		abcc(p->x);
	}
	if(p->w>1)
	{
		c=0;
		printf("%s %d\n",p->z,p->w);
	}
	if(p->y!=NULL)
	{
		abcc(p->y);
	}
	return 0;
}
int main()
{
	struct abc *i,*j;
	while(scanf("%d", &g) == 1)
	{
		i=NULL;
		for(g;g>0;g--)
		{
			scanf("%s",l);
			a=strlen(l);
			for(b=0,c=0;b<a;b++)
			{
				if(l[b]=='-')
				{
					continue;
				}
				if(l[b]<65)
				{
					k[c++]=l[b];
					if(c==3)
					{
						k[c++]='-';
					}
				}
				else
				{
					if(l[b]<81)
					{
						l[b]-=59;
					}
					else
					{
						l[b]-=60;
					}
					l[b]/=3;
					k[c++]=l[b]+48;
					if(c==3)
					{
						k[c++]='-';
					}
				}
			}
			k[c]=0;
			j=i;
			if(j==NULL)
			{
				j=(abc*)malloc(sizeof(abc));
				j->w=1;
				j->x=NULL;
				j->y=NULL;
				strcpy(j->z,k);
				i=j;
			}
			else
			{
				while(1)
				{
					c=strcmp(k,j->z);
					if(!c)
					{
						j->w++;
						break;
					}
					else if(c<0)
					{
						if(j->x==NULL)
						{
							j->x=(abc*)malloc(sizeof(abc));
							j=j->x;
							j->w=1;
							j->x=NULL;
							j->y=NULL;
							strcpy(j->z,k);
							break;
						}
						j=j->x;
					}
					else
					{
						if(j->y==NULL)
						{
							j->y=(abc*)malloc(sizeof(abc));
							j=j->y;
							j->w=1;
							j->x=NULL;
							j->y=NULL;
							strcpy(j->z,k);
							break;
						}
						j=j->y;
					}
				}
			}
		}
		c=1;
		abcc(i);
		if(c)
		{
			printf("No duplicates.\n");
		}
	}
	return 0;
}
