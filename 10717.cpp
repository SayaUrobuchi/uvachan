#include <stdio.h>

int ary[55], lis[5600000];

long long int getgcd(long long int p, long long int q)
{
	while((p%=q)&&(q%=p));
	return p+q;
}

int main()
{
	int n, m, i, j, k, l, p, q, r, t, c;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0, c=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			for(j=0; j<i; j++)
			{
				p = ary[i]/getgcd(ary[i], ary[j])*ary[j];
				for(k=0; k<j; k++)
				{
					q = p/getgcd(p, ary[k])*ary[k];
					for(l=0; l<k; l++)
					{
                        r = q/getgcd(q, ary[l])*ary[l];
                        lis[c++] = r;
					}
				}
			}
		}
		for(i=0; i<m; i++)
		{
			scanf("%d", &t);
			for(j=0, p=0, q=2147483647; j<c; j++)
			{
				k = (t/lis[j])*lis[j];
				l = k;
				if(l < t)
				{
					l += lis[j];
				}
				if(k > p)
				{
					p = k;
				}
				if(q > l)
				{
					q = l;
				}
			}
			printf("%d %d\n", p, q);
		}
	}
	return 0;
}
