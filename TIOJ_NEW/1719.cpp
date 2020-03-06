#include <stdio.h>
#include <string.h>
#include <algorithm>

#define M 1024
#define L 16

int id, n, m, lim, ar;
int box[64], nxt[1024], ary[1024], tbl[M], lost[1024];

void dfs(int nid, int cur, int st, int lst, int depth, int sukima)
{
	int gg, i, j, t, last, c;
	if (sukima > lost[id])
	{
		return;
	}
	if (nid >= n)
	{
		lim++;
		if (depth >= id)
		{
			id = depth;
			ar = 1;
		}
		return;
	}
	gg = 1;
	i = st;
	if (!cur && nid && box[nid] == box[nid-1])
	{
		i = lst;
	}
	for (j=nxt[i], c=0; j; i=j, j=nxt[j], c++)
	{
		t = ary[j];
		if (cur+t <= box[nid])
		{
			if (cur+t+t > box[nid] && nxt[j] && cur+ary[nxt[j]] <= box[nid])
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
			dfs(nid, cur+t, i, cur?lst:i, depth+1, sukima);
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
		last = t;
	}
	if (gg)
	{
		dfs(nid+1, 0, 0, lst, depth, sukima+box[nid]-cur);
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
		for (i=1, j=1; i<=m; i++)
		{
			scanf("%d", &t);
			if (!t)
			{
				z++;
			}
			else if (t <= box[n-1])
			{
				ary[j] = t;
				j++;
			}
		}
		m = j;
		std::sort(ary+1, ary+m);
		for (i=1, j=1; j<m; i++)
		{
			ary[i] = ary[j];
			for (t=j, j++; j<m&&ary[j]==ary[t]; j++);
			tbl[i] = j-t;
		}
		m = i;
		for (i=1, last=0, cur=0, csum=0; i<m; i++)
		{
			t = ary[i];
			if (csum+t > sum)
			{
				break;
			}
			nxt[last] = i;
			last = i;
			for (j=0; j<tbl[i]&&csum+t<=sum; j++)
			{
				csum += t;
				lost[cur] = sum-csum;
				cur++;
			}
			if (j < tbl[i])
			{
				tbl[i] = j;
				break;
			}
		}
		m = cur;
		nxt[last] = 0;
		for (id=cur; ; )
		{
			ar = 0;
			dfs(0, 0, 0, 0, 0, 0);
			if (ar)
			{
				break;
			}
			id--;
		}
		printf("%d\n", id);
	}
	return 0;
}
