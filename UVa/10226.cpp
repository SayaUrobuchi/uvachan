#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct abc
{
	struct abc *x,*y;
	char j[31];
	int i;
};
int a,b,c,d,e,f,g,h;
char z[31], check;
int abcc(struct abc *p)
{
	double q;
	if(p->x!=NULL)
	{
		abcc(p->x);
	}
	q=p->i;
	q*=100;
	q/=b;
	printf("%s %.4f\n",p->j,q);
	if(p->y!=NULL)
	{
		abcc(p->y);
	}
	return 0;
}
int main()
{
	struct abc *p,*q;
	check = 0;
	scanf("%d",&h);
	gets(z);
	gets(z);
	for(h;h>0;h--)
	{
		if(check) printf("\n");
		check = 1;
		gets(z);
		p=(abc*)malloc(sizeof(abc));
		p->i=1;
		strcpy(p->j,z);
		p->x=NULL;
		p->y=NULL;
		b=1;
		while(gets(z))
		{
			if(!strcmp(z,""))
			{
				break;
			}
			b++;
			q=p;
			while(1)
			{
				a=strcmp(q->j,z);
				if(!a)
				{
					q->i++;
					break;
				}
				else if(a>0)
				{
					if(q->x==NULL)
					{
						q->x=(abc*)malloc(sizeof(abc));
						q=q->x;
						strcpy(q->j,z);
						q->i=1;
						q->x=NULL;
						q->y=NULL;
						break;
					}
					else
					{
						q=q->x;
					}
				}
				else
				{
					if(q->y==NULL)
					{
						q->y=(abc*)malloc(sizeof(abc));
						q=q->y;
						strcpy(q->j,z);
						q->i=1;
						q->x=NULL;
						q->y=NULL;
						break;
					}
					else
					{
						q=q->y;
					}
				}
			}
		}
		abcc(p);
	}
	return 0;
}
