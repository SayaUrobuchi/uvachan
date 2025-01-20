#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = a % b;
		printf("%d\n", ans);
	}
	return 0;
}
