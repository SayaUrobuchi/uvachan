#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10005;

char buf[128];
string str[N];

bool is_prefix(const string &s, const string &pat)
{
	return s.rfind(pat, 0) == 0;
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%s", buf);
			str[i] = buf;
		}
		sort(str, str+n);
		bool ok = true;
		for (i=1; i<n&&ok; i++)
		{
			if (is_prefix(str[i], str[i-1]))
			{
				ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
