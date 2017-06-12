#include<stdio.h>
#include<math.h>
int main()
{
	long long int b,c,i,j;
	int a;
	while(scanf("%d %lld",&a,&b)==2)
	{
		c=a-1;
		c*=a;
		c+=b*2;
		j=(int)(sqrt(c));
		i=j;
		i+=j*j;
		if(i<c)
		{
			printf("%lld\n",j+1);
		}
		else
		{
			printf("%lld\n",j);
		}
	}
	return 0;
}