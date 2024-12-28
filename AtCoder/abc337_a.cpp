#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int asum = 0;
	int bsum = 0;
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		asum += a;
		bsum += b;
	}
	if (asum > bsum)
	{
		puts("Takahashi");
	}
	else if (asum == bsum)
	{
		puts("Draw");
	}
	else
	{
		puts("Aoki");
	}
	return 0;
}
