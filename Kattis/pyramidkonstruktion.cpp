#include<iostream>
using namespace std;

int main()
{
	int n, m, a, b;
	while (scanf("%d%d%d", &n, &a, &b) == 3)
	{
		m = 1 + ((n*(n-1))<<1);
		//printf(".. %d\n", m);
		if ((m>>1) <= b)
		{
			m = 1;
		}
		else
		{
			m -= (b<<1);
		}
		//printf("?? %d\n", m);
		if (m <= a)
		{
			m = 0;
		}
		else
		{
			m -= a;
		}
		printf("%d %d\n", m&1, m>>1);
	}
	return 0;
}
