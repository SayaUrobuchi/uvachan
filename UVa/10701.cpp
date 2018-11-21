#include<stdio.h>
#include<stdlib.h>
struct abc
{
	char z;
	struct abc *x,*y;
};
int a,b,c,d,e,f,g,h;
char i[53],j[123];
struct abc *p;
int abcc(struct abc *q,char k,char w)
{
	struct abc *m;
	if(j[i[c+1]]<k)
	{
		c++;
		q->x=(struct abc*)malloc(sizeof(abc));
		m=q->x;
		m->z=i[c];
		m->x=NULL;
		m->y=NULL;
		abcc(m,j[i[c]],k);
	}
	if(j[i[c+1]]<w)
	{
		c++;
		q->y=(struct abc*)malloc(sizeof(abc));
		m=q->y;
		m->z=i[c];
		m->x=NULL;
		m->y=NULL;
		abcc(m,j[i[c]],w);
	}
	return 0;
}
int bcaa(struct abc *q)
{
	if(q->x!=NULL)
	{
		bcaa(q->x);
	}
	if(q->y!=NULL)
	{
		bcaa(q->y);
	}
	printf("%c",q->z);
	return 0;
}
int main()
{
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&a);
		scanf("%s%s",&i,&j);
		for(b=0;b<a;b++)
		{
			j[j[b]]=b;
		}
		c=0;
		p=(struct abc*)malloc(sizeof(abc));
		p->z=i[0];
		p->x=NULL;
		p->y=NULL;
		abcc(p,j[i[0]],53);
		bcaa(p);
		printf("\n");
	}
	return 0;
}