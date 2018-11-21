#include <stdio.h>
#include <string.h>
#include <math.h>

int tbl[1000005], t2[]={0, 10, 100, 1000, 10000, 100000, 1000000};
char ss[10000000], *pp, *str[1000005];

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
	int res, temp;
	temp = n;
	res = 0;
	while(n > 0)
	{
		res += recurs(n%10, o);
		n /= 10;
	}
	return res == temp;
}

int main()
{
	int i, j, n, m, f, p, q, c, pn;
	*ss = ' ';
	for(i=1, pn=0, j=1, pp=ss+1, f=0; i<=1000000; i++)
	{
		if(i == t2[j])
		{
			j++;
		}
		if(is_arm(i, j))
		{
			tbl[pn] = i;
			if(f)
			{
				*pp++ = ' ';
			}
			f = 1;
			str[pn] = pp;
			pp += j;
			p = i;
			while(p > 0)
			{
				*--pp = p%10 + '0';
				p /= 10;
			}
			pp += j;
			pn++;
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
		if(tbl[i] > m)
		{
			printf("none\n");
			continue;
		}
		for(p=0, q=pn-1; p<=q; )
		{
			c = ((p+q)>>1);
			if(tbl[c] > m)
			{
				j = c;
				q = c-1;
			}
			else
			{
				p = c+1;
			}
		}
		printf("%.*s\n", str[j]-str[i]-1, str[i]);
	}
	return 0;
}
