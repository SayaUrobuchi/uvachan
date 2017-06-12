#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[200];
int abcc(int x)
{
	int p,q;
	scanf("%d",&p);
	if(p!=-1)
	{
		k[x-1]+=p;
		if(x-1<c)
		{
			c=x-1;
		}
		abcc(x-1);
	}
	scanf("%d",&p);
	if(p!=-1)
	{
		k[x+1]+=p;
		if(x+2>d)
		{
			d=x+2;
		}
		abcc(x+1);
	}
	return 0;
}
int main()
{
	h=0;
	while(scanf("%d",&a)==1)
	{
		if(a==-1)
		{
			break;
		}
		for(b=0,c=100,d=101;b<200;b++)
		{
			k[b]=0;
		}
		k[100]=a;
		abcc(100);
		printf("Case %d:\n",++h);
		printf("%d",k[c++]);
		for(c;c<d;c++)
		{
			printf(" %d",k[c]);
		}
		printf("\n\n");
	}
	return 0;
}