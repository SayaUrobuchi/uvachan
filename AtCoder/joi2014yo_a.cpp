#include <iostream>
using namespace std;

int main()
{
	int i;
	int sum = 0;
	for (i=0; i<5; i++)
	{
		int t;
		scanf("%d", &t);
		sum += max(40, t);
	}
	int ans = sum / 5;
	printf("%d\n", ans);
	return 0;
}
