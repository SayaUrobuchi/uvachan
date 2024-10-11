#include <iostream>
using namespace std;

const int N = 10000005;
const int M = 1000000009;

char buf[N];

int main()
{
	int i, j;
	scanf("%s", buf);
	for (i=0; buf[i]; i++);
	long long ans = 1;
	long long t = 2;
	for (--i; i>=0; i--)
	{
		long long u = 1;
		for (j='1'; j<=buf[i]; j++)
		{
			u = (u * t) % M;
		}
		ans = (ans * u) % M;
		for (; j<='9'+1; j++)
		{
			u = (u * t) % M;
		}
		t = u;
	}
	printf("%lld\n", ans);
	return 0;
}
