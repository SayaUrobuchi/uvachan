#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,c,d,e,f,g,h;
	double i,j,k,l,x;
	x=sqrt(3)/2;
	while(scanf("%lld%lld",&a,&b)==2)
	{
		a++;
		b++;
		i=sqrt(a);
		c=i;
		if(c==i)
		{
			c--;
		}
		if(c%2==a%2)
		{
			i=c+1.0/3;
			i*=x;
		}
		else
		{
			i=c+2.0/3;
			i*=x;
		}
		c=c*c+c+1;
		j=a-c;
		j/=2;
		k=sqrt(b);
		c=k;
		if(c==k)
		{
			c--;
		}
		if(c%2==b%2)
		{
			k=c+1.0/3;
			k*=x;
		}
		else
		{
			k=c+2.0/3;
			k*=x;
		}
		c=c*c+c+1;
		l=b-c;
		l/=2;
		printf("%.3f\n",sqrt((i-k)*(i-k)+(j-l)*(j-l)));
	}
	return 0;
}