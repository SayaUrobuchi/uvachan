#include <stdio.h>
#include <string.h>

#define dpmax 1000

int main()
{
	int s, n, max, cmax, ans[101], in[101], i, j, k, tmp;
	char dp[dpmax];
	while(scanf("%d", &s)==1)
	{
		if(!s) break;
		scanf("%d", &n);
		cmax = 0;
		while(n--)
		{
      max = 0;
			memset(dp, 0, dpmax);
			scanf("%d", &in[0]);
			for(i=1, in[0]++; i<in[0]; i++)
			{
				scanf("%d", &in[i]);
				for(j=max; j>-1; j--)
				{
					if(!j || dp[j])
					{
						if(dp[j] < s)
						{
							for(k=dp[j], tmp=j+in[i]; k<s; k++, tmp+=in[i])
							{
								if(tmp < dpmax)
								{
									if(!dp[tmp] || dp[tmp] > k + 1)
									{
										if(tmp > max) max = tmp;
										dp[tmp] = k + 1;
									}
								}
								else break;
							}
						}
					}
				}
			}
			for(i=1; dp[i]; i++);
			if(i > cmax)
			{
				cmax = i;
				for(i=0; i<in[0]; i++) ans[i] = in[i];
			}
			else if(i == cmax)
			{
				if(in[0] < ans[0])
				{
					for(i=0; i<in[0]; i++) ans[i] = in[i];
				}
				else if(in[0] == ans[0])
				{
					if(in[in[0] - 1] < ans[ans[0] - 1])
					{
            for(i=0; i<in[0]; i++) ans[i] = in[i];
					}
				}
			}
		}
		printf("max coverage =%4d :", cmax - 1);
		for(i=1; i<ans[0]; i++)
		{
			printf("%3d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
