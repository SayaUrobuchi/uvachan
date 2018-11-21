#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long a0[1024], a1[1024], a00[1024];
char s[1024];

int comp(const void *p, const void *q)
{
	return *(unsigned long long*)p < *(unsigned long long*)q ? -1 : 1;
}

unsigned long long trans(char *s)
{
	int i;
	unsigned long long res;
	res = 0;
	for (i=0; s[i]; i++)
	{
		res = ((res<<1) + s[i]-'0');
	}
	return res;
}

int main()
{
	int n, m, i, j, ans, count, cas, c;
	unsigned long long mask, t;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			a0[i] = trans(s);
			a00[i] = a0[i];
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			a1[i] = trans(s);
		}
		qsort(a1, n, sizeof(a1[0]), comp);
		ans = m+1;
		for (i=0; i<n; i++)
		{
			mask = (a00[i] ^ a1[0]);
			t = mask;
			c = 0;
			while (t)
			{
				c += (t&1);
				t >>= 1;
			}
			if (c < ans)
			{
				for (j=0; j<n; j++)
				{
					a0[j] ^= mask;
				}
				qsort(a0, n, sizeof(a0[0]), comp);
				for (j=0; j<n&&a0[j]==a1[j]; j++);
				if (j >= n)
				{
					ans = c;
				}
				for (j=0; j<n; j++)
				{
					a0[j] ^= mask;
				}
			}
		}
		if (ans == m+1)
		{
			printf("Case #%d: IMPOSSIBLE\n", ++cas);
		}
		else
		{
			printf("Case #%d: %d\n", ++cas, ans);
		}
	}
	return 0;
}
