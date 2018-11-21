#include <stdio.h>
#include <string.h>

int tbl[1505][1505], cnt[1000005], map[1505][1505], coln[1505], rown[1505];
int row[1505][10], col[1505][10], arx[3000005], ary[3000005];

int ab(int t)
{
	return t<0 ? -t : t;
}

void rinsert(int loc, int *arr, int *arrn, int tar)
{
	int i;
	arr[*arrn] = tar;
	for(i=*arrn; i>0; i--)
	{
		if(tbl[loc][arr[i]] > tbl[loc][arr[i-1]])
		{
			tar = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = tar;
		}
		else
		{
			break;
		}
	}
	if(*arrn < 4)
	{
		(*arrn)++;
	}
}

void cinsert(int loc, int *arr, int *arrn, int tar)
{
	int i;
	arr[*arrn] = tar;
	for(i=*arrn; i>0; i--)
	{
		if(tbl[arr[i]][loc] > tbl[arr[i-1]][loc])
		{
			tar = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = tar;
		}
		else
		{
			break;
		}
	}
	if(*arrn < 4)
	{
		(*arrn)++;
	}
}

int rfind(int loc, int *arr, int arrn, int tar, int val)
{
	int i;
	for(i=0; i<arrn; i++)
	{
		if(ab(arr[i]-tar) >= 2 && map[loc][arr[i]] < val)
		{
			return tbl[loc][arr[i]];
		}
	}
	return -10000005;
}

int cfind(int loc, int *arr, int arrn, int tar, int val)
{
	int i;
	for(i=0; i<arrn; i++)
	{
		if(ab(arr[i]-tar) >= 2 && map[arr[i]][loc] < val)
		{
			return tbl[arr[i]][loc];
		}
	}
	return -10000005;
}

int main()
{
	int n, i, j, k, t, x, y, mx, sx, sy, tt, ans;
	while(scanf("%d", &n) == 1)
	{
		scanf("%d%d", &sx, &sy);
		memset(cnt, 0, sizeof(cnt));
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
				cnt[map[i][j]]++;
			}
			coln[i] = rown[i] = 0;
		}
		coln[n+1] = rown[n+1] = 0;
		for(i=1; i<=1000001; i++)
		{
			cnt[i] += cnt[i-1];
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				cnt[map[i][j]]--;
				arx[cnt[map[i][j]]] = i;
				ary[cnt[map[i][j]]] = j;
			}
		}
		tbl[sx][sy] = 1;
		rinsert(sx, row[sx], &rown[sx], sy);
		cinsert(sy, col[sy], &coln[sy], sx);
		for(i=cnt[map[sx][sy]+1], tt=n*n, ans=1; i<tt; i++)
		{
			x = arx[i];
			y = ary[i];
			mx = -10000005;
			t = rfind(x-1, row[x-1], rown[x-1], y, map[x][y]);
			if(t > mx)
			{
				mx = t;
			}
			t = rfind(x+1, row[x+1], rown[x+1], y, map[x][y]);
			if(t > mx)
			{
				mx = t;
			}
			t = cfind(y-1, col[y-1], coln[y-1], x, map[x][y]);
			if(t > mx)
			{
				mx = t;
			}
			t = cfind(y+1, col[y+1], coln[y+1], x, map[x][y]);
			if(t > mx)
			{
				mx = t;
			}
			mx++;
			tbl[x][y] = mx;
			rinsert(x, row[x], &rown[x], y);
			cinsert(y, col[y], &coln[y], x);
			if(mx > ans)
			{
				ans = mx;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
