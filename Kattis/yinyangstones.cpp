#include <stdio.h>

char s[1048576];

int main()
{
	int i, ans;
	while (scanf("%s", s) == 1)
	{
		for (i=0, ans=0; s[i]; i++)
		{
			ans += (s[i] == 'B' ? 1 : -1);
		}
		puts(ans?"0":"1");
	}
	return 0;
}
