#include <iostream>
using namespace std;

int main()
{
	int n, i, sum;
	scanf("%d", &n);
	for (i=0, sum=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		sum += t;
	}
	printf("%d\n", sum/n);
	return 0;
}
