#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int i[10],y;
}abc;
int a,b,c,d,e,f,g[31],h[30],j[30][10],x[10];
abc k[30];
int abcc(const void *p,const void *q)
{
	return *(int*)p-*(int*)q;
}
int aabc(const void *p,const void *q)
{
	if((*(abc*)p).i[0]!=(*(abc*)q).i[0])
	{
		return (*(abc*)p).i[0]-(*(abc*)q).i[0];
	}
	for(d=1;d<b;d++)
	{
		if((*(abc*)p).i[d]!=(*(abc*)q).i[d])
		{
			return (*(abc*)q).i[d]-(*(abc*)p).i[d];
		}
	}
	return 0;
}
int main()
{
	int p,q;
	while(scanf("%d%d",&a,&b)==2)
	{
		for(c=0;c<a;c++)
		{
			for(d=0;d<b;d++)
			{
				scanf("%d",&x[d]);
			}
			qsort(x,b,sizeof(int),abcc);
			for(d=0;d<b;d++)
			{
				k[c].i[d]=x[d];
			}
			k[c].y=c+1;
		}
		qsort(k,c,sizeof(abc),aabc);
		for(d=0;d<b;d++)
		{
			j[0][d]=k[0].i[d];
		}
		h[0]=0;
		g[0]=-1;
		for(d=1,e=1;e<c;e++)
		{
			for(p=0;p<d;p++)
			{
				for(f=0;f<b;f++)
				{
					if(k[e].i[f]<=j[p][f])
					{
						break;
					}
				}
				if(f!=b)
				{
					for(f=0;f<b;f++)
					{
						j[p][f]=k[e].i[f];
					}
					h[p]=e;
					if(p>0)
					{
						g[e]=h[p-1];
					}
					else
					{
						g[e]=-1;
					}
					break;
				}
			}
			if(p==d)
			{
				for(f=0;f<b;f++)
				{
					j[d][f]=k[e].i[f];
				}
				h[d]=e;
				g[e]=h[d-1];
				d++;
			}
		}
		printf("%d\n",d--);
		for(e=h[d],f=0;;e=g[e],f++)
		{
			h[f]=k[e].y;
			if(g[e]==-1)
			{
				break;
			}
		}
		printf("%d",h[f]);
		for(f--;f>-1;f--)
		{
			printf(" %d",h[f]);
		}
		printf("\n");
	}
	return 0;
}