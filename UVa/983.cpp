#include <stdio.h>

int row[1005][1005], column[1005][1005];

int main()
{
	int cas, n, m, i, j, k, p, q;
	long long sum, now, temp;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &k);
				row[i][j] = row[i][j-1] + k;
				column[j][i] = column[j][i-1] + k;
			}
		}
		for(i=1, sum=0, now=0; i<=m; i++)
		{
			now += row[i][m];
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=0, j=m, temp=now; j<=n; i++, j++)
		{
			for(p=1, q=m, now=temp; q<=n; p++, q++)
			{
				printf("%lld\n", now);
				sum += now;
				now -= column[p][j] - column[p][i];
				now += column[q+1][j] - column[q+1][i];
			}
			temp -= row[i+1][m];
			temp += row[j+1][m];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
