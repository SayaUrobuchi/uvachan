#include <stdio.h>
#include <string.h>

int jmp[1048576];
char s[1048576];

int main()
{
	int n, i, j, ans;
	while (fgets(s, sizeof(s), stdin))
	{
		if (!strtok(s, "\r\n"))
		{
			*s = 0;
		}
		if (strcmp(s, ".") == 0)
		{
			break;
		}
		if (*s == 0)
		{
			puts("0");
			continue;
		}
		jmp[0] = -1;
		for (i=1, j=0; s[i]; i++, j++)
		{
			jmp[i] = j;
			while (j >= 0 && s[i] != s[j])
			{
				j = jmp[j];
			}
		}
		n = i;
		jmp[n] = j;
		ans = -1;
		while (i > ans)
		{
			if (ans != i-jmp[i])
			{
				ans = i - jmp[i];
			}
			i = jmp[i];
		}
		printf("%d\n", n/ans);
	}
	return 0;
}
