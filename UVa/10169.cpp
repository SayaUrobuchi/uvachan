#include <stdio.h>
#include <math.h>

#define N 1000000

double dp[N], zero[N];

int main()
{
	int n, i;
	for(i=1; i<N; i++)
	{
		dp[i] = dp[i-1] + (1.0-dp[i-1]) * (1.0/i) * (1.0/(i+1));
		zero[i] = zero[i-1] + log10((double)i) + log10((double)i+1);
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%.6lf %d\n", dp[n], (int)(zero[n]));
	}
	return 0;
}
