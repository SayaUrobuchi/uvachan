#include <iostream>
using namespace std;

const char *res[] = {"No", "Yes"};
const int N = 1005;

int ary[N];
bool used[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		used[i] = false;
	}
	bool ok = true;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		bool can_find = false;
		for (j=0; j<n; j++)
		{
			if (ary[j] == t && !used[j])
			{
				used[j] = true;
				can_find = true;
				break;
			}
		}
		if (!can_find)
		{
			ok = false;
		}
	}
	puts(res[ok]);
	return 0;
}