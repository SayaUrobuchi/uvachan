#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h,i,j,w[20][20];
bool z[20];
char k[20],x[21],y,l[2],m[123];
int abcc(const void *p,const void *q)
{
	return *(char*)p-*(char*)q;
}
int abc()
{
	int p;
	if(b==a)
	{
		x[b]='\0';
		printf("%s\n",x);
		return 0;
	}
	for(p=0;p<a;p++)
	{
		if(z[p])
		{
			for(c=1;c<w[p][0];c++)
			{
				if(z[w[p][c]])
				{
					break;
				}
			}
			if(c!=w[p][0])
			{
				continue;
			}
			x[b++]=k[p];
			z[p]=0;
			abc();
			z[p]=1;
			b--;
		}
	}
	return 0;
}
int main()
{
	int s;
	a=0;
	s=0;
	while(scanf("%s%c",x,&y)==2)
	{
		k[a++]=x[0];
		if(y==10)
		{
			qsort(k,a,sizeof(char),abcc);
			for(b=0;b<a;b++)
			{
				m[k[b]]=b;
				w[b][0]=1;
				z[b]=1;
			}
			while(scanf("%s%s%c",x,l,&y)==3)
			{
				w[m[l[0]]][w[m[l[0]]][0]]=m[x[0]];
				w[m[l[0]]][0]++;
				if(y==10)
				{
					break;
				}
			}
			if(s)
			{
				printf("\n");
			}
			s=1;
			b=0;
			abc();
			a=0;
		}
	}
	return 0;
}