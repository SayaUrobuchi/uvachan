#include <iostream>
#include <sstream>
using namespace std;

bool ary[1024], stk[1024];

int main()
{
	int n, i, sn;
	string s;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> s;
			ary[i] = (s[0] == 'T');
		}
		getline(cin, s);
		getline(cin, s);
		stringstream ss(s);
		sn = -1;
		while (ss >> s)
		{
			if (s[0] == '+')
			{
				stk[sn-1] += stk[sn];
				--sn;
			}
			else if (s[0] == '-')
			{
				stk[sn] = !stk[sn];
			}
			else if (s[0] == '*')
			{
				stk[sn-1] *= stk[sn];
				--sn;
			}
			else
			{
				stk[++sn] = ary[s[0]-'A'];
			}
		}
		puts(stk[0] ? "T" : "F");
	}
	return 0;
}
