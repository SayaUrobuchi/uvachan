#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; n>1; i<<=1, n>>=1);
	printf("%d\n", i);
	return 0;
}