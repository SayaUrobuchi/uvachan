#include <iostream>
#include <cstring>
using namespace std;

int tbl[16], cnt[16], alter[16];
bool appeared[16];

int main()
{
	int i, j, t, pos, best;
	string s, ans;
	for (i=0; i<=9; i++)
	{
		tbl[i] = i;
		alter[i] = i;
	}
	tbl[5] = 2;
	tbl[9] = 6;
	alter[2] = 5;
	alter[6] = 9;
	while (cin >> s)
	{
		if (s == ".")
		{
			break;
		}
		memset(appeared, 0, sizeof(appeared));
		memset(cnt, 0, sizeof(cnt));
		pos = -1;
		for (i=s.size()-1; i>=0; i--)
		{
			if (s[i] != '.')
			{
				t = tbl[ s[i]-'0' ];
				++cnt[t];
				appeared[t] = true;
				appeared[alter[t]] = true;
				for (j=s[i]-'0'+1; j<=9; j++)
				{
					if (appeared[j])
					{
						break;
					}
				}
				if (j <= 9)
				{
					pos = i;
					best = j;
					break;
				}
			}
		}
		if (pos == -1)
		{
			cout << "The price cannot be raised.\n";
		}
		else
		{
			ans = s.substr(0, pos);
			ans += '0'+best;
			--cnt[tbl[best]];
			for (i=0; i<=9; i++)
			{
				while (cnt[i])
				{
					--cnt[i];
					ans += '0'+i;
				}
			}
			if (ans[ans.size()-2] != '.')
			{
				ans.insert(ans.end()-1, '.');
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
