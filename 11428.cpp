#include <stdio.h>

int main()
{
	int n, i, j, ans;
	long long ii, temp;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, ans=0; ; i++)
		{
			ii = (long long)i * i * i;
			for(j=i+1; ; j++)
			{
				temp = (long long)j * j * j - ii;
				if(temp == n)
				{
					ans = 1;
					break;
				}
				else if(temp > n)
				{
					break;
				}
			}
			if(ans)
			{
				break;
			}
			if(j == i+1)
			{
				break;
			}
		}
		if(ans)
		{
			printf("%d %d\n", j, i);
		}
		else
		{
			printf("No solution\n");
		}
	}
	return 0;
}
