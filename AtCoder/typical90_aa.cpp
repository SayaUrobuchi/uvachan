#include <iostream>
#include <unordered_set>
using namespace std;
using sss = unordered_set<string>;

char buf[32];

int main()
{
	int n, i;
	sss se;
	while (scanf("%d", &n) == 1)
	{
		se.clear();
		for (i=1; i<=n; i++)
		{
			scanf("%s", buf);
			if (!se.count(buf))
			{
				printf("%d\n", i);
				se.insert(buf);
			}
		}
	}
	return 0;
}
