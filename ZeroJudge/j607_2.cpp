#include <iostream>
using namespace std;

int p;
string s;

long long operand()
{
	long long expr();
	long long res, pos;
	if (s[p] == 'f')
	{
		long long big = -1e18;
		long long small = 1e18;
		++p;
		while (s[p] != ')')
		{
			++p;
			long long nxt = expr();
			big = max(big, nxt);
			small = min(small, nxt);
		}
		++p;
		res = big - small;
	}
	else
	{
		sscanf(s.c_str()+p, "%lld%n", &res, &pos);
		p += pos;
	}
	return res;
}

long long expr()
{
	long long tmp = 0;
	long long ans = 1;
	while (p < s.size())
	{
		long long nxt = operand();
		tmp += nxt;
		char op = s[p];
		if (op == '*')
		{
			ans *= tmp;
			tmp = 0;
		}
		else if (op != '+')
		{
			break;
		}
		++p;
	}
	return ans * tmp;
}

int main()
{
	getline(cin, s);
	s += " ";
	p = 0;
	printf("%lld\n", expr());
	return 0;
}
