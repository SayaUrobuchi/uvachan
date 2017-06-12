#include <stdio.h>
#include <string.h>

int len, answer;
int map[10001][101], num[10000];
int length[10001][101];
int chk[10001];
char str[10001];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int dfs(int now)
{
	int i, temp, best, sec;
	for(i=0, best=sec=0; i<num[now]; i++)
	{
		if(!chk[map[now][i]])
		{
			chk[map[now][i]] = 1;
			temp = dfs(map[now][i]) + length[now][i];
			if(temp >= best)
			{
				sec = best;
				best = temp;
			}
			else if(temp > sec)
			{
				sec = temp;
			}
		}
	}
	if(best + sec > answer)
	{
		answer = best + sec;
	}
	return best;
}

int main()
{
	int n, m, o, i, best, sec, temp, ans, maxn;
	ans = 0;
	maxn = 0;
	while(gets(str))
	{
		if(sscanf(str, "%d%d%d", &n, &m, &o) == 3)
		{
			ans = 1;
			map[n][num[n]] = m;
			map[m][num[m]] = n;
			maxn = max(maxn, max(n, m));
			length[n][num[n]++] = o;
			length[m][num[m]++] = o;
		}
		else
		{
			answer = 0;
			memset(chk, 0, sizeof(chk));
			for(i=1; i<=maxn; i++)
			{
				if(!chk[i])
				{
					chk[i] = 1;
					dfs(i);
				}
			}
			printf("%d\n", answer);
			memset(num, 0, sizeof(num));
			ans = 0;
			maxn = 0;
		}
	}
	if(ans)
	{
		answer = 0;
		memset(chk, 0, sizeof(chk));
		for(i=1; i<=maxn; i++)
		{
			if(!chk[i])
			{
				chk[i] = 1;
				dfs(i);
			}
		}
		printf("%d\n", answer);
	}
	scanf(" ");
	return 0;
}
