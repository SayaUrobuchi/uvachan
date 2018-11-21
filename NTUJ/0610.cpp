#include <stdio.h>

long long cc[105][105];

int main()
{
	int n, i, j, cnt, f;
	long long tt, temp, m;
	cc[0][0] = 1;
	for(i=1; i<100; i++)
	{
		for(j=0; j<100; j++)
		{
			cc[i][j] = cc[i-1][j] + (j?cc[i-1][j-1]:0);
		}
	}
	while(scanf("%d%lld", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(tt=0, i=0; tt<m; i++)
		{
			tt += cc[n][i];
			if(tt >= m)
			{
				break;
			}
		}
		tt -= cc[n][i];
		m -= tt;
		cnt = i;
		for(i=n-1, f=cnt; i>=0; i--)
		{
			if(cnt == 0)
			{
				printf("0");
				continue;
			}
			/*if(cnt > i)
			{
				printf("1");
				continue;
			}*/
			temp = cc[i][cnt];
			if(temp < m)
			{
				m -= temp;
				printf("1");
				cnt--;
			}
			else
			{
				printf("0");
			}
		}
		for(; i>=0; i--)
		{
			printf("1");
		}
		printf("\n");
	}
	return 0;
}
