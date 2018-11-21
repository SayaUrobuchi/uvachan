#include <stdio.h>

int ary[670000], m;
char tbl[5000001];

int bisearch(int now)
{
	int left, right, center;
	left = 0;
	right = m - 1;
	for(;;)
	{
		center = left + right;
		center /= 2;
		if(ary[center] == now)
		{
			return center;
		}
		else if(ary[center] > now)
		{
			right = center - 1;
			if(left > right)
			{
				return center - 1;
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				return center;
			}
		}
	}
}

int main()
{
	int n, i, j, k;
	ary[1] = 2;
	for(i=3, m=2; i<4000; i+=2)
	{
		if(!tbl[i/2])
		{
			for(j=i*i, k=i+i; j<10000001; j+=k)
			{
				tbl[j/2] = 1;
			}
			ary[m++] = i;
		}
	}
	for(; i<10000001; i+=2)
	{
		if(!tbl[i/2])
		{
			ary[m++] = i;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &j);
			printf("%d\n", bisearch(j));
		}
	}
	return 0;
}
