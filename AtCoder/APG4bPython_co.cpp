#include <iostream>
using namespace std;

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}
