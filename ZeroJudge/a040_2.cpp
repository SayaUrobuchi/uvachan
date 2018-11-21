#include <stdio.h>
#include <math.h>

int tbl[1000005], t2[]={0, 10, 100, 1000, 10000, 100000, 1000000};

int recurs(int m, int o)
{
	int temp;
	if(o == 0)
	{
		return 1&&m;
	}
	if(o % 2)
	{
		return recurs(m, o-1) * m;
	}
	temp = recurs(m, o>>1);
	return temp*temp;
}

int is_arm(int n, int o)
{
	int res, m, temp;
	temp = n;
	res = 0;
	while(n > 0)
	{
		m = n % 10;
		res += recurs(m, o);
		n /= 10;
	}
	return res == temp;
}

int main()
{
	int i, j, n, m, f, p, q, c, pn;
	for(i=1, pn=0, j=1; i<=1000000; i++)
	{
		if(i == t2[j])
		{
			j++;
		}
		if(is_arm(i, j))
		{
			tbl[pn++] = i;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(p=0, q=pn-1; p<=q; )
		{
			c = ((p+q)>>1);
			if(tbl[c] >= n)
			{
				i = c;
				q = c-1;
			}
			else
			{
				p = c+1;
			}
		}
		for(f=0; i<pn&&tbl[i]<=m; i++)
		{
			if(tbl[i])
			{
				if(f)
				{
					printf(" ");
				}
				f = 1;
				printf("%d", tbl[i]);
			}
		}
		if(!f)
		{
			printf("none");
		}
		printf("\n");
	}
	return 0;
}
