#include<stdio.h>
#include<string.h>
int main()
{
	char check[51],n,m,i,j,k,cas,pri[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	char com[51][15],fac[15],tmp[15];
	unsigned long ans;
	memset(com,0,30);
	for(i=2;i<51;i++)
	{
		for(j=0,k=i;j<15;j++)
		{
			com[i][j]=com[i-1][j];
			if(!(k%pri[j]))
			{
				while(!(k%pri[j]))
				{
					k/=pri[j];
					com[i][j]++;
				}
			}
		}
	}
	cas=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n&&!m)
		{
			break;
		}
		memset(check,1,n+1);
		for(i=0,k=0;i<n;i++)
		{
			scanf("%d",&j);
			k+=check[j];
			check[j]=0;
		}
		for(i=0;i<15;i++)
		{
			fac[i]=com[k][i];
		}
		n=k;
		printf("Case %d:\n",++cas);
		while(m--)
		{
			scanf("%d",&k);
			for(i=0,j=n-k;i<15;i++)
			{
				tmp[i]=fac[i];
				tmp[i]-=com[j][i];
				tmp[i]-=com[k][i];
			}
			for(i=0,ans=1;i<15;i++)
			{
				for(j=0;j<tmp[i];j++)
				{
					ans*=pri[i];
				}
			}
			printf("%llu\n",ans);
		}
	}
	return 0;
}