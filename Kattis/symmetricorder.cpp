#include <stdio.h>

int n;
char s[32][64];

void recurs(int cur)
{
	if (cur >= n)
	{
		return;
	}
	puts(s[cur]);
	recurs(cur+2);
	if (cur+1 < n)
	{
		puts(s[cur+1]);
	}
}

int main()
{
	int i, cas;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", s[i]);
		}
		printf("SET %d\n", ++cas);
		recurs(0);
	}
	return 0;
}
