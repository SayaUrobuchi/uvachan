#include <stdio.h>
#include <string.h>

const int N = 16384;

int ary[N], bry[N];

int main()
{
	int n, m, i, p, q, r, a, b, c;
	while (scanf("%d%d", &m, &n) == 2)
	{
		memset(ary, 0, sizeof(ary));
		memset(bry, 0, sizeof(bry));
		for (i=0, c=0; i<m; i++)
		{
			scanf("%d%d%d", &r, &p, &q);
			ary[r] += p;
			bry[r] += q;
			c += p+q;
		}
		for (i=1, a=0, b=0; i<=n; i++)
		{
			if (ary[i] > bry[i])
			{
				p = ary[i] - ((ary[i]+bry[i])/2 + 1);
				q = bry[i];
			}
			else
			{
				p = ary[i];
				q = bry[i] - ((ary[i]+bry[i])/2 + 1);
			}
			a += p;
			b += q;
			printf("%c %d %d\n", ary[i]>bry[i]?'A':'B', p, q);
		}
		printf("%.10lf\n", (a>b?a-b:b-a)*1./c);
	}
	return 0;
}