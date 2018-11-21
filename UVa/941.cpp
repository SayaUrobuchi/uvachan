#include <stdio.h>

#define N 26
#define M 8

char s[32], ans[32];
int ss[32], tbl[32][8], tt[8], pri[] = {2, 3, 5, 7, 11, 13, 17, 19};

int main()
{
	int count, n, i, j, k, l, len;
	long long m, cc;
	for (i=2; i<=20; i++)
	{
		n = i;
		for (j=0; j<M; j++)
		{
			tbl[i][j] = tbl[i-1][j];
			while (n % pri[j] == 0)
			{
				tbl[i][j]++;
				n /= pri[j];
			}
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%lld", s, &m);
		for (i=0; s[i]; i++)
		{
			ss[s[i]-'a']++;
		}
		len = i;
		for (k=0; k<len; k++)
		{
			for (i=0; i<N; i++)
			{
				if (ss[i])
				{
					for (j=0; j<M; j++)
					{
						tt[j] = tbl[len-k-1][j];
					}
					ss[i]--;
					for (j=0; j<N; j++)
					{
						if (ss[j] > 1)
						{
							for (l=0; l<M; l++)
							{
								tt[l] -= tbl[ss[j]][l];
							}
						}
					}
					cc = 1;
					for (j=0; j<M; j++)
					{
						while (tt[j]--)
						{
							cc *= pri[j];
						}
					}
					if (cc > m)
					{
						break;
					}
					ss[i]++;
					m -= cc;
				}
			}
			ans[k] = i+'a';
		}
		ans[k] = 0;
		puts(ans);
	}
	return 0;
}
