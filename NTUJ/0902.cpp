#include <stdio.h>
#include <string.h>

int mnum[1005], map[1005][5005], cmap[1005][5005], way[5005][1005];
int qq[5005005], qs[5005005], used[5005][1005];
char str[1000005], buf[1000005];

int main()
{
	int count, n, m, p, q, i, j, k, mod, len, now, step, tar, chr, ans, idx, tt;
	char *ptr;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &mod);
		scanf("%s", str);
		len = strlen(str);
		memset(mnum, 0, sizeof(mnum));
		for(i=0; i<m; i++)
		{
			scanf("%d%d%s", &p, &q, buf);
			map[p][mnum[p]] = q;
			cmap[p][mnum[p]] = *buf;
			mnum[p]++;
		}
		memset(way, 0, sizeof(way));
		for(i=0; i<n; i++)
		{
			qq[i] = i;
			qs[i] = 0;
			way[0][i] = 1;
		}
		memset(used, 0, sizeof(used));
		for(i=0, j=n; i<j; i++)
		{
			now = qq[i];
			step = qs[i];
			if(str[step] == 0)
			{
				continue;
			}
			for(k=0; k<mnum[now]; k++)
			{
				tar = map[now][k];
				chr = cmap[now][k];
				if(chr == str[step])
				{
					if(used[step+1][tar] == 0)
					{
						used[step+1][tar] = 1;
						qq[j] = tar;
						qs[j] = step+1;
						j++;
					}
					way[step+1][tar] += way[step][now];
					way[step+1][tar] %= mod;
				}
			}
		}
		for(i=0, ans=0; i<n; i++)
		{
			ans += way[len][i];
			ans %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
