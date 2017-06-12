#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j;
char k[1000],l[10],m[10];
int abcc(int p,int q,int r)
{
	int w,x;
	if(p==a)
	{
		k[q]=1;
		return 0;
	}
	abcc(p+1,q,r);
	for(w=0;w<r;w++)
	{
		abcc(p+1,q+l[w],r);
	}
	return 0;
}
int bcaa(int p,int q)
{
	int w,x,y;
	if(p==b)
	{
		if(q>i)
		{
			i=q;
			for(w=0;w<b;w++)
			{
				m[w]=l[w];
			}
		}
		return 0;
	}
	for(w=l[p-1]+1;w<q;w++)
	{
		for(x=1,y=w*a+2;x<y;x++)
		{
			k[x]=0;
		}
		l[p]=w;
		abcc(0,0,p+1);
		for(x=1;k[x];x++);
		bcaa(p+1,x+1);
	}
	return 0;
}
int main()
{
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		i=0;
		l[0]=1;
		bcaa(1,a+2);
		for(a=0;a<b;a++)
		{
			printf("%3d",m[a]);
		}
		printf(" ->%3d\n",i-2);
	}
	return 0;
}