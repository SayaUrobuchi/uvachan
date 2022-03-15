#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	int n, i;
	bool gg;
	char buf[128], buf0[128], buf1[128];
	while (scanf("%d", &n) == 1)
	{
		unordered_set<string> se;
		for (i=0, gg=false; i<n; i++)
		{
			scanf("%s%s", buf0, buf1);
			sprintf(buf, "%s_%s", buf0, buf1);
			if (se.count(buf))
			{
				gg = true;
			}
			else
			{
				se.insert(buf);
			}
		}
		puts(gg?"Yes":"No");
	}
	return 0;
}
