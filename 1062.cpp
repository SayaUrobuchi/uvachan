#include <stdio.h>
#include <stdlib.h>

char s[1024];
int idx[1024], stk[26];

int comp(const void *p, const void *q)
{
	if (s[*(int*)p] != s[*(int*)q])
	{
		return s[*(int*)p]>s[*(int*)q] ? 1 : -1;
	}
	return *(int*)q > *(int*)p ? 1 : -1;
}

int main()
{
	int cas, n, i, j, sn;
	cas = 0;
	while (gets(s))
	{
		if (*s == 'e')
		{
			break;
		}
		for (i=0; s[i]; i++)
		{
			idx[i] = i;
		}
		n = i;
		qsort(idx, n, sizeof(int), comp);
		for (i=0, sn=0; i<n; i++)
		{
			for (j=0; j<sn; j++)
			{
				if (idx[i] < stk[j])
				{
					stk[j] = idx[i];
					break;
				}
			}
			if (j >= sn)
			{
				stk[sn++] = idx[i];
			}
		}
		printf("Case %d: %d\n", ++cas, sn);
	}
	return 0;
}
