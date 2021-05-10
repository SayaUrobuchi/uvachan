#include <iostream>
#include <algorithm>
using namespace std;

char s[1024];

int main()
{
	int n, i;
	string p, q, res;
	while (scanf("%s", s) == 1)
	{
		if (*s == '0')
		{
			break;
		}
		p.clear();
		q.clear();
		n = 0;
		for (i=0; s[i]; i++)
		{
			if (s[i] == 'N')
			{
				++n;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				q += s[i];
			}
			else
			{
				p += s[i];
			}
		}
		if (p.size())
		{
			res.clear();
			res += p.back();
			p.pop_back();
			while (n--)
			{
				res += 'N';
			}
			while (p.size()&&q.size())
			{
				res += p.back();
				p.pop_back();
				res += q.back();
				q.pop_back();
			}
			reverse(res.begin(), res.end());
			puts(res.c_str());
		}
		else
		{
			puts("no WFF possible");
		}
	}
	return 0;
}
