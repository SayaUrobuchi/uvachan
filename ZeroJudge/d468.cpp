#include <stdio.h>
#include <string.h>

char s[10000005];

long long recurs(long long p, unsigned long long q)
{
	long long temp;
	if(q == 0)
	{
		return 1&&p;
	}
	if(q & 1)
	{
		return recurs(p, q-1)*p;
	}
	temp = recurs(p, q>>1);
	return temp*temp;
}

int main()
{
	long long n;
	unsigned long long m;
	while(scanf("%lld%s", &n, s) == 2)
	{
		if(n == 0 && strcmp(s, "0") == 0)
		{
			printf("All Over.\n");
			break;
		}
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		if(n == -1)
		{
			printf("%d\n", (s[strlen(s)-1]&1)?-1:1);
			continue;
		}
		sscanf(s, "%llu", &m);
		printf("%lld\n", recurs(n, m));
	}
	return 0;
}
