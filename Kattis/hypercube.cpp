#include <iostream>
using namespace std;

char buf[2][128];

long long recurs(long long t, int dir, char *s)
{
	if (!t)
	{
		return 0;
	}
	return ((*s-'0')^dir)*t + recurs(t>>1, dir^(*s&1), s+1);
}

int main()
{
	int n;
	long long a, b;
	while (scanf("%d%s%s", &n, buf[0], buf[1]) == 3)
	{
		a = recurs(1LL<<(n-1), 0, buf[0]);
		b = recurs(1LL<<(n-1), 0, buf[1]);
		//printf("%lld %lld\n", a, b);
		printf("%lld\n", b-a-1);
	}
	return 0;
}
