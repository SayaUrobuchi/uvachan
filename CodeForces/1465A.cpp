#include <iostream>

char s[1048576];

int main()
{
	int count, n, i, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &n, s);
		for (i=0, t=0; s[i]; i++)
		{
			if (s[i] == ')')
			{
				++t;
			}
			else
			{
				t = 0;
			}
		}
		puts(t>(n>>1)?"Yes":"No");
	}
	return 0;
}
