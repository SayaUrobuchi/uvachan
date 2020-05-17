#include <stdio.h>

char s[1024];
const char *ss = "PER";

int main()
{
	int i, ans;
	while (scanf("%s", s) == 1)
	{
		for (i=0, ans=0; s[i]; i++)
		{
			if (s[i] != ss[i%3])
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
