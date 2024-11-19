#include <iostream>
using namespace std;

const int N = 100005;

int tbl[128];
char s[N];

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; i++)
	{
		++tbl[s[i]];
	}
	int high = max(tbl['a'], max(tbl['b'], tbl['c']));
	int low = min(tbl['a'], min(tbl['b'], tbl['c']));
	puts(high-low<=1 ? "YES" : "NO");
	return 0;
}
