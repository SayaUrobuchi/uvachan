#include <iostream>
#include <cstring>

const int N = 4;

int ary[8], bry[8][64], bn[8];
long long dp[8][1048576];

void brk(int cnt, int val, int a[], int &n)
{
	if (cnt == 0)
	{
		return;
	}
	if (cnt == 1)
	{
		//a[n++] = val;
		return;
	}
	brk(cnt>>1, val, a, n);
	a[n++] = val * (cnt >> 1);
	if (cnt & 1)
	{
		a[n++] = val;
	}
}

int main()
{
	int count, i, j, k, n, m, o, t, c;
	long long sum;
	scanf("%d", &count);
	while (count--)
	{
		for (i=1; i<=N; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &m);
		while (m--)
		{
			for (i=1; i<=N; i++)
			{
				scanf("%d", &c);
				bn[i] = 0;
				brk(c+1, ary[i], bry[i], bn[i]);
			}
			scanf("%d", &o);
			dp[0][0] = 1;
			for (i=1, sum=0; i<=N; i++)
			{
				memcpy(dp[i], dp[i-1], sizeof(dp[0][0])*(o+1));
				for (j=0; j<bn[i]; j++)
				{
					t = bry[i][j];
					sum += t;
					if (sum > o)
					{
						sum = o;
					}
					for (k=sum; k>=t; k--)
					{
						if (t == ary[i])
						{
							dp[i][k] = dp[i-1][k];
						}
						dp[i][k] += dp[i][k-t];
					}
//				printf("now %d %d:", ary[i], j);
//				for (k=0; k<=o&&k<=16; k++)
//				{
//					printf(" %lld", dp[i][k]);
//				}
//				puts("");
				}
			}
			printf("%lld\n", dp[N][o]);
		}
	}
	return 0;
}
