#include <stdio.h>

int main()
{
	int ans;
	long long n, i, j;
	long long ii, jj, temp;
	while(scanf("%lld", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, j=2, ii=i*i*i, jj=j*j*j, ans=0; ; )
		{
			temp = jj - ii;
			if(temp == n)
			{
				ans = 1;
				break;
			}
			else if(temp > n)
			{
				if(j == i+1)
				{
					break;
				}
				i++;
				ii = i * i * i;
			}
			else
			{
				j++;
				jj = j * j * j;
			}
		}
		if(ans)
		{
			printf("%lld %lld\n", j, i);
		}
		else
		{
			printf("No solution\n");
		}
	}
	return 0;
}
