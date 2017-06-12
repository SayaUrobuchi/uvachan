#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,k,l;
	long long i,j;
	while(scanf("%d",&a)==1)
	{
		if(a==1)
		{
			printf("1\n");
			continue;
		}
		j=a/2+1;
		j*=j*2;
		j-=3;
		printf("%lld\n",j*3);
	}
	return 0;
}