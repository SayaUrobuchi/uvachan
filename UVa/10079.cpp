#include<stdio.h>
int main()
{
	long long int a,b;
	while(scanf("%lld",&a)==1)
	{
		if(a<0)
		{
			break;
		}
		b=(a+1)*a/2;
		b++;
		printf("%lld\n",b);
	}
	return 0;
}