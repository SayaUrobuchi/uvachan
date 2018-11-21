#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,k;
	double i,j;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		if(a==1&&b==1)
		{
			printf("%.5f\n",0.5);
			continue;
		}
		i=b;
		i/=a+b;
		i*=b-1;
		i/=a-c+b-1;
		j=a;
		j/=a+b;
		j*=b;
		j/=a-c-1+b;
		printf("%.5f\n",i+j);
	}
	return 0;
}