#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,j,k;
	long long i;
	h=0;
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		b=a/2;
		i=(b+2)*(b-1)/2*-1;
		for(b++,c=2;c<b;c++)
		{
			i-=a%c;
		}
		i+=a*(b-2);
		printf("Case %d: %lld\n",++h,i);
	}
	return 0;
}