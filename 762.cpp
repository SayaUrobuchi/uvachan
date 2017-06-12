#include<stdio.h>
#include<string.h>
int a,b,c,d,e,f,g,h,i,j[1000],x[1000][501],y[1000];
char k[1000][3],w[3],z[3], check;
bool l[1000];
int main()
{
	check = 0;
	while(scanf("%d",&h)==1)
	{
		if(check) printf("\n");
		check = 1;
		a=0;
		for(h;h>0;h--)
		{
			scanf("%s%s",w,z);
			for(b=0;b<a;b++)
			{
				if(!strcmp(k[b],w))
				{
					break;
				}
			}
			if(b==a)
			{
				strcpy(k[a],w);
				l[a]=0;
				x[a++][0]=1;
			}
			for(c=0;c<a;c++)
			{
				if(!strcmp(k[c],z))
				{
					break;
				}
			}
			if(c==a)
			{
				strcpy(k[a],z);
				l[a]=0;
				x[a++][0]=1;
			}
			x[b][x[b][0]++]=c;
			x[c][x[c][0]++]=b;
		}
		scanf("%s%s",w,z);
		for(b=0;b<a;b++)
		{
			if(!strcmp(z,k[b]))
			{
				break;
			}
		}
		for(c=0;c<a;c++)
		{
			if(!strcmp(w,k[c]))
			{
				break;
			}
		}
		if(b==a||c==a)
		{
			printf("No route\n");
			continue;
		}
		y[0]=b;
		l[b]=1;
		for(d=0,e=1;d<e;d++)
		{
			i=y[d];
			for(a=1;a<x[i][0];a++)
			{
				if(x[i][a]==c)
				{
					printf("%s %s\n",k[c],k[i]);
					e=-1;
					break;
				}
				if(!l[x[i][a]])
				{
					l[x[i][a]]=1;
					j[x[i][a]]=i;
					y[e++]=x[i][a];
				}
			}
		}
		if(d==e)
		{
			printf("No route\n");
		}
		else
		{
			if(i!=b)
			{
				for(a=i;;a=j[a])
				{
					printf("%s %s\n",k[a],k[j[a]]);
					if(j[a]==b)
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}
