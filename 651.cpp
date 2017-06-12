#include<stdio.h>
double k[100000];
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	k[1]=1.0/2;
	for(a=2,b=4;a<100000;a++,b+=2)
	{
		k[a]=k[a-1]+1.0/b;
	}
	printf("# Cards Overhang\n");
	while(scanf("%d",&a)==1)
	{
		printf("%5d     %.3f\n",a,k[a]);
	}
	return 0;
}