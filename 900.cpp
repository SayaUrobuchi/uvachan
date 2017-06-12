#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	long long k[51];
	k[1]=1;
	k[2]=2;
	for(a=3;a<51;a++)
	{
		k[a]=k[a-1]+k[a-2];
	}
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		printf("%lld\n",k[a]);
	}
	return 0;
}
