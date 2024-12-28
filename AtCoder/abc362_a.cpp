#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	char col;
	scanf("%d%d%d %c", &a, &b, &c, &col);
	if (col == 'R')
	{
		a = 100000;
	}
	else if (col == 'G')
	{
		b = 100000;
	}
	else
	{
		c = 100000;
	}
	int ans = min(a, min(b, c));
	printf("%d\n", ans);
	return 0;
}
