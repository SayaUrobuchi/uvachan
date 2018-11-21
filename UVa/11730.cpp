#include <stdio.h>

int used[2005], q[2005], qs[2005], tbl[1005];

int main()
{
	int i, j, k, n, m, now, nxt, cnt, s, cas;
	cnt = 0;
	cas = 0;
	for(i=2; i<1005; i+=2)
	{
		tbl[i] = 2;
	}
	for(i=3; i<40; i+=2)
	{
		if(tbl[i] == 0)
		{
			tbl[i] = i;
			for(j=i*i, k=i+i; j<1005; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for(; i<1005; i+=2)
	{
		if(tbl[i] == 0)
		{
			tbl[i] = i;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		q[0] = n;
		qs[0] = 0;
		cnt++;
		for(i=0, j=1; i<j; i++)
		{
			now = q[i];
			s = qs[i];
			if(now > m)
			{
				continue;
			}
			if(now == m)
			{
				break;
			}
			for(k=now; k>1&&tbl[k]!=now; k/=tbl[k])
			{
				if(k%(tbl[k]*tbl[k]))
				{
					nxt = now+tbl[k];
					if(used[nxt] != cnt)
					{
						used[nxt] = cnt;
						q[j] = nxt;
						qs[j] = s+1;
						j++;
					}
				}
			}
		}
		if(i == j)
		{
			printf("Case %d: -1\n", ++cas);
		}
		else
		{
			printf("Case %d: %d\n", ++cas, s);
		}
	}
	return 0;
}
