#include <stdio.h>
#include <string.h>

int d[30], v[30], dp[1001];
char ans[1001][31];

int main()
{
	int t, n, w, i, j, max, tmp, tmp2, vmax, loc;
	char check;
	check = 0;
	while(scanf("%d%d%d", &t, &w, &n)==3)
	{
		if(check) printf("\n");
		check = 1;
		memset(dp, 0, 1001 * 4);
		ans[0][0] = 0;
		w *= 3;
		max = 0;
		vmax = 0;
		loc = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &d[i], &v[i]);
			tmp = d[i] * w;
			for(j=max; j>-1; j--)
			{
				if(dp[j] || !j)
				{
					tmp2 = j + tmp;
					if(tmp2 < t + 1)
					{
						if(dp[tmp2] < dp[j] + v[i])
						{
							if(tmp2 > max) max = tmp2;
							dp[tmp2] = dp[j] + v[i];
							if(dp[tmp2] > vmax)
							{
								vmax = dp[tmp2];
								loc = tmp2;
							}
							sprintf(ans[tmp2], "%s%c", ans[j], i + 1);
						}
					}
				}
			}
		}
		printf("%d\n%d\n", vmax, strlen(ans[loc]));
		for(i=0; ans[loc][i]; i++)
		{
			tmp = ans[loc][i] - 1;
			printf("%d %d\n", d[tmp], v[tmp]);
		}
	}
	return 0;
}
