#include <stdio.h>

int main()
{
	int n, i, loc1, loc2, step1, step2, tmp1, tmp2, l, r;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0, loc1=1, loc2=1, step1=0, step2=0; i<n; i++)
		{
			scanf("%d%d", &l, &r);
			if(loc1 < l)
			{
				tmp2 = step1 + r - loc1;
			}
			else if(loc1 > r)
			{
				tmp2 = step1 + loc1 - l + r - l;
			}
			else
			{
				tmp2 = step1 + loc1 + r - l - l;
			}
			if(loc1 > r)
			{
				tmp1 = step1 + loc1 - l;
			}
			else if(loc1 < l)
			{
				tmp1 = step1 + r - loc1 + r - l;
			}
			else
			{
				tmp1 = step1 + r + r - loc1 - l;
			}
			if(loc2 < l)
			{
				if(step2 + r - loc2 < tmp2)
				{
					tmp2 = step2 + r - loc2;
				}
			}
			else if(loc2 > r)
			{
				if(step2 + loc2 - l + r - l < tmp2)
				{
					tmp2 = step2 + loc2 - l + r - l;
				}
			}
			else
			{
				if(step2 + loc2 + r - l - l < tmp2)
				{
					tmp2 = step2 + loc2 + r - l - l;
				}
			}
			if(loc2 > r)
			{
				if(step2 + loc2 - l < tmp1)
				{
					tmp1 = step2 + loc2 - l;
				}
			}
			else if(loc2 < l)
			{
				if(step2 + r - loc2 + r - l < tmp1)
				{
					tmp1 = step2 + r - loc2 + r - l;
				}
			}
			else
			{
				if(step2 + r + r - loc2 - l < tmp1)
				{
					tmp1 = step2 + r + r - loc2 - l;
				}
			}
			loc1 = l;
			loc2 = r;
			step1 = tmp1;
			step2 = tmp2;
		}
		step1 += n - loc1 + n - 1;
		step2 += n - loc2 + n - 1;
		if(step1 < step2)
		{
			printf("%d\n", step1);
		}
		else
		{
			printf("%d\n", step2);
		}
	}
	return 0;
}
