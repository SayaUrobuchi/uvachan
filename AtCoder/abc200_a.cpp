#include <iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", (n-1)/100+1);
	}
	return 0;
}

