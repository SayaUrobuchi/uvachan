#include <stdio.h>
#include <stdlib.h>

int ary[100][2];

int main()
{
	int cas, count, n, m, i, j, k, l, p, q, num, chk, temp, ans;
	double x, y;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &m);
		n = 0;
		while(m--)
		{
			scanf("%lf%lf", &x, &y);
			j = (int)x * 100;
			k = (int)y * 100;
			for(i=0; i<n; i++)
			{
				if(ary[i][0] == j && ary[i][1] == k)
				{
					break;
				}
			}
			if(i == n)
			{
				ary[n][0] = j;
				ary[n++][1] = k;
			}
		}
		if(n == 1)
		{
			printf("Data set #%d contains a single gnu.\n", ++cas);
		}
		else
		{
			num = 30;
			chk = 65536 / n;
			for(i=1, l=0, ans=0; i<n; i++)
			{
				for(j=0; j<i; j++)
				{
					if(l++ < num || rand() < chk)
					{
						p = ary[i][1] - ary[j][1];
						q = ary[i][0] - ary[j][0];
						for(k=0, temp=0; k<n; k++)
						{
							if((ary[i][1] - ary[k][1]) * q == (ary[i][0] - ary[k][0]) * p)
							{
								temp++;
							}
						}
						if(temp > ans)
						{
							ans = temp;
						}
					}
				}
			}
			printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", ++cas, n, ans);
		}
	}
	return 0;
}
