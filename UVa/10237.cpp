#include <stdio.h>

long long black[31][31], white[31][31];

int main()
{
	int n, i, j, k;
	long long ans;
	white[0][0] = black[0][0] = 1;
	white[1][0] = black[1][0] = white[1][1] = 1;
	black[1][1] = 0;
	for(i=2; i<31; i++)
	{
		black[i][0] = white[i][0] = 1;
		if(i % 2)
		{
			for(j=1; j<=i; j++)
			{
				black[i][j] = white[i-1][j] + white[i-1][j-1] * (i-j+1);
				white[i][j] = white[i-1][j] + white[i-1][j-1] * (i-j);
			}
		}
		else
		{
			black[i][1] = white[i][1] = i*i / 2;
			for(j=2; j<=i; j++)
			{
				black[i][j] = white[i][j] = white[i-2][j] + white[i-2][j-1] * 2 * (i-j) + white[i-2][j-2] * (i-j+1) * (i-j);
			}
		}
	}
	while(scanf("%d%d", &n, &k) == 2)
	{
		if(!n && !k)
		{
			break;
		}
		for(i=0, ans=0; i<=k; i++)
		{
			if(i < 31 && k-i < 31)
			{
				ans += black[n][i] * white[n][k-i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
