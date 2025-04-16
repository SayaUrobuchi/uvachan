#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = 0;
	int sum = 0;
	for (i=0; i<n; i++)
	{
		ans += ary[i] * sum;
		sum += ary[i];
	}
	printf("%d\n", ans);
	return 0;
}
