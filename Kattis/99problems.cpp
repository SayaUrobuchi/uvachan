#include <iostream>
using namespace std;

int main()
{
	int n, t;
	scanf("%d", &n);
	t = n % 100;
	if (t >= 49 || n < 100)
	{
		n += 99 - t;
	}
	else
	{
		n -= t + 1;
	}
	printf("%d\n", n);
	return 0;
}
