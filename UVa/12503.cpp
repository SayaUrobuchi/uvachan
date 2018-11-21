#include <stdio.h>

int ary[1048576];
char s[1048576];

int main()
{
	int count, i, j, n, res;
	gets(s);
	sscanf(s, "%d", &count);
	while (count--)
	{
		gets(s);
		sscanf(s, "%d", &n);
		res = 0;
		for (i=0; i<n; i++)
		{
			gets(s);
			if (*s == 'L')
			{
				ary[i] = -1;
			}
			else if (*s == 'R')
			{
				ary[i] = 1;
			}
			else
			{
				sscanf(s+7, "%d", &j);
				ary[i] = ary[j-1];
			}
			res += ary[i];
		}
		printf("%d\n", res);
	}
	return 0;
}
