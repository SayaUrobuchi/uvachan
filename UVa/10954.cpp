#include<stdio.h>
int a,b,c,d,e,f,g,h,j,k[5010];
long long i;
int abcc(int p)
{
	if(p>a)
	{
		return 0;
	}
	int w,x,y;
	w=p*2;
	if(w>a)
	{
		return 0;
	}
	if(w==a)
	{
		x=w;
	}
	else
	{
		if(k[w]<k[w+1])
		{
			x=w;
		}
		else
		{
			x=w+1;
		}
	}
	if(k[x]<k[p])
	{
		y=k[x];
		k[x]=k[p];
		k[p]=y;
	}
	abcc(x);
	return 0;
}
int main()
{
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		for(a++,b=1;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		for(a--,b=a;b>0;b--)
		{
			abcc(b);
		}
		for(i=0;a>1;)
		{
			j=k[1];
			k[1]=k[a];
			a--;
			abcc(1);
			k[1]+=j;
			i+=k[1];
			abcc(1);
		}
		printf("%lld\n",i);
	}
	return 0;
}