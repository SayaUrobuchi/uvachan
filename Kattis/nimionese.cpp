#include <iostream>
using namespace std;

const char *tk = "bcdgknpt";
const char *tt = "aou";

int tbl[128], tail[128];

int main()
{
	int i, j, mod;
	char last, better;
	bool ws, ss;
	string s;
	for (i=0; tk[i]; i++)
	{
		tbl[tk[i]] = 1;
	}
	for (i=0; tt[i]; i++)
	{
		tail[tt[i]] = 1;
	}
	while (getline(cin, s))
	{
		for (i=0, ws=true, ss=false, last=0; i<=s.size(); i++)
		{
			if (i == s.size() || s[i] == ' ')
			{
				if (tbl[last])
				{
					for (j=1; ; j++)
					{
						if (last-j >= 'a' && tail[last-j])
						{
							last -= j;
							break;
						}
						if (last+j <= 'z' && tail[last+j])
						{
							last += j;
							break;
						}
					}
					cout << last << 'h';
				}
				ws = true;
				ss = false;
				if (i < s.size())
				{
					cout << " ";
				}
			}
			else if (s[i] == '-')
			{
				ss = true;
			}
			else
			{
				last = (s[i] | 32);
				mod = ((s[i] & 32) ? ~0 : ~32);
				if (ws)
				{
					if (!tbl[last])
					{
						for (j=1; ; j++)
						{
							if (last-j >= 'a' && tbl[last-j])
							{
								last -= j;
								break;
							}
							if (last+j <= 'z' && tbl[last+j])
							{
								last += j;
								break;
							}
						}
					}
					better = last;
				}
				else if (ss && tbl[last])
				{
					last = better;
				}
				ws = false;
				cout << (char)(last&mod);
			}
		}
		cout << "\n";
	}
	return 0;
}
