#include <stdio.h>
#include <algorithm>

#define N 20005

int w[N], h[N], idx[N], ary[N];

bool comp(const int& a, const int &b)
{
	return w[a]==w[b] ? h[b]<h[a] : w[a]<w[b];
}

int main()
{
	int count, n, i, j, k, l, r, c, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &w[i], &h[i]);
			idx[i] = i;
		}
		std::sort(idx, idx+n, comp);
		for (i=0, j=0; i<n; i++)
		{
			k = h[idx[i]];
			t = j;
			for (l=0, r=j-1; l<=r; )
			{
				c = ((l+r) >> 1);
				if (k > ary[c])
				{
					t = c;
					r = c-1;
				}
				else
				{
					l = c+1;
				}
			}
			ary[t] = k;
			if (t == j)
			{
				++j;
			}
		}
		printf("%d\n", j);
	}
	return 0;
}
