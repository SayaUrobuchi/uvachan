#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int used[905][905], dp[905][905];
int px[455], py[455], pp[455], pxp[455], pyp[455], list[905];

int comp(const void *p, const void *q)
{
	if(py[*(int*)p] != py[*(int*)q])
	{
		return py[*(int*)p] > py[*(int*)q] ? 1 : -1;
	}
	return px[*(int*)p] > px[*(int*)q] ? 1 : -1;
}

int comp2(const void *p, const void *q)
{
	return *(int*)p < *(int*)q ? -1 : 1;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int recurs(int p, int q)
{
	int a, b, t, i, j, c, res;
	if(p >= q)
	{
		return 0;
	}
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	dp[p][q] = 0;
	for(a=0, b=n-1, t=-1; a<=b; )
	{
		c = ((a+b)>>1);
		if(py[pp[c]] <= list[q])
		{
			t = c;
			a = c+1;
		}
		else
		{
			b = c-1;
		}
	}
	if(t == -1)
	{
		return 0;
	}
	res = 0;
	for(j=t; j>=0; j--)
	{
		if(py[pp[j]] != list[q] || px[pp[j]] < list[p])
		{
			break;
		}
		if(px[pp[j]] == list[p] && py[pp[j]] == list[q])
		{
			for(i=j-1, res=1; i>=0; i--)
			{
				if(py[pp[i]] != py[pp[j]] || px[pp[i]] != px[pp[j]])
				{
					break;
				}
				res++;
			}
			break;
			//printf("XD %d %d: %d\n", list[p], list[q], max(recurs(p, p+1)+recurs(p+1, q), recurs(p, q-1)+recurs(q-1, q)) + res);
			//printf("ikuso (%d, %d)+(%d, %d) maxx (%d, %d)+(%d, %d)\n", list[p], list[p+1], list[p+1], list[q], list[p], list[q-1], list[q-1], list[q]);
		}
	}
	dp[p][q] = res;
	for(i=t; i>=0; i--)
	{
		if(py[pp[i]] < px[pp[t]])
		{
			break;
		}
		if(px[pp[i]] < list[p])
		{
			continue;
		}
		if(px[pp[i]] == py[pp[i]] || (px[pp[i]] == list[p] && py[pp[i]] == list[q]))
		{
			continue;
		}
		//printf("ohoh %d %d ask (%d, %d), (%d, %d)..\n", list[p], list[q], list[p], list[pxp[pp[i]]-1], list[pxp[pp[i]]], list[q]);
		dp[p][q] = max(dp[p][q], recurs(p, pxp[pp[i]])+recurs(pxp[pp[i]], pyp[pp[i]])+res);
		//printf("%d %d!! %d, %d\n", list[p], list[q], i, dp[p][q]);
	}
	return dp[p][q];
}

int main()
{
	int count, i, j, p, q, c, pn, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, pn=0, res=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			if(px[i] == py[i])
			{
				res++;
			}
			list[pn++] = px[i];
			list[pn++] = py[i];
			pp[i] = i;
		}
		qsort(pp, n, sizeof(int), comp);
		qsort(list, pn, sizeof(int), comp2);
		for(i=1, j=1; i<pn; i++)
		{
			if(list[i] != list[i-1])
			{
				list[j++] = list[i];
			}
		}
		pn = j;
		for(i=0; i<n; i++)
		{
			for(p=0, q=pn-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(list[c] == px[i])
				{
					pxp[i] = c;
					break;
				}
				else if(list[c] > px[i])
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			for(p=0, q=pn-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(list[c] == py[i])
				{
					pyp[i] = c;
					break;
				}
				else if(list[c] > py[i])
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recurs(0, pn-1)+res);
	}
	return 0;
}
