#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, m, i, t, a, b, cmd;
	while (scanf("%d%d", &n, &m) == 2)
	{
		set<int> se;
		se.insert(0);
		se.insert(n);
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &cmd, &t);
			if (cmd == 1)
			{
				se.insert(t);
			}
			else
			{
				auto it = se.upper_bound(t);
				b = *it;
				a = *(--it);
				printf("%d\n", b-a);
			}
		}
	}
	return 0;
}

