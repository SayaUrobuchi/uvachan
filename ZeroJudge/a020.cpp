#include <iostream>
using namespace std;

//           0123456789012345678901234567890123456789
string id = "__________ABCDEFGHJKLMNPQRSTUVXYWZIO";
int tbl[128];

int main()
{
	int i, j, ans;
	string s;
	for (i=0; i<id.size(); i++)
	{
		tbl[ id[i] ] = i;
	}
	while (cin >> s)
	{
		ans = tbl[s[0]]/10 + (tbl[s[0]]%10 * 9);
		for (i=1, j=8; j>0; i++, j--)
		{
			ans += (s[i]-'0') * j;
		}
		ans += s[i] - '0';
		cout << (ans%10?"fake":"real") << "\n";
	}
	return 0;
}
