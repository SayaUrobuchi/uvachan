#include <iostream>
using namespace std;

int main()
{
	int sum, i;
	scanf("%d", &sum);
	for (i=0; i<9; i++)
	{
		int t;
		scanf("%d", &t);
		sum -= t;
	}
	printf("%d\n", sum);
	return 0;
}
