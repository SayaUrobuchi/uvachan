#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int sum = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		sum += t;
	}
	printf("%d\n", sum);
	return 0;
}
