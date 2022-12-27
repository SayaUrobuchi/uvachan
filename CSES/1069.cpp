#include <iostream>
using namespace std;

int main()
{
	int i, j, ans;
	string s;
	while (cin >> s)
	{
		for (i=0, ans=0; i<s.size(); i=j)
		{
			for (j=i+1; j<s.size()&&s[j]==s[i]; j++);
			ans = max(ans, j-i);
		}
		cout << ans << "\n";
	}
	return 0;
}

