#include <stdio.h>

int ary[2][10005];
char s[1005];

int main()
{
	int count, n, m, i, j, k, ans, sum, a, t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		m *= 100;
		*ary[0] = 1;
		*ary[1] = 1;
		for(i=0; i<n; i++)
		{
			scanf("%d%s", &a, s);
			if(*s == 'l')
			{
				ary[0][(*ary[0])++] = a;
			}
			else
			{
				ary[1][(*ary[1])++] = a;
			}
		}
		for(i=1, j=1, k=0, ans=0; i<*ary[k]||j<*ary[1-k]; ans++)
		{
			for(sum=0; i<*ary[k]; i++)
			{
				sum += ary[k][i];
				if(sum > m)
				{
					break;
				}
			}
			t = i;
			i = j;
			j = t;
			k = 1-k;
		}
		printf("%d\n", ans);
	}
	return 0;
}
