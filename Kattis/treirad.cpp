#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i*(i+1)*(i+2)<n; i++);
	printf("%d\n", i-1);
	return 0;
}
