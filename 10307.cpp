#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int recog[51][51];
int aryx[101], aryy[101];
int queuex[2500], queuey[2500];
int step[2500];
int chk[51][51];
int index[11000];
int edgex[11000], edgey[11000];
int length[11000];
int parent[110];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char map[51][51];

int comp(const void *p, const void *q)
{
	return length[*(int*)p] - length[*(int*)q];
}

int getparent(int now)
{
	if(parent[now])
	{
		return parent[now] = getparent(parent[now]);
	}
	return now;
}

int valid(int x, int y)
{
	return map[x][y] != '#';
}

int main()
{
	int count, n, m, i, j, k, p, q, c, s, x, y, tx, ty, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		memset(recog, 0, sizeof(recog));
		gets(map[0]);
		for(i=0, k=1; i<n; i++)
		{
			gets(map[i]);
			for(j=0; j<n; j++)
			{
				if(map[i][j] == 'S' || map[i][j] == 'A')
				{
					recog[i][j] = k;
					aryx[k] = i;
					aryy[k++] = j;
					map[i][j] = ' ';
				}
			}
		}
		for(i=1, c=0; i<k; i++)
		{
			queuex[0] = aryx[i];
			queuey[0] = aryy[i];
			step[0] = 0;
			memset(chk, 0, sizeof(chk));
			chk[aryx[i]][aryy[i]] = 1;
			for(p=0, q=1; p<q; p++)
			{
				x = queuex[p];
				y = queuey[p];
				s = step[p];
				if(recog[x][y] && s)
				{
					index[c] = c;
					edgex[c] = i;
					edgey[c] = recog[x][y];
					length[c++] = s;
				}
				for(j=0; j<4; j++)
				{
					tx = x + wayx[j];
					ty = y + wayy[j];
					if(valid(tx, ty) && !chk[tx][ty])
					{
						chk[tx][ty] = 1;
						queuex[q] = tx;
						queuey[q] = ty;
						step[q++] = s + 1;
					}
				}
			}
		}
		qsort(index, c, sizeof(int), comp);
		memset(parent, 0, sizeof(parent));
		for(i=0, ans=0; i<c; i++)
		{
			j = index[i];
			if(getparent(edgex[j]) != getparent(edgey[j]))
			{
				parent[getparent(edgex[j])] = getparent(edgey[j]);
				ans += length[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
