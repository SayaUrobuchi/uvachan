/*
	ID: sa072682
	LANG: C
	TASK: rect1
*/
#include <stdio.h>

int ary[5000][5], temp[5], tbl[2501];
char map[50][50];

char valid(int* p)
{
	return p[0] <= p[2] && p[1] <= p[3];
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, o, i, j, k, c, *p, *q, *r;
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &o);
	ary[0][0] = ary[0][1] = 0;
	ary[0][2] = n - 1;
	ary[0][3] = m - 1;
	ary[0][4] = 1;
	k = 1;
	while(o--)
	{
		scanf("%d%d%d%d%d", &ary[k][0], &ary[k][1], &ary[k][2], &ary[k][3], &ary[k][4]);
		ary[k][2]--;
		ary[k][3]--;
		p = ary[k];
		temp[0] = p[0];
		temp[1] = p[1];
		temp[2] = p[2];
		temp[3] = p[3];
		temp[4] = p[4];
		p = temp;
		for(i=k-1, k++; i>-1; i--)
		{
			q = ary[i];
			if(p[0] <= q[2] && q[0] <= p[2] && p[1] <= q[3] && q[1] <= p[3])
			{
				r = ary[k];
				r[0] = q[0];
				r[1] = p[3] + 1;
				r[2] = q[2];
				r[3] = q[3];
				r[4] = q[4];
				k += valid(r);
				r = ary[k];
				r[0] = q[0];
				r[1] = q[1];
				r[2] = q[2];
				r[3] = p[1] - 1;
				r[4] = q[4];
				k += valid(r);
				r = ary[k];
				r[0] = q[0];
				r[1] = max(p[1], q[1]);
				r[2] = p[0] - 1;
				r[3] = min(p[3], q[3]);
				r[4] = q[4];
				k += valid(r);
				r = ary[k];
				r[0] = p[2] + 1;
				r[1] = max(p[1], q[1]);
				r[2] = q[2];
				r[3] = min(p[3], q[3]);
				r[4] = q[4];
				k += valid(r);
				r = ary[k-1];
				q[0] = r[0];
				q[1] = r[1];
				q[2] = r[2];
				q[3] = r[3];
				q[4] = r[4];
				k--;
				/*printf("%d: \n", i);
				for(j=0; j<k; j++)
				{
					r = ary[j];
					printf("XDDD %d:  %d %d %d %d %d\n", j, r[0], r[1], r[2], r[3], r[4]);
				}*/
			}
		}
		/*for(i=0; i<k; i++)
		{
			r = ary[i];
			printf("%d:  %d %d %d %d %d\n", i, r[0], r[1], r[2], r[3], r[4]);
			for(j=r[0]; j<=r[2]; j++)
			{
				for(c=r[1]; c<=r[3]; c++)
				{
					map[c][j] = 48 + r[4];
				}
			}
		}
		for(i=0; i<n; i++)
		{
			printf("%s\n", map[i]);
		}*/
	}
	for(i=0; i<k; i++)
	{
		p = ary[i];
		tbl[p[4]] += (p[2] - p[0] + 1) * (p[3] - p[1] + 1);
		/*printf("%d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4]);*/
	}
	for(i=1; i<2501; i++)
	{
		if(tbl[i])
		{
			printf("%d %d\n", i, tbl[i]);
		}
	}
	scanf(" ");
	return 0;
}
