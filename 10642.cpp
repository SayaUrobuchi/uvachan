#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	scanf("%d",&h);
	for(g=0;h>0;h--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e=a+b+2;
		f=c+d;
		i=e+f;
		i*=f-e+1;
		i/=2;
		i+=b;
		i+=c;
		i++;
		printf("Case %d: %d\n",++g,i);
	}
	return 0;
}