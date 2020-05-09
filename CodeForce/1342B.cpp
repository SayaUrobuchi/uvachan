#include <stdio.h>
#include <string.h>

char s[256], t[256];

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		n = strlen(s);
		if (n <= 2)
		{
			puts(s);
			continue;
		}
		for (i=0; i<n; i++)
		{
			if (s[i] != s[0])
			{
				break;
			}
		}
		if (i >= n)
		{
			puts(s);
			continue;
		}
		t[0] = s[0];
		for (i=1, j=1; i<n; i++)
		{
			if (s[i] == s[i-1])
			{
				t[j++] = (s[i] ^ 1);
			}
			t[j++] = s[i];
		}
		t[j] = 0;
		puts(t);
	}
	return 0;
}
