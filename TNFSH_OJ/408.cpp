#include <stdio.h>
#include <vector>

const int N = 5005;

int used[N], del[N], idx[N], cc[N], dc[N], ccn[N];
int map[N][N];
int qq[N];
std::vector<int> con[N];

int main()
{
	int n, m, i, j, k, p, q, ans, cnt, bfucnt, qf, qe, cur, nxt, pos, rn, jj, mc, dcid, cid;
	cnt = 0;
	bfucnt = 0;
	dcid = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			con[i].clear();
			idx[i] = i;
			cc[i] = 0;
		}
		cid = 0;
		ccn[0] = n;
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			p--;
			q--;
			map[p][q] = con[p].size();
			map[q][p] = con[q].size();
			con[p].push_back(q);
			con[q].push_back(p);
		}
		cnt++;
		ans = 0;
		rn = n;
		mc = rn;
		for (i=1; i<=n; i++)
		{
			/*if (i * mc <= ans)
			{
				continue;
			}*/
			qf = 0;
			qe = 0;
			dcid++;
			dc[0] = dcid;
			for (j=0; j<rn; j++)
			{
				jj = idx[j];
				if (del[jj] != cnt)
				{
					if (con[jj].size() < i)
					{
						qq[qe++] = jj;
						del[jj] = cnt;
						dc[cc[jj]] = dcid;
					}
				}
			}
			if (qe == 0 && i > 1)
			{
				if (i * mc > ans)
				{
					ans = i * mc;
				}
				continue;
			}
			for (; qf<qe; qf++)
			{
				cur = qq[qf];
				for (j=0; j<con[cur].size(); j++)
				{
					nxt = con[cur][j];
					if (del[nxt] != cnt)
					{
						pos = map[nxt][cur];
						con[nxt][pos] = con[nxt][con[nxt].size()-1];
						map[nxt][con[nxt][pos]] = pos;
						con[nxt].pop_back();
						if (con[nxt].size() < i)
						{
							del[nxt] = cnt;
							qq[qe++] = nxt;
							dc[cc[nxt]] = dcid;
							rn--;
						}
					}
				}
			}
			mc = 1;
			bfucnt++;
			for (j=0; j<rn; j++)
			{
				jj = idx[j];
				if (del[jj] == cnt)
				{
					/*rn--;
					idx[j] = idx[rn];
					j--;*/
					continue;
				}
				if (dc[cc[jj]] == dcid)
				{
					if (used[jj] != bfucnt)
					{
						qf = 0;
						qe = 1;
						qq[0] = jj;
						used[jj] = bfucnt;
						cid++;
						for (; qf<qe; qf++)
						{
							cur = qq[qf];
							cc[cur] = cid;
							for (k=0; k<con[cur].size(); k++)
							{
								nxt = con[cur][k];
								if (del[nxt] != cnt && used[nxt] != bfucnt)
								{
									used[nxt] = bfucnt;
									qq[qe++] = nxt;
								}
							}
						}
						ccn[cid] = qe;
						if (i * qe > ans)
						{
							ans = i * qe;
						}
						if (qe > mc)
						{
							mc = qe;
						}
					}
				}
				else
				{
					//printf("%d %d, %d\n", i, ccn[cc[jj]], ans);
					if (i * ccn[cc[jj]] > ans)
					{
						ans = i * ccn[cc[jj]];
					}
					if (ccn[cc[jj]] > mc)
					{
						mc = ccn[cc[jj]];
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
