#include <stdio.h>
#include <string.h>

int pnum[105], has[105][105], map[105][105];
int used[105], q[105], c[105], frm[105];

int main()
{
	int n, m, i, j, k, f, tar, now, cc, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(pnum, 0, sizeof(pnum));
		memset(has, 0, sizeof(has));
		for(i=2; i<n; i++)
		{
			scanf("%d%d", &tar, &cc);
			map[tar][pnum[tar]] = tar+n;
			has[tar][tar+n] = cc;
			pnum[tar]++;
			map[tar+n][pnum[tar+n]] = tar;
			pnum[tar+n]++;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &now, &tar, &cc);
			map[now+n][pnum[now+n]] = tar;
			has[now+n][tar] = cc;
			pnum[now+n]++;
			map[tar][pnum[tar]] = now+n;
			pnum[tar]++;
			map[tar+n][pnum[tar+n]] = now;
			has[tar+n][now] = cc;
			pnum[tar+n]++;
			map[now][pnum[now]] = tar+n;
			pnum[now]++;
		}
		ans = 0;
		while(1)
		{
			q[0] = 1+n;
			memset(used, 0, sizeof(used));
			used[1+n] = 1;
			for(i=0, j=1; i<j; i++)
			{
				now = q[i];
				for(k=0; k<pnum[now]; k++)
				{
					tar = map[now][k];
					if(has[now][tar] && used[tar] == 0)
					{
						used[tar] = 1;
						q[j] = tar;
						c[j] = has[now][tar];
						frm[j] = i;
						if(tar == n)
						{
							break;
						}
						j++;
					}
				}
				if(k < pnum[now])
				{
					break;
				}
			}
			if(used[n] == 0)
			{
				break;
			}
			for(now=j, f=2147483647; now; now=frm[now])
			{
				if(c[now] < f)
				{
					f = c[now];
				}
			}
			ans += f;
			for(now=j; now; now=frm[now])
			{
				has[q[frm[now]]][q[now]] -= f;
				has[q[now]][q[frm[now]]] += f;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
