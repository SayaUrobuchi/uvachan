#include<stdio.h>
int n,dp[10][10];
char tmp[10][10];
int ans(int p,int q)
{
	if(p==q)
	{
		printf("A%d",p+1);
		return 0;
	}
	printf("(");
	ans(p,tmp[p][q]);
	printf(" x ");
	ans(tmp[p][q]+1,q);
	printf(")");
	return 0;
}
int main()
{
	int i,j,k,l,m,t,ary[10][2],cas;
	cas=0;
	while(scanf("%d",&n)==1)
	{
		if(!n)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&ary[i][0],&ary[i][1]);
			dp[i][i]=0;
			tmp[i][i]=i;
		}
		for(k=1;k<n;k++)
		{
			for(i=0,j=i+k;j<n;i++,j++)
			{
				dp[i][j]=0;
				m=ary[i][0]*ary[j][1];
				for(l=i;l<j;l++)
				{
					t=m*ary[l][1]+dp[i][l]+dp[l+1][j];
					if(t<dp[i][j]||!dp[i][j])
					{
						dp[i][j]=t;
						tmp[i][j]=l;
					}
				}
			}
		}
		printf("Case %d: ",++cas);
		ans(0,n-1);
		printf("\n");
	}
	return 0;
}
