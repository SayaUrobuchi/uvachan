#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int k, sp;
int dp[1001][1001], used[1001][1001], ptr[26], alp[26][1001];
char str[1001], list[1001];

int max(int p, int q)
{
	return p > q ? p : q;
}

int calc(int p, int q)
{
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(p > q)
	{
		return 0;
	}
	if(p == q)
	{
		dp[p][q] = 1;
		return dp[p][q];
	}
	if(str[p] == str[q])
	{
		dp[p][q] = calc(p+1, q-1) + 2;
		return dp[p][q];
	}
	dp[p][q] = max(calc(p+1, q), calc(p, q-1));
	return dp[p][q];
}

void recurs(int dep)
{
	if(dep == k)
	{
		if(sp)
		{
			printf("%c", sp);
		}
	}
	else
	{
		printf("%c", list[dep]);
		recurs(dep+1);
		printf("%c", list[dep]);
	}
	if(dep == 0)
	{
		printf("\n");
	}
}

int main()
{
	int len, res, i, j, l, r, p, q;
	while(gets(str))
	{
		memset(ptr, 0, sizeof(ptr));
		for(len=0; str[len]; len++)
		{
			alp[str[len]-'a'][ptr[str[len]-'a']++] = len;
		}
		memset(used, 0, sizeof(used));
		res = calc(0, len-1);
		sp = 0;
		for(i=res, l=0, r=len-1, k=0; i>0; )
		{
			for(j=0; j<26; j++)
			{
				for(p=0; p<ptr[j]; p++)
				{
					if(alp[j][p] >= l)
					{
						break;
					}
				}
				if(p < ptr[j])
				{
					for(q=ptr[j]-1; q>=p; q--)
					{
						if(alp[j][q] <= r)
						{
							break;
						}
					}
					if(q >= p)
					{
						p = alp[j][p];
						q = alp[j][q];
						if(dp[p][q] == i)
						{
							if(p == q)
							{
								sp = str[p];
								i--;
							}
							else
							{
								list[k++] = str[p];
								i -= 2;
							}
							l = p+1;
							r = q-1;
							break;
						}
					}
				}
			}
		}
		recurs(0);
	}
	return 0;
}
