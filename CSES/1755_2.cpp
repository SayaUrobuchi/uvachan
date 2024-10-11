#include <iostream>
using namespace std;

int appear[128];

int main()
{
	int i, j, k;
	string s;
	cin >> s;
	for (i=0; i<s.size(); i++)
	{
		++appear[s[i]];
	}
	int odd = 0;
	int odd_pos;
	for (i='A'; i<='Z'; i++)
	{
		if (appear[i] % 2 != 0)
		{
			++odd;
			odd_pos = i;
		}
	}
	if (odd >= 2)
	{
		cout << "NO SOLUTION\n";
	}
	else
	{
		string ans;
		ans.resize(s.size(), '?');
		for (i=0, j=s.size()-1, k='A'; i<j; i++, j--)
		{
			while (appear[k] < 2)
			{
				k++;
			}
			ans[i] = k;
			ans[j] = k;
			appear[k] -= 2;
		}
		if (s.size() % 2 != 0)
		{
			ans[s.size() / 2] = odd_pos;
		}
		cout << ans << "\n";
	}
	return 0;
}
