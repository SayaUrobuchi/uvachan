#include <stdio.h>

char s[1048576];

int main()
{
	int count, res, cnt, i;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		res = 0;
		cnt = 0;
		for (i=0; s[i]; i++)
		{
			if (s[i] == 'O')
			{
				++cnt;
				res += cnt;
			}
			else
			{
				cnt = 0;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
