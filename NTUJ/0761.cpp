#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, ans;
int next[10005], box[10005][3], bnd[1005][1005][55], used[55];
long long req[10005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void dfs(int hei, long long stat, int w, int l, int dep)
{
	int i, j, k;
	int tbl[155][4], p, pp;
	if(hei > ans)
	{
		ans = hei;
	}
	if(stat == (1ll<<(n+1))-2)
	{
		return;
	}
	for(i=1, p=0; i<=n; i++)
	{
		j = i;
		if(used[i] == 0 && (req[j]==0 || (stat & req[j])))
		{
			if(box[j][1] <= w && box[j][2] <= l)
			{
				for(k=0; k<p; k++)
				{
					if(tbl[k][0] == box[j][1] && tbl[k][1] == box[j][2])
					{
						if(tbl[k][2] < box[j][0])
						{
							tbl[k][2] = box[j][0];
							tbl[k][3] = j;
						}
						break;
					}
				}
				if(k == p)
				{
					tbl[k][0] = box[j][1];
					tbl[k][1] = box[j][2];
					tbl[k][2] = box[j][0];
					tbl[k][3] = j;
					p++;
				}
			}
			if(/*box[j][0]!=box[j][1] && */box[j][0] <= w && box[j][2] <= l)
			{
				for(k=0; k<p; k++)
				{
					if(tbl[k][0] == box[j][0] && tbl[k][1] == box[j][2])
					{
						if(tbl[k][2] < box[j][1])
						{
							tbl[k][2] = box[j][1];
							tbl[k][3] = j;
						}
						break;
					}
				}
				if(k == p)
				{
					tbl[k][0] = box[j][0];
					tbl[k][1] = box[j][2];
					tbl[k][2] = box[j][1];
					tbl[k][3] = j;
					p++;
				}
			}
			if(/*(box[j][0]!=box[j][1]||box[j][1]!=box[j][2]) && */box[j][0] <= w && box[j][1] <= l)
			{
				for(k=0; k<p; k++)
				{
					if(tbl[k][0] == box[j][0] && tbl[k][1] == box[j][1])
					{
						if(tbl[k][2] < box[j][2])
						{
							tbl[k][2] = box[j][2];
							tbl[k][3] = j;
						}
						break;
					}
				}
				if(k == p)
				{
					tbl[k][0] = box[j][0];
					tbl[k][1] = box[j][1];
					tbl[k][2] = box[j][2];
					tbl[k][3] = j;
					p++;
				}
			}
		}
	}
	for(i=0; i<p; i++)
	{
		used[tbl[i][3]] = 1;
		dfs(hei+tbl[i][2], stat+(1ll<<tbl[i][3]), tbl[i][0], tbl[i][1], dep+1);
		used[tbl[i][3]] = 0;
	}
}

int main()
{
	int count, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%d%d%d", &box[i][0], &box[i][1], &box[i][2]);
			qsort(box[i], 3, sizeof(int), comp);
		}
		memset(req, 0, sizeof(req));
		next[0] = 1;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(i != j)
				{
					for(k=0; k<3; k++)
					{
						if(box[i][k] >= box[i][j])
						{
							break;
						}
					}
					if(k == 3)
					{
						req[i] |= (1ll<<j);
					}
				}
			}
			next[i] = i+1;
		}
		memset(used, 0, sizeof(used));
		next[i-1] = 0;
		ans = 0;
		dfs(0, 0, 1000, 1000, 0);
		printf("%d\n", ans);
	}
	return 0;
}
