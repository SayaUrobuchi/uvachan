#include <stdio.h>
#include <string.h>

int n, m;
int used[4005], rev[2005], mrk[4005], pptr[4005], map[4005][2005];
int mat[2005];

int match(int nd);

int domat(int nd)
{
	used[n+nd] = 1;
	if(used[rev[nd]] == 0 && match(rev[nd]))
	{
		return 1;
	}
	return 0;
}

int match(int nd)
{
	int i, tar;
	used[nd] = 1;
	for(i=0; i<pptr[nd]; i++)
	{
		tar = map[nd][i];
		if(rev[tar] == -1)
		{
			rev[tar] = nd;
			mat[nd] = tar;
			return 1;
		}
		else if(used[n+tar] == 0)
		{
			if(domat(tar))
			{
				rev[tar] = nd;
				mat[nd] = tar;
				return 1;
			}
		}
	}
	return 0;
}

void dfs(int tar, int f)
{
	int i;
	if(mrk[tar] == 1)
	{
		return;
	}
	mrk[tar] = f;
	for(i=0; i<pptr[tar]; i++)
	{
		if(tar >= n)
		{
			dfs(map[tar][i], f^1);
		}
		else
		{
			dfs(n+map[tar][i], f^1);
		}
	}
}

int main()
{
	int o, i, j, r, c, res;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(n == 0 && m == 0 && o == 0)
		{
			break;
		}
		memset(pptr, 0, sizeof(pptr));
		for(i=0; i<o; i++)
		{
			scanf("%d%d", &r, &c);
			r--;
			c--;
			map[r][pptr[r]++] = c;
			map[n+c][pptr[n+c]++] = r;
		}
		memset(mat, -1, sizeof(mat));
		memset(rev, -1, sizeof(rev));
		for(i=0, res=0; i<n; i++)
		{
			if(mat[i] == -1)
			{
				memset(used, 0, sizeof(used));
				res += match(i);
			}
		}
		printf("%d", res);
		memset(mrk, -1, sizeof(mrk));
		for(i=0; i<n; i++)
		{
			if(mat[i] == -1)
			{
				for(j=0; j<pptr[i]; j++)
				{
					if(rev[map[i][j]] != -1)
					{
						dfs(n+map[i][j], 1);
					}
				}
			}
		}
		for(i=0; i<m; i++)
		{
			if(rev[i] == -1)
			{
				for(j=0; j<pptr[n+i]; j++)
				{
					if(mat[map[n+i][j]] != -1)
					{
						dfs(map[n+i][j], 1);
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			if(mat[i] != -1)
			{
				if(mrk[i])
				{
					printf(" r%d", i+1);
					mrk[mat[i]+n] = 0;
				}
			}
		}
		for(i=0; i<m; i++)
		{
			if(rev[i] != -1 && mrk[i+n])
			{
				printf(" c%d", i+1);
			}
		}
		printf("\n");
	}
	return 0;
}
