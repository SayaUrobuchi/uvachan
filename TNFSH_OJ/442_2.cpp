#include<iostream>
#include <algorithm>
using namespace std;

int tbl[10485760], ary[1024];
int ans0[10485760], ans1[10485760];

int main() {
	int i, j, k, n, m, t, u, p, q, c, ba, bb, dif, res;
	for (i=3; i<4096; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=i+i; j<10485760; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &m);
			if (ans0[m])
			{
				printf("%d %d\n", ans0[m], ans1[m]);
				continue;
			}
			for (j=0, k=m; k>1; j++)
			{
				if (k & 1)
				{
					if (tbl[k])
					{
						ary[j] = tbl[k];
					}
					else
					{
						ary[j] = k;
					}
				}
				else
				{
					ary[j] = 2;
				}
				while (!(k % ary[j]))
				{
					k /= ary[j];
				}
				if (ans0[k])
				{
					ary[++j] = ans1[k];
					if (ans0[k] != 1)
					{
						ary[++j] = ans0[k];
					}
					j++;
					break;
				}
			}
			if (j == 1)
			{
				ans0[m] = 1;
				ans1[m] = ary[0];
				printf("1 %d\n", ary[0]);
			}
			else
			{
				sort(ary, ary+j);
				ans0[m] = ary[j-2];
				ans1[m] = ary[j-1];
				printf("%d %d\n", ary[j-2], ary[j-1]);
			}
		}
	}
	return 0;
}
