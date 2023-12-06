#include <iostream>
using namespace std;

int main()
{
	int a, b, i, sum;
	for (i=0, sum=0; i<5; i++)
	{
		scanf("%d%d", &a, &b);
		sum += a * b;
	}
	scanf("%d%d", &a, &b);
	printf("%d\n", a*(sum/5)/b);
	return 0;
}
