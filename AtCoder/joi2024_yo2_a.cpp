#include <iostream>
using namespace std;

const int N = 200005;

int ary[N];
bool tbl[N+10];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		tbl[ary[i]] = true;
	}
	bool found = false;
	for (i=0; i<n&&!found; i++)
	{
		if (tbl[ary[i]] && tbl[ary[i]+3] && tbl[ary[i]+6])
		{
			found = true;
		}
	}
	puts(found ? "Yes" : "No");
	return 0;
}