#include<stdio.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i[10001],j[10001];
char w;
struct abc *p;
struct abc
{
	int z;
	struct abc *x,*y;
};
int bcaa(struct abc *q,int m)
{
	m+=q->z;
	if(q->x==NULL&&q->y==NULL)
	{
		if(m<c||c==0)
		{
			c=m;
			d=q->z;
		}
		else if(m==c)
		{
			if(d>q->z)
			{
				d=q->z;
			}
		}
		return 0;
	}
	if(q->x!=NULL)
	{
		bcaa(q->x,m);
	}
	if(q->y!=NULL)
	{
		bcaa(q->y,m);
	}
	return 0;
}
int abcc(struct abc *q,int m,int n)
{
	struct abc *r;
	if(i[j[b-1]]>n)
	{
		b--;
		q->y=(struct abc*)malloc(sizeof(abc));
		r=q->y;
		r->z=j[b];
		r->x=NULL;
		r->y=NULL;
		abcc(r,n,i[j[b]]);
	}
	if(i[j[b-1]]>m)
	{
		b--;
		q->x=(struct abc*)malloc(sizeof(abc));
		r=q->x;
		r->z=j[b];
		r->x=NULL;
		r->y=NULL;
		abcc(r,m,i[j[b]]);
	}
	return 0;
}
int main()
{
	a=0;
	while(scanf("%d%c",&b,&w)==2)
	{
		i[b]=a;
		a++;
		if(w==10)
		{
			b=0;
			while(scanf("%d%c",&j[b],&w)==2)
			{
				if(w==10)
				{
					break;
				}
				b++;
			}
			p=(struct abc*)malloc(sizeof(abc));
			p->z=j[b];
			p->x=NULL;
			p->y=NULL;
			abcc(p,0,i[j[b]]);
			c=0;
			d=0;
			bcaa(p,0);
			printf("%d\n",d);
		}
	}
	return 0;
}