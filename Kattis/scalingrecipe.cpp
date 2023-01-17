#include <iostream>
using namespace std;

int main()
{
	int n, x, y, i, t;
	scanf("%d%d%d", &n, &x, &y);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		printf("%d\n", t*y/x);
	}
	return 0;
}
