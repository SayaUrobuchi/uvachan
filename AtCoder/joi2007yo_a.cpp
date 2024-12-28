#include <iostream>
using namespace std;

int main()
{
	int i, j;
	int ans = 0;
	for (i=0; i<2; i++)
	{
		int sum = 0;
		for (j=0; j<4; j++)
		{
			int t;
			scanf("%d", &t);
			sum += t;
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
