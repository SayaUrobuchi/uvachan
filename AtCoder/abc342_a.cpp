#include <iostream>
using namespace std;

const int N = 128;

int pos[128], cnt[128];
char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	string s;
	for (i=0; buf[i]; i++)
	{
		if (!cnt[buf[i]])
		{
			s += buf[i];
		}
		++cnt[buf[i]];
		pos[buf[i]] = i + 1;
	}
	int ans;
	for (i=0; i<s.size(); i++)
	{
		if (cnt[s[i]] == 1)
		{
			ans = pos[s[i]];
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
