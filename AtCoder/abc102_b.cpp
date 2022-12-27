#include <iostream>
using namespace std;

int main()
{
	int n, i, t, big, small;
	scanf("%d", &n);
	for (i=0, big=0, small=2e9; i<n; i++)
	{
		scanf("%d", &t);
		big = max(big, t);
		small = min(small, t);
	}
	printf("%d\n", big-small);
	return 0;
}