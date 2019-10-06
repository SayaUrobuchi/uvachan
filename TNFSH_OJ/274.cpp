#include <stdio.h>

char s[1048576];

int check(int p, int q, int r)
{
	for (; p<q; p++, q--)
	{
		if (s[p] != s[q])
		{
			if (!r)
			{
				return 0;
			}
			return check(p+1, q, r-1) || check(p, q-1, r-1);
		}
	}
	return 1;
}

int main()
{
	int count, len;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (len=0; s[len]; len++);
		puts(check(0, len-1, 1) ? "YES" : "NO");
	}
	return 0;
}
