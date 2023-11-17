#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int ary[N];

int main()
{
	int n, m, i;
	bool ok;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	for (i=0, ok=true; ok&&i<n; i++)
	{
		if (ary[i] <= i * m)
		{
			ok = false;
		}
	}
	puts(ok ? "YES" : "NO");
	return 0;
}