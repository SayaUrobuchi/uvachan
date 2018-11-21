#include<iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int ex[1048576], ey[1048576], ew[1048576], idx[1048576];
int par[1048576], num[1048576];

bool cmp(int p, int q)
{
	return ew[p] < ew[q];
}

int getpar(int p)
{
	if (par[p] < 0)
	{
		return p;
	}
	return par[p] = getpar(par[p]);
}

int main() {
	int n, m, st, ed, i, j, k, p, q;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d", &st, &ed);
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &ex[i], &ey[i], &ew[i]);
			idx[i] = i;
		}
		sort(idx, idx+m, cmp);
		memset(par, -1, sizeof(par));
		memset(num, 0, sizeof(num));
		for (i=0, j=0; i<m&&j<2; i++)
		{
			k = idx[i];
			p = getpar(ex[k]);
			q = getpar(ey[k]);
			if (j == 1)
			{
				if (p == q && getpar(st) == p)
				{
					printf(" %d\n", ew[k]);
					break;
				}
				else if (p != q)
				{
					if (getpar(st) == p && num[q])
					{
						printf(" %d\n", ew[k]);
						break;
					}
					else if (getpar(st) == q && num[p])
					{
						printf(" %d\n", ew[k]);
						break;
					}
				}
			}
			if (p != q)
			{
				par[p] = q;
				num[q] += num[p];
			}
			else
			{
				num[p] = 1;
			}
			p = getpar(st);
			q = getpar(ed);
			if (p == q)
			{
				if (j == 0)
				{
					printf("%d", ew[k]);
					++j;
					if (num[p])
					{
						printf(" %d\n", ew[k]);
						break;
					}
				}
			}
		}
	}
	return 0;
}
