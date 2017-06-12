#include<stdio.h>
int main()
{
	unsigned long long int a;
	while(scanf("%lld",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		a*=10;
		a/=9;
		if(a%10==0)
		{
			printf("%lld %lld\n",a-1,a);
		}
		else
		{
			printf("%lld\n",a);
		}
	}
	return 0;
}