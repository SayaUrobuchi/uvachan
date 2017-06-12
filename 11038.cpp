#include<stdio.h>
long long i,j;
unsigned int l;
int abcc(unsigned int p,int q)
{
	int w,x;
	if(p<10)
	{
		return 1;
	}
	w=p-1;
	w/=10;
	w*=q;
	if(!(p%10))
	{
		w+=l%q+1;
	}
	return w+abcc(p/10,q*10);
}
int main()
{
	unsigned int a,b,c,d,e,f,g,h,k;
	while(scanf("%lld%lld",&i,&j)==2)
	{
		if(i==-1&&j==-1)
		{
			break;
		}
		l=--i;
		if(i==-1)
		{
			a=0;
		}
		else
		{
			a=abcc(i,1);
		}
		l=j;
		b=abcc(j,1);
		printf("%d\n",b-a);
	}
	return 0;
}