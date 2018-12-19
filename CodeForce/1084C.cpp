#include <stdio.h>

const int M = 1000000007;

char s[131072];

int main()
{
	int i, cnt, ans;
	while (scanf("%s", s) == 1)
	{
		cnt = 0;
		ans = 0;
		for (i=0; s[i]; i++)
		{
			if (s[i] == 'a')
			{
				cnt++;
			}
			else if (s[i] == 'b')
			{
				ans = (ans + ((long long)ans * cnt) + cnt) % M;
				cnt = 0;
			}
		}
		ans = (ans + ((long long)ans * cnt) + cnt) % M;
		printf("%d\n", ans);
	}
	return 0;
}
