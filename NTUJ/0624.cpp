#include <stdio.h>
#include <string.h>

int dp[256][256];
char s1[256], s2[256];

int main()
{
	int i, j, k, mx, ni, nj, di, dj, cnt;
	while(gets(s1+1))
	{
		if(strcmp(s1+1, "#") == 0)
		{
			break;
		}
		gets(s2+1);
		for(ni=1, nj=1, cnt=0; ; )
		{
			for(i=ni, mx=0; s1[i]; i++)
			{
				for(j=nj; s2[j]; j++)
				{
					if(s1[i] == s2[j])
					{
						dp[i][j] = dp[i-1][j-1]+1;
						if(dp[i][j] >= mx)
						{
							mx = dp[i][j];
							di = i;
							dj = j;
						}
					}
					else
					{
						dp[i][j] = 0;
					}
				}
			}
			if(mx < 2)
			{
				break;
			}
			for(k=di-mx+1; ; k++)
			{
				s1[k] = s1[k+mx];
				if(s1[k] == 0)
				{
					break;
				}
			}
			for(k=dj-mx+1; ; k++)
			{
				s2[k] = s2[k+mx];
				if(s2[k] == 0)
				{
					break;
				}
			}
			cnt++;
		}
		printf("%d %s_%s\n", cnt, s1+1, s2+1);
	}
	return 0;
}
