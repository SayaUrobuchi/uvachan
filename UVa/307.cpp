#include <stdio.h>
#include <string.h>

int ary[51], max;

char dfs(int last, int num, int now, int goal)
{
	int i, j, tmp;
	if(now == goal)
	{
		if(num)
		{
			for(i=max; i>0; i--)
			{
				if(ary[i])
				{
					break;
				}
			}
			ary[i]--;
			if(dfs(i, num-1, i, goal))
			{
				return 1;
			}
			ary[i]++;
		}
		else
		{
			return 1;
		}
		return 0;
	}
	for(i=last; i>0; i--)
	{
		if(ary[i])
		{
			if(now+i <= goal)
			{
				ary[i]--;
				if(dfs(i, num, now+i, goal))
				{
					return 1;
				}
				ary[i]++;
				if(now+i == goal) return 0;
			}
		}
	}
	return 0;
}

int main()
{
	int n, i, in, sum, num, odd, tmp, ans;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		memset(ary, 0, sizeof(ary));
		sum = 0;
		max = 0;
		num = 0;
		while(n--)
		{
			scanf("%d", &in);
			ary[in]++;
			sum += in;
			if(in > max)
			{
				max = in;
			}
		}
		ary[max]--;
		odd = 1 + sum % 2;
		tmp = sum / (odd + 1);
		ans = 0;
		for(i=max+odd-1; i<tmp; i+=odd)
		{
			if(!(sum % i))
			{
				if(dfs(max, sum/i-2, max, i))
				{
					ans = 1;
					break;
				}
			}
		}
		if(!ans)
		{
			if(!(sum % tmp))
			{
				if(dfs(max, sum/(tmp)-2, max, tmp))
				{
					i = tmp;
					ans = 1;
				}
			}
		}
		if(!ans)
		{
			i = sum;
		}
		printf("%d\n", i);
	}
	return 0;
}