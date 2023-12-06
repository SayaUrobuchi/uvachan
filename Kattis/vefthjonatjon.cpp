#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	int tbl[4] = {};
	char s[8];
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf("%s", s);
			tbl[j] += (*s == 'J');
		}
	}
	printf("%d\n", min(tbl[0], min(tbl[1], tbl[2])));
	return 0;
}
