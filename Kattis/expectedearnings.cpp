#include <iostream>
using namespace std;

int main()
{
	int n, k;
	double p, expected;
	scanf("%d%d%lf", &n, &k, &p);
	expected = p * n;
	if (expected < k)
	{
		puts("spela");
	}
	else
	{
		puts("spela inte!");
	}
	return 0;
}
