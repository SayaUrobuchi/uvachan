#include<stdio.h>
#include<math.h>
int abcc(int a,int b,int c)
{
	int i;
	if(b==0)
	{
		return 1;
	}
	if(b%2==0)
	{
		i=abcc(a,b/2,c);
		return (i*i)%c;
	}
	else
	{
		return ((a%c)*abcc(a,b-1,c))%c;
	}
}
int main()
{
	int a,b,c;
	long long int d;
	while(scanf("%d %d %d",&a,&b,&c)==3)
	{
		d=abcc(a,b,c);
		printf("%lld\n",d);
	}
	return 0;
}