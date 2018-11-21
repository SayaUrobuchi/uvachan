#include <stdio.h>
#include <string.h>

int tbl[105][105][105], ary[105];
unsigned int cnt[105];
long long fcnt[105];
char buf[10005];

int main()
{
	int i, j, k, a, b, n, p, q, r, t, count;
	int *pp, *qq;
	for(i=0; i<100; i++)
	{
		tbl[i][1][0] = 1;
		for(j=2, k=i; j<=100; j++, k+=i)
		{
			memcpy(tbl[i][j], tbl[i][j-1], sizeof(tbl[0][0]));
			tbl[i][j][k%100]++;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &n);
		memset(cnt, 0, sizeof(cnt));
		for(i=0; i<n; i++)
		{
			scanf("%s%d%d", buf, &p, &q);
			sscanf(buf+1, "%d", &r);
			r %= 100;
			t = q/100;
			p %= 100;
			q %= 100;
			pp = tbl[p][100];
			qq = tbl[p][q];
			for(j=0, k=r; j<100; j++, k++, pp++, qq++)
			{
				if(k == 100)
				{
					k = 0;
				}
				cnt[k] += *pp*t;
				cnt[k] += *qq;
			}
		}
		fcnt[0] = cnt[0];
		for(i=1; i<100; i++)
		{
			fcnt[i] = fcnt[i-1] + cnt[i];
		}
		for(i=0, j=0; i<100; i++)
		{
			if(fcnt[i] <= b && fcnt[99]-fcnt[i] <= a)
			{
				ary[j++] = i+1;
			}
		}
		printf("%d\n", j);
		if(j)
		{
			printf("%d", ary[0]);
		}
		for(i=1; i<j; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n");
	}
	return 0;
}
