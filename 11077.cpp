#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	unsigned long long k[21][21];
	k[0][0]=1;
	for(a=1;a<21;a++)
	{
		k[a][0]=1;
		for(b=1;b<a;b++)
		{
			k[a][b]=k[a-1][b-1]*a+k[a-1][b];
		}
		k[a][b]=k[a-1][b-1]*a;
	}
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		printf("%llu\n",k[a-1][b]);
	}
	return 0;
}