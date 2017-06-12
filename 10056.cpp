#include<stdio.h>
#include<math.h>
int main()
{
	double i,j,k,x;
	int a,b,c,d,e,f,g,h;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		scanf("%d %lf %d",&a,&x,&b);
		if(x==0)
		{
			printf("0.0000\n");
			continue;
		}
		k=1-x;
		j=pow(k,a);
		i=pow(k,b-1);
		i*=x;
		j=1-j;
		i/=j;
		printf("%.4f\n",i);
	}
	return 0;
}