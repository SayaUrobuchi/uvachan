#include <stdio.h>
#include <math.h>

int tbl[1000005];

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

int is_arm(int n)
{
	int res, m, temp, o;
	o = (int)(log10(n)+1e-10)+1;
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
	int i, n, m, f;
	for(i=1; i<=1000000; i++)
	{
		tbl[i] = is_arm(i);
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=n, f=0; i<=m; i++)
		{
			if(tbl[i])
			{
				if(f)
				{
					printf(" ");
				}
				f = 1;
				printf("%d", i);
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
