#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[101][101];
	for(a=1;a<101;a++)
	{
		k[1][a]=a;
	}
	for(a=2;a<101;a++)
	{
		k[a][1]=1;
		for(b=2;b<101;b++)
		{
			k[a][b]=k[a-1][b]+k[a][b-1];
			k[a][b]%=1000000;
		}
	}
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		printf("%d\n",k[a][b]);
	}
	return 0;
}