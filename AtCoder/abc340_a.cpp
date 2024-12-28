#include <iostream>
using namespace std;

int main()
{
	int a, b, c, i;
	scanf("%d%d%d", &a, &b, &c);
	for (i=a; i<=b; i+=c)
	{
		printf("%d%c", i, " \n"[i==b]);
	}
	return 0;
}
