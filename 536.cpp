#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct abc
{
	int z;
	struct abc *x,*y;
};
int a,b,c,d,e,f,g,h;
char i[27],j[91];
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
struct abc *p;
int main()
{
	while(scanf("%s%s",&i,&j)==2)
	{
		a=strlen(i);
		for(b=0;b<a;b++)
		{
			j[j[b]]=b;
		}
		p=(struct abc*)malloc(sizeof(abc));
		p->z=i[0];
		p->x=NULL;
		p->y=NULL;
		c=0;
		abcc(p,j[i[0]],27);
		bcaa(p);
		printf("\n");
	}
	return 0;
}