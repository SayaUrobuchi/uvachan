#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 512;

char buf[N];

int main()
{
	int n, m, i, j;
	scanf("%s%d", buf, &m);
	string s = buf;
	n = s.size();
	int ans = 0;
	vector<string> str;
	if (m <= n)
	{
		for (i=0, j=m; j<=n; i++, j++)
		{
			str.emplace_back(s.substr(i, m));
		}
		sort(str.begin(), str.end());
		ans = unique(str.begin(), str.end()) - str.begin();
	}
	printf("%d\n", ans);
	return 0;
}
