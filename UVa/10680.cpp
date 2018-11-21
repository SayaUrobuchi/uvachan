#include <stdio.h>

int mark[1000001], ans[1000001], two[1000001], ary[4] = {6, 2, 4, 8};
char tbl[1000001];

int calc(int times)
{
	if(!times)
	{
		return 1;
	}
	return ary[times%4];
}

int main()
{
	int n, i, j, k;
	for(i=2; i<1000001; i*=2)
	{
		mark[i] = 2;
	}
	for(i=3; i<1000; i+=2)
	{
		if(!tbl[i])
		{
			for(j=i*i, k=i+i; j<1000001; j+=k)
			{
				tbl[j] = 1;
			}
			for(j=i; j<1000001; j*=i)
			{
				mark[j] = i;
			}
		}
	}
	for(; i<1000001; i+=2)
	{
		if(!tbl[i])
		{
			mark[i] = i;
		}
	}
	ans[1] = 1;
	two[1] = 0;
	for(i=2; i<1000001; i++)
	{
		ans[i] = ans[i-1];
		two[i] = two[i-1];
		if(mark[i])
		{
			if(mark[i] == 2)
			{
				two[i]++;
			}
			else if(mark[i] == 5)
			{
				two[i]--;
			}
			else
			{
				ans[i] *= mark[i];
				ans[i] %= 10;
			}
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("%d\n", (ans[n]*calc(two[n]))%10);
	}
	return 0;
}
