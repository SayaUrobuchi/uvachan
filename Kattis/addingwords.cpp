#include <iostream>
#include <map>
using namespace std;

const int BLEN = 64;

char buf[BLEN], buf2[BLEN], cmd[BLEN];

int main()
{
	map<string, int> str;
	map<int, string> num;
	while (scanf("%s", cmd) == 1)
	{
		int t;
		if (*cmd == 'd')
		{
			scanf("%s%d", buf, &t);
			decltype(str)::iterator it = str.find(buf);
			if (it != str.end())
			{
				num.erase(it->second);
			}
			str[buf] = t;
			num[t] = buf;
		}
		else if (cmd[1] == 'a')
		{
			bool is_plus = true;
			bool is_unknown = false;
			int res = 0;
			while (scanf("%s%s", buf, buf2) == 2)
			{
				printf("%s %s ", buf, buf2);
				decltype(str)::iterator it = str.find(buf);
				if (it == str.end())
				{
					is_unknown = true;
				}
				else
				{
					if (is_plus)
					{
						res += it->second;
					}
					else
					{
						res -= it->second;
					}
				}
				if (*buf2 == '=')
				{
					break;
				}
				else if (*buf2 == '+')
				{
					is_plus = true;
				}
				else
				{
					is_plus = false;
				}
			}
			string ans = "unknown";
			if (!is_unknown)
			{
				decltype(num)::iterator it2 = num.find(res);
				if (it2 != num.end())
				{
					ans = it2->second;
				}
			}
			puts(ans.c_str());
		}
		else
		{
			str.clear();
			num.clear();
		}
	}
	return 0;
}
