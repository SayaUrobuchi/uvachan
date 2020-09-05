#include <iostream>
#include <algorithm>
using namespace std;

int ary[1048576];

int main()
{
	int n, i, ad, cur;
	string s, t;
	while (cin >> s >> t)
	{
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		for (i=0, ad=0; i<s.size()||i<t.size(); i++)
		{
			cur = ad;
			if (i < s.size())
			{
				cur += s[i] - '0';
			}
			if (i < t.size())
			{
				cur += t[i] - '0';
			}
			ary[i] = cur%10;
			ad = cur/10;
		}
		if (ad)
		{
			ary[i++] = ad;
		}
		n = i;
		reverse(ary, ary+n);
		for (i=0; i<n; i++)
		{
			cout << ary[i];
		}
		cout << "\n";
	}
	return 0;
}
