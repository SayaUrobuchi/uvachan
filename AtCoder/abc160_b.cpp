#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int a = n / 500;
	int b = (n % 500) / 5;
	int ans = a * 1000 + b * 5;
	printf("%d\n", ans);
	return 0;
}
