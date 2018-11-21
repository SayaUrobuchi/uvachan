#include<stdio.h>
int n,l,nth;
char str[81];
int dfs(int len)
{
	int hlen,i,j,k,m;
	hlen=len/2-1;
	for(i=0;i<l;i++)
	{
		str[len]=65+i;
		for(j=len-1;j>hlen;j--)
		{
			for(k=len,m=j;k>j;k--,m--)
			{
				if(str[k]!=str[m])
				{
					break;
				}
			}
			if(k==j)
			{
				break;
			}
		}
		if(j==hlen)
		{
			str[len+1]=0;
			nth++;
			if(nth==n)
			{
				return len+1;
			}
			k=dfs(len+1);
			if(k)
			{
				return k;
			}
		}
	}
	return 0;
}
int main()
{
	int len,i;
	while(scanf("%d%d",&n,&l)==2)
	{
		if(!n&&!l)
		{
			break;
		}
		nth=0;
		len=dfs(0);
		printf("%c",str[0]);
		for(i=1;i<len;i++)
		{
			if(i==64)
			{
				printf("\n");
			}
			else if(!(i%4))
			{
				printf(" ");
			}
			printf("%c",str[i]);
		}
		printf("\n%d\n",len);
	}
	return 0;
}