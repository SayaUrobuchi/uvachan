#include <iostream>
using namespace std;

int main()
{
	int n, i, lvl;
	scanf("%d%d", &n, &lvl);
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (lvl >= a && lvl <= b)
		{
			++lvl;
		}
	}
	printf("%d\n", lvl);
	return 0;
}