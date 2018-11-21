#include<stdio.h>
#include<string.h>
int i,j;
char k[26][9],l[9],m,n,o[9],y[26],z[9];
int abcc(int p)
{
	int q,w,x;
	if(p==j)
	{
		q=0;
		for(w=0;w<j;w++)
		{
			for(x=1;x<k[z[w]][0];x++)
			{
				if(y[k[z[w]][x]]-y[z[w]]>q)
				{
					q=y[k[z[w]][x]]-y[z[w]];
				}
				else if(y[z[w]]-y[k[z[w]][x]]>q)
				{
					q=y[z[w]]-y[k[z[w]][x]];
				}
			}
		}
		if(q<i||!i)
		{
			i=q;
			strcpy(o,l);
		}
		else if(q==i)
		{
			if(strcmp(o,l)>0)
			{
				strcpy(o,l);
			}
		}
		return 0;
	}
	for(w=0;w<j;w++)
	{
		if(!y[z[w]])
		{
			y[z[w]]=p+1;
			l[p]=z[w]+1;
			abcc(p+1);
			y[z[w]]=0;
		}
	}
	return 0;
}
int main()
{
	int a,b,c,d,e,f,g,h;
	while(scanf("%c",&m)==1)
	{
		if(m=='#')
		{
			break;
		}
		for(a=0;a<26;a++)
		{
			k[a][0]=1;
			y[a]=0;
		}
		i=0;
		j=0;
		n=m;
		n-=65;
		scanf("%c",&m);
		while(scanf("%c",&m)==1)
		{
			if(m==';')
			{
				scanf("%c",&n);
				n-=65;
				scanf("%c",&m);
			}
			else if(m==10)
			{
				break;
			}
			else
			{
				m-=65;
				k[n][k[n][0]++]=m;
				if(k[n][0]==2)
				{
					j++;
				}
				k[m][k[m][0]++]=n;
				if(k[m][0]==2)
				{
					j++;
				}
			}
		}
		for(a=0,b=0;a<26;a++)
		{
			if(k[a][0]>1)
			{
				z[b++]=a;
			}
		}
		l[j]=0;
		abcc(0);
		for(a=0;a<j;a++)
		{
			printf("%c ",o[a]+64);
		}
		printf("-> %d\n",i);
	}
	return 0;
}