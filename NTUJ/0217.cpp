#include <stdio.h>

int cused[75][9], cd[75][9], rused[75][9][3], rd[75][9][3];

long long calc(int n, int c)
{
	int i, j;
	if(cused[n][c])
	{
		return cd[n][c];
	}
	cused[n][c] = 1;
	if(c == 0)
	{
		return cd[n][c]=1;
	}
	if(n < c*2-1)
	{
		return cd[n][c]=0;
	}
	cd[n][c] = 0;
	for(i=n-2, j=(c-1)*2-1; i>=0&&i>=j; i--)
	{
		cd[n][c] += calc(i, c-1);
	}
	return cd[n][c]+=calc(0, c-1);
}

long long recur(int n, int c, int t)
{
	int i;
	if(rused[n][c][t])
	{
		return rd[n][c][t];
	}
	rused[n][c][t] = 1;
	if(c == 0)
	{
		return rd[n][c][t]=1;
	}
	if(n < c)
	{
		return rd[n][c][t]=0;
	}
	rd[n][c][t] = 0;
	if(t == 0)
	{
		for(i=n-2; i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 0);
			if(n == 2 && c == 2)
			{
				printf("123ABC %I64d\n", recur(i, c-1, 0));
			}
		}
		for(i=n-1; i>0&&i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 1);
			if(n == 2 && c == 2)
			{
				printf("123ABCccccccccccc %I64d\n", recur(i, c-1, 1));
			}
		}
	}
	else if(t == 1)
	{
		for(i=n-1; i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 0);
			if(n == 2 && c == 2)
			{
				printf("123ABCaaaaaaaaaa %I64d\n", recur(i, c-1, 0));
			}
		}
		for(i=n-2; i>0&&i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 1);
			if(n == 2 && c == 2)
			{
				printf("123ABCcccccccccccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa %I64d\n", recur(i, c-1, 1));
			}
		}
	}
	else if(t == 2)
	{
		for(i=n-2; i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 2);
		}
		for(i=n-1; i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 3);
		}
	}
	else
	{
		for(i=n-1; i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 2);
		}
		for(i=n-2; i>=c-1; i--)
		{
			rd[n][c][t] += recur(i, c-1, 3);
		}
	}
	return rd[n][c][t];
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		if(n % 2)
		{
			printf("%I64d\n", (calc(n-3, 7)+calc(n-1, 8)) * 8 * 7 * 6 * 5 * 4 * 3 * 2);
		}
		else
		{
			printf("%I64d %I64d %I64d\n", recur((n-2)/2, 7, 0)*2, recur((n-2)/2-1, 7, 2), recur((n-2)/2, 8, 2));
			printf("%I64d\n", recur((n-2)/2, 7, 0)*2+recur((n-2)/2-1, 7, 2)+recur((n-2)/2, 8, 2));
		}
	}
	return 0;
}
