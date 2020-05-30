#include <stdio.h>
#include <algorithm>

int red[1024], rn;
int blue[1024], bn;

bool comp(int p, int q)
{
	return p>q;
}

int main()
{
	int cas, count, n, i, t, ans;
	char c;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		rn = bn = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d%c", &t, &c);
			if (c == 'R')
			{
				red[rn++] = t;
			}
			else
			{
				blue[bn++] = t;
			}
		}
		std::sort(red, red+rn, comp);
		std::sort(blue, blue+bn, comp);
		for (i=0, ans=0; i<rn&&i<bn; i++)
		{
			ans += red[i] + blue[i] - 2;
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
