#include <iostream>
using namespace std;

char tbl[128];

int main()
{
	int n, x, i;
	tbl['x'] = -1;
	tbl['o'] = 1;
	scanf("%d%d", &n, &x);
	for (i=0; i<n; i++)
	{
		char c;
		scanf(" %c", &c);
		x = max(0, x+tbl[c]);
	}
	printf("%d\n", x);
	return 0;
}
