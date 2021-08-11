#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i, j;
	string s, ans;
	while (cin >> s)
	{
		ans = s;
		for (i=1; i+1<s.size(); i++)
		{
			for (j=i+1; j<s.size(); j++)
			{
				reverse(s.begin(), s.begin()+i);
				reverse(s.begin()+i, s.begin()+j);
				reverse(s.begin()+j, s.end());
				if (s < ans)
				{
					ans = s;
				}
				reverse(s.begin(), s.begin()+i);
				reverse(s.begin()+i, s.begin()+j);
				reverse(s.begin()+j, s.end());
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
