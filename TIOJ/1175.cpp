#include <stdio.h>

int dp[100005];

int main()
{
	int n, i, j, temp, maxlen;
	while(scanf("%d", &n) == 1)
	{
		for(i=1, maxlen=0; i<=n; i++)
		{
			scanf("%d", &temp);
			for(j=maxlen; j>=0; j--)
			{
				if(temp > dp[j])
				{
					dp[j+1] = temp;
					maxlen += (j==maxlen);
					break;
				}
			}
		}
		printf("%d\n", maxlen);
	}
	return 0;
}
