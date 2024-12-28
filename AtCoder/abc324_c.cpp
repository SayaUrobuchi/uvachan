#include <iostream>
#include <vector>
using namespace std;

const int N = 500005;

char buf[N];

int main()
{
	int n, i, j;
	scanf("%d%s", &n, buf);
	string s = buf;
	vector<int> ans;
	for (i=1; i<=n; i++)
	{
		scanf("%s", buf);
		string t = buf;
		if (abs((int)s.size() - (int)t.size()) <= 1)
		{
			for (j=0; j<s.size()&&j<t.size()&&s[j]==t[j]; j++);
			bool ok = false;
			if (s.size() < t.size())
			{
				if (s.substr(j) == t.substr(j+1))
				{
					ok = true;
				}
			}
			else if (s.size() > t.size())
			{
				if (s.substr(j+1) == t.substr(j))
				{
					ok = true;
				}
			}
			else
			{
				if (j == s.size() || s.substr(j+1) == t.substr(j+1))
				{
					ok = true;
				}
			}
			if (ok)
			{
				ans.emplace_back(i);
			}
		}
	}
	printf("%llu\n", ans.size());
	for (i=0; i<ans.size(); i++)
	{
		printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
	}
	return 0;
}
