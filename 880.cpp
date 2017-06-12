#include<stdio.h>
#include<math.h>
long long a,b,c;
int main()
{
	while(scanf("%lld",&a)==1)
	{
		c=a*2;
		b=sqrt(c)-1;
		for(b;b*(b+1)<c;b++)
		{
		}
		c=b-1;
		c*=c+1;
		c/=2;
		b*=b+1;
		b/=2;
		printf("%lld/%lld\n",b-a+1,a-c);
	}
	return 0;
}