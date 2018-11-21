#include<stdio.h>
#include<math.h>
int main()
{
	double x;
	int a,b,c,d,e,f,g,h,i,j,k[10001];
	i=1601;
	for(c=0;c<40;c++)
	{
		k[c]=1;
	}
	for(c;c<=10000;c++)
	{
		i+=c*2;
		j=sqrt(i);
		for(d=3,e=1;d<=j;d+=2)
		{
			if(i%d==0)
			{
				e=0;
				break;
			}
		}
		k[c]=e;
	}
	while(scanf("%d %d",&a,&b)==2)
	{
		for(c=a,i=0;c<=b;c++)
		{
			i+=k[c];
		}
		x=i*100;
		x/=b-a+1;
		printf("%.2f\n",x);
	}
	return 0;
}