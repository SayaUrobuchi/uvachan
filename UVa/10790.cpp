#include<stdio.h>
int a,b,c,d,e,f,g,h,j,k;
unsigned long long i;
int main()
{
	h=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		if(a>b)
		{
			c=a;
			a=b;
			b=c;
		}
		if(a==1)
		{
			printf("Case %d: 0\n",++h);
		}
		else
		{
			i=1;
			i*=a;
			i*=a-1;
			i/=2;
			i*=b;
			i*=b-1;
			i/=2;
			printf("Case %d: %llu\n",++h,i);
		}
	}
	return 0;
}