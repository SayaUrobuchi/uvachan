#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i, j, c, ans;
	string s, t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	for (i=0, ans=s.size(); i<ans; i++)
	{
		for (j=0, c=0; j+i<s.size(); j++)
		{
			c += (s[j+i] != t[j]);
		}
		ans = min(ans, i+(c>>1));
	}
	printf("%d\n", ans);
	return 0;
}