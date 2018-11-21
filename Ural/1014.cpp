#include <stdio.h>
#include <stdlib.h>

char s[101];

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

int main()
{
	int n, i, len;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			printf("10\n");
			continue;
		}
		else if(n == 1)
		{
			printf("%d\n", n);
			continue;
		}
		for(i=9, len=0; i>1&&n>1; i--)
		{
			while(n%i == 0)
			{
				n /= i;
				s[len++] = i + 48;
			}
		}
		if(n > 1)
		{
			printf("-1\n");
		}
		else
		{
			qsort(s, len, sizeof(char), comp);
			s[len] = 0;
			printf("%s\n", s);
		}
	}
	return 0;
}
