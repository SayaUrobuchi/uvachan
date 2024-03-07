#include <iostream>
using namespace std;

int rec(int n)
{
	if (n <= 0)
	{
		return 1;
	}
	int i, t;
	for (i=0, t=n; t; i++, t>>=1);
	//printf("%d %d\n", n, d);
	return rec(n - (1 << (i-1))) << 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", rec(n));
	return 0;
}