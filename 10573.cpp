#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	double i,j;
	char x;
	i=2.0*acos(0.0);
	scanf("%d",&c);
	for(c;c>0;c--)
	{
		scanf("%d%c",&a,&x);
		if(x==10)
		{
			printf("%.4f\n",a*a*i*1/8.0);
		}
		else
		{
			scanf("%d",&b);
			printf("%.4f\n",a*b*2*i);
		}
	}
	return 0;
}