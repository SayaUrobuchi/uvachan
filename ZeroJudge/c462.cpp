#include <stdio.h>

int ary[1048576];
char s[1048576];

int main()
{
	int n, i, j, k, m, ans, t, last;
	while (scanf("%d%s", &n, s) == 2)
	{
		for (i=0, j=-1, last=-1; s[i]; i++)
		{
			k = (s[i] >= 'a' ? 1 : 0);
			if (k != last)
			{
				j++;
				ary[j] = 0;
				last = k;
			}
			ary[j]++;
		}
		m = j+1;
		ans = 0;
		for (i=0, t=0; i<m; i++)
		{
			if (ary[i] == n)
			{
				t += n;
				if (t > ans)
				{
					ans = t;
				}
			}
			else if (ary[i] < n)
			{
				t = 0;
			}
			else
			{
				t += n;
				if (t > ans)
				{
					ans = t;
				}
				t = n;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
