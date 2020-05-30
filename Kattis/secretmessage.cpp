#include <stdio.h>

char s[1048576];

int main()
{
	int count, n, m, i, j, x, y, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (n=0; s[n]; n++);
		for (m=1; m*m<n; m++);
		for (i=0; i<m; i++)
		{
			for (j=0; j<m; j++)
			{
				x = m-j-1;
				y = i;
				t = x*m+y;
				if (t < n)
				{
					putchar(s[t]);
				}
			}
		}
		puts("");
	}
	return 0;
}
