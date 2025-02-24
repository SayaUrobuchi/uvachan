#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int sum = 0;
	for (i=n; i; i/=10)
	{
		sum += i % 10;
	}
	puts(n % sum ? "No" : "Yes");
	return 0;
}
