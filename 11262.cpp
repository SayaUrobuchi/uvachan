#include <stdio.h>
#include <string.h>

#define INF 3000

int rnum, bnum, dislim;
int red[101], blue[101];
int px[101], py[101];
int map[101][101];
int rused[101], bused[101];
int assigned[101];
char buf[101];

int fill(int);

int getdist(int x, int y)
{
	return x*x + y*y;
}

int assign(int now)
{
	if(!assigned[now])
	{
		return 1;
	}
	else if(!rused[assigned[now]-1])
	{
		return fill(assigned[now]-1);
	}
	return 0;
}

int fill(int now)
{
	int i;
	rused[now] = 1;
	for(i=0; i<bnum; i++)
	{
		if(map[now][i] <= dislim && !bused[i])
		{
			bused[i] = 1;
			if(assign(i))
			{
				assigned[i] = now + 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, n, m, i, j, c, ans, left, right, center;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0, bnum=rnum=0; i<n; i++)
		{
			scanf("%d%d%s", &px[i], &py[i], buf);
			if(!strcmp(buf, "blue"))
			{
				blue[bnum++] = i;
			}
			else
			{
				red[rnum++] = i;
			}
		}
		if(bnum < m || rnum < m)
		{
			printf("Impossible\n");
		}
		else
		{
			for(i=0; i<rnum; i++)
			{
				for(j=0; j<bnum; j++)
				{
					map[i][j] = getdist(px[red[i]]-px[blue[j]], py[red[i]]-py[blue[j]]);
				}
			}
			for(left=0, right=INF; left<=right; )
			{
				center = left + right;
				center /= 2;
				dislim = center * center;
				memset(assigned, 0, sizeof(assigned));
				for(i=0, c=0; i<rnum&&c<m; i++)
				{
					memset(bused, 0, sizeof(bused));
					memset(rused, 0, sizeof(rused));
					c += fill(i);
				}
				if(c == m)
				{
					ans = center;
					right = center - 1;
				}
				else
				{
					left = center + 1;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
