#include <iostream>
#include <algorithm>
using namespace std;

pair<int, string> ary[1024];
char buf[32];

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s%d", buf, &ary[i].first);
			ary[i].second = buf;
		}
		nth_element(ary, ary+n-2, ary+n);
		puts(ary[n-2].second.c_str());
	}
	return 0;
}

