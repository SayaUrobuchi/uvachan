#include <stdio.h>
#include <string.h>

int w[2005], ltbl[2005], rtbl[2005];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int count, n, i, j, ans, lm, rm, t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		lm = 1;
		rm = 1;
		ltbl[0] = 2147483647;
		rtbl[0] = -1;
		for(i=0; i<n; i++)
		{
			scanf("%d", &w[i]);
		}
		for(i=n-1, ans=0; i>=0; i--)
		{
			for(j=0; j<lm; j++)
			{
				if(w[i] > ltbl[j])
				{
					break;
				}
			}
			ltbl[j] = w[i];
			if(j == lm)
			{
				lm++;
			}
			t = j;
			for(j=0; j<rm; j++)
			{
				if(w[i] < rtbl[j])
				{
					break;
				}
			}
			rtbl[j] = w[i];
			if(j == rm)
			{
				rm++;
			}
			if(t+j-1 > ans)
			{
				ans = t+j-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
