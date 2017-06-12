#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool m[21][21];
int a,b,c,d,e,f,g,h,p;
char k[21][21],x,y[401];
typedef struct abc
{
	int i;
	char z[401];
}abc;
abc j[23000];
int abcc(char r)
{
	if(d>1)
	{
		y[d+1]='\0';
		strcpy(j[e].z,y);
		j[e].i=d;
		e++;
	}
	if(b>0)
	{
		if(k[b-1][c]>r)
		{
			d++;
			b--;
			y[d]=k[b][c];
			abcc(k[b][c]);
			b++;
			d--;
		}
		if(c>0)
		{
			if(k[b-1][c-1]>r)
			{
				d++;
				b--;
				c--;
				y[d]=k[b][c];
				abcc(k[b][c]);
				b++;
				c++;
				d--;
			}
		}
		if(c<a)
		{
			if(k[b-1][c+1]>r)
			{
				d++;
				b--;
				c++;
				y[d]=k[b][c];
				abcc(k[b][c]);
				b++;
				c--;
				d--;
			}
		}
	}
	if(c>0)
	{
		if(k[b][c-1]>r)
		{
			d++;
			c--;
			y[d]=k[b][c];
			abcc(k[b][c]);
			c++;
			d--;
		}
	}
	if(c<a)
	{
		if(k[b][c+1]>r)
		{
			d++;
			c++;
			y[d]=k[b][c];
			abcc(k[b][c]);
			c--;
			d--;
		}
	}
	if(b<a)
	{
		if(k[b+1][c]>r)
		{
			d++;
			b++;
			y[d]=k[b][c];
			abcc(k[b][c]);
			b--;
			d--;
		}
		if(c>0)
		{
			if(k[b+1][c-1]>r)
			{
				d++;
				b++;
				c--;
				y[d]=k[b][c];
				abcc(k[b][c]);
				b--;
				c++;
				d--;
			}
		}
		if(c<a)
		{
			if(k[b+1][c+1]>r)
			{
				d++;
				b++;
				c++;
				y[d]=k[b][c];
				abcc(k[b][c]);
				b--;
				c--;
				d--;
			}
		}
	}
	return 0;
}
int bcaa(const void *s,const void *t)
{
	if((*(abc*)s).i<(*(abc*)t).i)
	{
		return -1;
	}
	else if((*(abc*)s).i==(*(abc*)t).i)
	{
		int q;
		for(q=0;q<=(*(abc*)s).i;q++)
		{
			if((*(abc*)s).z[q]<(*(abc*)t).z[q])
			{
				return -1;
			}
			else if((*(abc*)s).z[q]>(*(abc*)t).z[q])
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int s;
	s=0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		scanf("%d%c",&a,&x);
		for(b=0;b<a;b++)
		{
			gets(k[b]);
			for(c=0;c<a;c++)
			{
				m[b][c]=0;
			}
		}
		a--;
		for(b=0,e=0;b<=a;b++)
		{
			for(c=0;c<=a;c++)
			{
				d=0;
				y[0]=k[b][c];
				abcc(k[b][c]);
			}
		}
		if(e==0)
		{
			continue;
		}
		qsort(j,e,sizeof(abc),bcaa);
		printf("%s\n",j[0].z);
		strcpy(y,j[0].z);
		for(b=1;b<e;b++)
		{
			if(strcmp(j[b].z,y)==0)
			{
				continue;
			}
			strcpy(y,j[b].z);
			printf("%s\n",y);
		}
	}
	return 0;
}