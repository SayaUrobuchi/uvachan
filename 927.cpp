#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,k[21];
	long long i,j;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d",&a);
		for(a++,b=0;b<a;b++)
		{
			scanf("%d",&k[b]);
		}
		scanf("%d%d",&c,&d);
		e=d*2/c;
		e=sqrt(e);
		while(c*(e*e+e)<d*2)
		{
			e++;
		}
		for(j=1,d=0,i=0;d<a;j*=e,d++)
		{
			i+=k[d]*j;
		}
		printf("%lld\n",i);
	}
	return 0;
}