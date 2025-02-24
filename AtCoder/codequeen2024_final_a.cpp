#include <iostream>
using namespace std;

const int LIS[] = {10, 15, 17};
const int N = sizeof(LIS) / sizeof(LIS[0]);

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<N&&n>LIS[i]; i++);
	printf("%d\n", LIS[i]);
	return 0;
}