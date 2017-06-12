#include <stdio.h>
#include <string.h>

int cs[105], cap[105][105], con[105][105], cos[105][105], used[105], from[105];
int inq[100005], qp[100005], qs[100005];

int main()
{
	int n, m, i, j, k, l, p, q, c, s, ts, tp, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		memset(cs, 0, sizeof(cs));
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &c);
			con[p][cs[p]] = q;
			cap[p][q] = 1;
			cos[p][q] = c;
			cs[p]++;
			con[q][cs[q]] = p;
			cap[q][p] = 1;
			cos[q][p] = c;
			cs[q]++;
		}
		for(l=0, ans=0; l<2; l++)
		{
			memset(used, 0x7F, sizeof(used));
			memset(inq, 0, sizeof(inq));
			qp[0] = 1;
			from[1] = -1;
			inq[1] = 1;
			used[1] = 0;
			for(i=0, j=1; i<j; i++)
			{
				p = qp[i];
				s = used[p];
				inq[p] = 0;
				for(k=0; k<cs[p]; k++)
				{
					tp = con[p][k];
					if(!cap[p][tp])
					{
						continue;
					}
					ts = s + cos[p][tp];
					if(ts < used[tp])
					{
						used[tp] = ts;
						from[tp] = p;
						if(!inq[tp])
						{
							inq[tp] = 1;
							qp[j] = tp;
							j++;
						}
					}
				}
			}
			if(used[n] > 1048576)
			{
				break;
			}
			ans += used[n];
			for(i=n; from[i]!=-1; i=from[i])
			{
				cap[from[i]][i]--;
				cap[i][from[i]]++;
				cos[i][from[i]] = -cos[from[i]][i];
			}
		}
		if(l < 2)
		{
			printf("Back to jail\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
