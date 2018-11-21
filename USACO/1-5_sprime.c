/*
	ID: sa072682
	LANG: C
	TASK: sprime
*/
#include <stdio.h>

int queue[100000];

char isprime(int now)
{
	int i;
	for(i=3; i*i<now; i+=2)
	{
		if(!(now % i))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, i, j;
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	queue[0] = 2;
	queue[1] = 3;
	queue[2] = 5;
	queue[3] = 7;
	for(i=0, j=4; i<j; i++)
	{
		n = queue[i] * 10;
		if(n > 100000000)
		{
			break;
		}
		if(isprime(n+1))
		{
			queue[j++] = n + 1;
		}
		if(isprime(n+3))
		{
			queue[j++] = n + 3;
		}
		if(isprime(n+7))
		{
			queue[j++] = n + 7;
		}
		if(isprime(n+9))
		{
			queue[j++] = n + 9;
		}
	}
	queue[j] = 1000000000;
	scanf("%d", &n);
	j = 1;
	while(n--)
	{
		i = j;
		j *= 10;
	}
	for(n=0; queue[n]<i; n++);
	for(; queue[n]<j; n++)
	{
		printf("%d\n", queue[n]);
	}
	return 0;
}
