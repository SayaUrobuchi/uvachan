#include <iostream>
using namespace std;

int main()
{
	int n;
	char t;
	scanf("%d.%c", &n, &t);
	if (t >= '5')
	{
		++n;
	}
	printf("%d\n", n);
	return 0;
}
