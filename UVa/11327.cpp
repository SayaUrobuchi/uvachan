#include <stdio.h>

int min, tbl[200001];
long long count[200001];

void bisearch(long long now, int left, int right)
{
	int center;
	if(left > right)
	{
		return;
	}
	center = left + right;
	center /= 2;
	if(count[center] >= now)
	{
		min = center;
		bisearch(now, left, center-1);
	}
	else
	{
		bisearch(now, center+1, right);
	}
}

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int main()
{
	int i, j, c, need;
	long long n;
	for(i=0, j=0; i<200001; j++)
	{
		tbl[i++] = j;
		tbl[i] = i;
		i++;
	}
	for(i=3; i<100001; i+=2)
	{
		if(tbl[i] == i)
		{
			tbl[i]--;
			for(j=i+i; j<200001; j+=i)
			{
				tbl[j] /= i;
				tbl[j] *= i-1;
			}
		}
	}
	for(; i<200001; i+=2)
	{
		if(tbl[i] == i)
		{
			tbl[i]--;
		}
	}
	count[0] = 1;
	for(i=1; i<200001; i++)
	{
		count[i] = tbl[i] + count[i-1];
	}
	while(scanf("%lld", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(n == 1)
		{
			printf("0/1\n");
		}
		else
		{
			min = 200000;
			bisearch(n, 0, 200000);
			need = n - count[min-1];
			/*printf("%d %d\n", need, min);*/
			for(i=1, c=0; ; i++)
			{
				if(gcd(i, min) == 1)
				{
					c++;
				}
				if(c == need)
				{
					break;
				}
			}
			printf("%d/%d\n", i, min);
		}
	}
	return 0;
}
