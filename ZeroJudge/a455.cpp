#include <stdio.h>
#include <string.h>
#include <algorithm>

#define M 1048576
#define L 32

int id, n, m, lim;
int box[64], nxt[1024], tbl[M], lost[1024];

void dfs(int nid, int cur, int st, int lst, int depth, int sukima)
{
	int gg, i, j, last, c;
	if (sukima > lost[id])
	{
		return;
	}
	if (nid >= n)
	{
		lim++;
		if (depth > id)
		{
			id = depth;
		}
		return;
	}
	gg = 1;
	i = st;
	if (!cur && nid && box[nid] == box[nid-1])
	{
		i = lst;
	}
	for (j=nxt[i], c=0; j&&c<3; i=j, j=nxt[j], c++)
	{
		if (cur+j <= box[nid])
		{
			if (cur+j+j > box[nid] && nxt[j] && cur+nxt[j] <= box[nid])
			{
				c--;
				continue;
			}
			gg = 0;
			tbl[j]--;
			if (!tbl[j])
			{
				nxt[i] = nxt[j];
			}
			dfs(nid, cur+j, i, cur?lst:i, depth+1, sukima);
			if (!tbl[j])
			{
				nxt[i] = j;
			}
			tbl[j]++;
			if (id >= m || lim > L)
			{
				return;
			}
		}
		else
		{
			break;
		}
		last = j;
	}
	if (gg)
	{
		dfs(nid+1, 0, 0, lst, depth, sukima+box[nid]-cur);
	}
}

void calc()
{
	int i, j, nid, sum;
	id = 0;
	for (i=0, j=nxt[i], nid=0, sum=0; nid<n&&j; i=j, j=nxt[j])
	{
		while (nid < n && sum+j > box[nid])
		{
			nid++;
			sum = 0;
		}
		if (nid < n && sum+j <= box[nid])
		{
			sum += j;
			id++;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int i, j, z, t, last, sum, cur, csum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &box[i]);
			sum += box[i];
		}
		std::sort(box, box+n);
		z = 0;
		memset(tbl, 0, sizeof(tbl));
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			if (t > box[n-1])
			{
				continue;
			}
			if (!t)
			{
				z++;
			}
			else
			{
				tbl[t]++;
			}
		}
		for (i=1, last=0, cur=0, csum=0; i<M; i++)
		{
			if (tbl[i])
			{
				if (csum+i > sum)
				{
					break;
				}
				nxt[last] = i;
				last = i;
				for (j=0; j<tbl[i]&&csum+i<=sum; j++)
				{
					csum += i;
					lost[cur] = sum-csum;
					cur++;
				}
				if (j < tbl[i])
				{
					tbl[i] = j;
					break;
				}
			}
		}
		m = cur;
		nxt[last] = 0;
		calc();
		dfs(0, 0, 0, 0, 0, 0);
		printf("%d\n", id);
	}
	return 0;
}
