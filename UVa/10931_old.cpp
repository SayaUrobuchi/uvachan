#include<stdio.h>
int main()
{
	bool x[32];
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		printf("The parity of ");
		for(c=0,d=0;;d++)
		{
			b=a%2;
			a/=2;
			x[d]=b;
			c+=b;
			if(a==0)
			{
				break;
			}
		}
		for(d;d>=0;d--)
		{
			printf("%d",x[d]);
		}
		printf(" is %d (mod 2).\n",c);
	}
	return 0;
}