#include <iostream>
#include <vector>
using namespace std;

const int END = 1;
const int HOME = 0;

void mov(string &s, vector<string> &v)
{
	if (s.size())
	{
		v.emplace_back(s);
		s.clear();
	}
}

int main()
{
	int count, i, idx, pos;
	string s, tmp;
	vector<string> str;
	getline(cin, s);
	sscanf(s.c_str(), "%d", &count);
	while (count--)
	{
		getline(cin, s);
		tmp.clear();
		str.clear();
		pos = END;
		idx = 0;
		str.emplace_back("");
		for (i=0; i<s.size(); i++)
		{
			if (s[i] == '[')
			{
				mov(tmp, str);
				pos = HOME;
			}
			else if (s[i] == ']')
			{
				mov(tmp, str);
				pos = END;
			}
			else if (s[i] == '<')
			{
				if (pos == END)
				{
					if (str[idx].size())
					{
						str[idx].pop_back();
						if (str[idx].empty() && idx+1 < str.size())
						{
							++idx;
						}
					}
				}
				else
				{
					if (tmp.size())
					{
						tmp.pop_back();
					}
				}
			}
			else
			{
				if (pos == END)
				{
					str[idx] += s[i];
				}
				else
				{
					tmp += s[i];
				}
			}
		}
		mov(tmp, str);
		for (i=str.size()-1; i>=0; i--)
		{
			printf("%s", str[i].c_str());
		}
		puts("");
	}
	return 0;
}