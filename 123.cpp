#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct abc
{
	char m[50],n,o,p;
}abc;
typedef struct aabc
{
	char y[11];
}aabc;
int abcc(const void *p,const void *q)
{
	return strcmp((*(aabc*)p).y,(*(aabc*)q).y);
}
int bcaa(const void *p,const void *q)
{
	int m;
	m=strcmp((*(abc*)p).m,(*(abc*)q).m);
	if(m==0)
	{
		if((*(abc*)p).n==(*(abc*)q).n)
		{
			return (*(abc*)p).o-(*(abc*)q).o;
		}
		else
		{
			return (*(abc*)p).n-(*(abc*)q).n;
		}
	}
	else
	{
		return m;
	}
}
int a,b,c,d,e,f,g,h,k;
char y[200][1001],z[1001];
aabc x[51];
abc w[300];
int main()
{
	int p,q;
	a=0;
	while(gets(x[a].y))
	{
		if(strcmp(x[a].y,"::")==0)
		{
			break;
		}
		a++;
	}
	qsort(x,a,sizeof(aabc),abcc);
	a--;
	b=0;
	k=0;
	while(gets(y[b]))
	{
		c=strlen(y[b]);
		for(d=0,e=0,q=0;d<c+1;d++)
		{
			if(y[b][d]==32||d==c)
			{
				if(e==0)
				{
					q++;
					continue;
				}
				z[e]='\0';
				f=0;
				g=a;
				while(1)
				{
					h=f+g;
					h/=2;
					p=strcmp(x[h].y,z);
					if(p==0)
					{
						break;
					}
					else if(p>0)
					{
						g=h-1;
						if(f>g)
						{
							strcpy(w[k].m,z);
							w[k].p=e;
							w[k].n=b;
							w[k++].o=q;
							break;
						}
					}
					else
					{
						f=h+1;
						if(f>g)
						{
							strcpy(w[k].m,z);
							w[k].p=e;
							w[k].n=b;
							w[k++].o=q;
							break;
						}
					}
				}
				e=0;
				q++;
			}
			else
			{
				if(y[b][d]<97)
				{
					y[b][d]+=32;
				}
				z[e++]=y[b][d];
			}
		}
		b++;
	}
	qsort(w,k,sizeof(abc),bcaa);
	for(b=0,e=0;b<k;b++)
	{
		strcpy(z,y[w[b].n]);
		for(c=0,d=0;z[c]!='\0';c++)
		{
			if(d==w[b].o)
			{
				for(e=0;w[b].m[e]!='\0';c++,e++)
				{
					z[c]-=32;
				}
				break;
			}
			if(z[c]==32)
			{
				d++;
			}
		}
		printf("%s\n",z);
	}
	return 0;
}