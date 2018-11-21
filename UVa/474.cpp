#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,l[1000001];
double k[1000001];
int main()
{
	k[1]=5;
	l[1]=1;
	for(a=2;a<1000001;a++)
	{
		k[a]=k[a-1]/2;
		l[a]=l[a-1];
		if(k[a]<1)
		{
			k[a]*=10;
			l[a]++;
		}
	}
	while(scanf("%d",&a)==1)
	{
		printf("2^-%d = %.3fe-%d\n",a,k[a],l[a]);
	}
	return 0;
}