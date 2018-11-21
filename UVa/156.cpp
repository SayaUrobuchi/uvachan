#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct abc
{
	char y[27],z[21];
}abc;
typedef struct bca
{
	char z[21];
}bca;
int a,b,c,d,e,f,g,h,i,j;
abc k[1001];
bca l[1000];
char m[27];
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).y,(*(abc*)q).y);
}
int bcaa(const void *p,const void *q)
{
	return strcmp((*(bca*)p).z,(*(bca*)q).z);
}
int main()
{
	for(a=0;a<26;a++)
	{
		m[a]=1;
	}
	m[a]=0;
	a=0;
	while(scanf("%s",k[a].z)==1)
	{
		if(!strcmp(k[a].z,"#"))
		{
			qsort(k,a,sizeof(abc),abcc);
			for(b=1,c=0,d=0;b<a;b++)
			{
				if(strcmp(k[b].y,k[d].y))
				{
					if(!(b-d-1))
					{
						strcpy(l[c++].z,k[d].z);
					}
					d=b;
				}
			}
			if(!(b-d-1))
			{
				strcpy(l[c++].z,k[d].z);
			}
			qsort(l,c,sizeof(bca),bcaa);
			for(b=0;b<c;b++)
			{
				printf("%s\n",l[b].z);
			}
			a=0;
		}
		else
		{
			b=strlen(k[a].z);
			strcpy(k[a].y,m);
			for(c=0;c<b;c++)
			{
				if(k[a].z[c]>90)
				{
					k[a].y[k[a].z[c]-97]++;
				}
				else
				{
					k[a].y[k[a].z[c]-65]++;
				}
			}
			a++;
		}
	}
	return 0;
}