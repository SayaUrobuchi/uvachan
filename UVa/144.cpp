#include <stdio.h>
#include <string.h>

int ary[30], next[30];

int main()
{
	int n, m, i, j, k, c, rem;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			next[i] = i+1;
		}
		next[i] = 0;
		memset(ary, 0, sizeof(ary));
		for(i=1, j=0, rem=0, c=n; c; i++)
		{
			rem += i;
			if(i == m)
			{
				i = 0;
			}
			for(; rem&&c; )
			{
				k = next[j];
				if(!k)
				{
					j = 0;
					k = next[j];
				}
				if(ary[k] + rem < 40)
				{
					ary[k] += rem;
					rem = 0;
					j=k;
				}
				else
				{
					rem -= 40 - ary[k];
					printf("%3d", k);
					next[j] = next[k];
					c--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
