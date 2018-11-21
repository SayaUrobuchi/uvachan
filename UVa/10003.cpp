#include<stdio.h>
int main()
{
    int len,num,dp[51][51],tmp[51][51],i,j,k,l,m,n;
    while(scanf("%d",&len)==1)
    {
        if(!len)
        {
            break;
        }
        scanf("%d",&num);
        for(i=0,j=0;i<num;i++)
        {
            scanf("%d",&k);
            tmp[i][i]=k-j;
            j=k;
            dp[i][i]=0;
        }
        dp[i][i]=0;
        tmp[i][i]=len-j;
        for(k=1,num++;k<num;k++)
        {
            for(i=0,j=i+k;j<num;i++,j++)
            {
                dp[i][j]=0;
                for(l=i;l<j;l++)
                {
                    m=tmp[l+1][j]+tmp[i][l];
                    n=dp[i][l]+dp[l+1][j];
                    if(m+n<dp[i][j]||!dp[i][j])
                    {
                        dp[i][j]=m+n;
                        tmp[i][j]=m;;
                    }
                }
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][num-1]);
    }
    return 0;
}
