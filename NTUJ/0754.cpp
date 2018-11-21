#include <stdio.h>

int tbl[1000005];

int main()
{
	int i, j, k, n, p, q, c, temp;
	tbl[1] = 1;
	for(i=2, j=2, k=2; ; i++)
	{
		tbl[i] = tbl[i-1] + j;
		if(tbl[i] >= 2000000000)
		{
			break;
		}
		if(i >= tbl[k])
		{
			j++;
			k++;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(p=1, q=i; p<=q; )
		{
			c = ((p+q)>>1);
			if(n <= tbl[c])
			{
				temp = c;
				q = c-1;
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
