#include <iostream>
using namespace std;

const int N = 128;

int ary[8], tbl[128];
char s[N];

int main()
{
	int n, i;
	tbl['L'] = -1;
	tbl['R'] = 1;
	scanf("%d%s", &n, s);
	int pos = 0;
	++ary[pos];
	for (i=0; i<n; i++)
	{
		pos = max(0, min(2, pos + tbl[s[i]]));
		++ary[pos];
	}
	printf("%d\n", ary[2]);
	return 0;
}
