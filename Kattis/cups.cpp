#include <stdio.h>
#include <algorithm>

int ary[32], idx[32];
char s0[64], s1[64], nam[32][64];

int comp(int p, int q)
{
	return ary[p] < ary[q];
}

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s%s", s0, s1);
			if (*s0 <= '9')
			{
				sscanf(s0, "%d", &ary[i]);
				ary[i] >>= 1;
				sprintf(nam[i], s1);
			}
			else
			{
				sscanf(s1, "%d", &ary[i]);
				sprintf(nam[i], s0);
			}
			idx[i] = i;
		}
		std::sort(idx, idx+n, comp);
		for (i=0; i<n; i++)
		{
			puts(nam[idx[i]]);
		}
	}
	return 0;
}
