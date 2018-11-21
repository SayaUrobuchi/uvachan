#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	double i,j,k,l;
	while(scanf("%d",&a)==1)
	{
		if(a<3)
		{
			break;
		}
		for(b=0,i=0,j=0;b<a;b++)
		{
			scanf("%lf%lf",&k,&l);
			i+=k;
			j+=l;
		}
		i/=a;
		j/=b;
		printf("%.3f %.3f\n",i,j);
	}
	return 0;
}