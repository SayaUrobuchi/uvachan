#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	int sum = 0;
	for (i=0; sum<n; sum+=++i);
	printf("%d\n", i);
	return 0;
}
