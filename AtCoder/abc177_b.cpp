#include <iostream>
using namespace std;

char buf[2][1005];

int main()
{
	int i, j;
	scanf("%s%s", buf[0], buf[1]);
	string s = buf[0];
	string t = buf[1];
	int ans = t.size();
	for (i=0; i+t.size()<=s.size(); i++)
	{
		int cnt = 0;
		for (j=0; j<t.size(); j++)
		{
			if (t[j] != s[i+j])
			{
				++cnt;
			}
		}
		ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
