#include <iostream>
using namespace std;

char s[128];
const char *tbl[128];

int main()
{
	int n;
	tbl['o'] = "Yes";
	tbl['x'] = "No";
	while (scanf("%d%s", &n, s) == 2)
	{
		printf("%s\n", tbl[s[n-1]]);
	}
	return 0;
}

