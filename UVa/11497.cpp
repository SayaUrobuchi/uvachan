#include <stdio.h>
#include <string.h>

int tim[15];
int used[2050000], dp[2050000];
char s1[10000], s2[10000];
int cnt[15];

int has(int stat, int bit)
{
	return stat%tim[bit+1] >= tim[bit];
}

int recurs(int stat)
{
	int i, s, p, q;
	if(used[stat])
	{
		return dp[stat];
	}
	used[stat] = 1;
	dp[stat] = 0;
	if(stat == 0)
	{
		return 0;
	}
	for(i=0; i<9; i++)
	{
		if(has(stat, i))
		{
			s = stat;
			p = i-i%3+(i%3+1)%3;
			q = i-i%3+(i%3+2)%3;
			if(has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if(recurs(s)+1 > dp[stat])
				{
					dp[stat] = recurs(s)+1;
				}
			}
			s = stat;
			p = i%3 + (i/3+1)%3*3;
			q = i%3 + (i/3+2)%3*3;
			if(has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if(recurs(s)+1 > dp[stat])
				{
					dp[stat] = recurs(s)+1;
				}
			}
			s = stat;
			p = (i/3+1)%3*3 + (i%3+1)%3;
			q = (i/3+2)%3*3 + (i%3+2)%3;
			if(has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if(recurs(s)+1 > dp[stat])
				{
					dp[stat] = recurs(s)+1;
				}
			}
			s = stat;
			p = (i/3+1)%3*3 + (i%3+2)%3;
			q = (i/3+2)%3*3 + (i%3+1)%3;
			if(has(stat, p) && has(stat, q))
			{
				s -= tim[i] + tim[p] + tim[q];
				if(recurs(s)+1 > dp[stat])
				{
					dp[stat] = recurs(s)+1;
				}
			}
		}
	}
	return dp[stat];
}

int main()
{
	int i, j, f, n, t, ans, temp;
	tim[0] = 1;
	for(i=1; i<=10; i++)
	{
		tim[i] = tim[i-1] * 5;
	}
	recurs(tim[9]-1);
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(cnt, 0, sizeof(cnt));
		for(i=0; i<n; i++)
		{
			scanf("%s%s", s1, s2);
			if(*s1 == 'u')
			{
				t = 0;
			}
			if(*s1 == 'd')
			{
				t = 3;
			}
			if(*s1 == 't')
			{
				t = 6;
			}
			if(*s2 == 't')
			{
				t++;
			}
			if(*s2 == 'q')
			{
				t += 2;
			}
			cnt[t]++;
		}
		for(i=0, ans=0; i<tim[9]; i++)
		{
			for(j=0, f=0, temp=0; j<9; j++)
			{
				if(i/tim[j]%5 > cnt[j])
				{
					f = 1;
				}
				cnt[j] -= i/tim[j]%5;
				temp += cnt[j]/3;
			}
			if(f == 0)
			{
				temp += recurs(i);
				if(temp > ans)
				{
					ans = temp;
				}
			}
			for(j=0; j<9; j++)
			{
				cnt[j] += i/tim[j]%5;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
