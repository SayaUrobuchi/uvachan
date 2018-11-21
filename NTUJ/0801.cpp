#include <stdio.h>

int ary[1005];

int main()
{
	int count, n, m, f, i, c, temp, sum, cc;
	unsigned int p, q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &f, &m);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			ary[i] = (q ? f+f-p : p);
		}
		for(p=0, q=2147483647, cc=0; p<=q; )
		{
			cc++;
			if(cc > 40)
			{
				cc = 0;
				p /= cc;
			}
			c = ((p+q)>>1);
			for(i=0, sum=0; i<n; i++)
			{
				sum += (c>=ary[i]+f?(c-ary[i]-f) / (f+f) + 1:0);
				if(sum >= m)
				{
					break;
				}
			}
			if(sum >= m)
			{
				q = c-1;
				temp = c;
			}
			else
			{
				p = c+1;
			}
		}
		printf("%d\n", temp);
	}
	return 0;
}
