#include<stdio.h>
int a,b,c,d,e,f,g,h,j,k[500000],l[500000];
long long i;
int abc(int p,int q,int r)
{
	int w,x,y,z;
	w=q-p;
	y=0;
	for(x=q,z=p;z<q;z++,w--)
	{
		for(x;x<r;x++)
		{
			if(k[x]>=k[z])
			{
				break;
			}
			i+=w;
			l[y++]=k[x];
		}
		l[y++]=k[z];
	}
	for(x;x<r;x++)
	{
		l[y++]=k[x];
	}
	for(w=0;w<y;p++,w++)
	{
		k[p]=l[w];
	}
	return 0;
}
int abcc(int p,int q)
{
	int w,x;
	if(p==q-1)
	{
		return 0;
	}
	w=p+q;
	w/=2;
	abcc(p,w);
	abcc(w,q);
	abc(p,w,q);
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		i=0;
		abcc(0,a);
		printf("%lld\n",i);
	}
	return 0;
}