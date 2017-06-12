#include <stdio.h>

int m, x;

char chk(long long now)
{
	if(now - now * x / 100.0 < m - 1)
	{
		return 0;
	}
	return 1;
}

long long bisearch(long long left, long long right)
{
	long long center, temp, temp2;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	temp = chk(center);
	temp2 = chk(center+1);
	if(temp != temp2)
	{
		return center;
	}
	else if(temp)
	{
		return bisearch(left, center-1);
	}
	return bisearch(center+1, right);
}

int main()
{
	long long ans, temp;
	while(scanf("%d%d", &m, &x) == 2)
	{
		if(!m && !x)
		{
			break;
		}
		if(!x || x == 100)
		{
			printf("Not found\n");
			continue;
		}
		temp = (long long)m * x / 100.0;
		temp /= (100.0-x) / 100.0;
		ans = bisearch(m, (long long)(m+temp+2));
		if(ans == -1)
		{
			printf("Not found\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}
