#include <stdio.h>
#include <string.h>

int cnt[3], tbl[127];
char s[1024];

int main()
{
	int m, i, ans;
	tbl['T'] = 0;
	tbl['C'] = 1;
	tbl['G'] = 2;
	while (scanf("%s", s) == 1)
	{
		memset(cnt, 0, sizeof(cnt));
		for (i=0; s[i]; i++)
		{
			cnt[tbl[s[i]]]++;
		}
		for (i=0, m=2147483647, ans=0; i<3; i++)
		{
			ans += cnt[i] * cnt[i];
			if (cnt[i] < m)
			{
				m = cnt[i];
			}
		}
		printf("%d\n", ans+7*m);
	}
	return 0;
}
