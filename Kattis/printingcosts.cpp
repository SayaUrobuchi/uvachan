#include <iostream>
using namespace std;

int tbl[128];

int main()
{
	int i, ans;
	string s;
	tbl['!'] = 9;
	tbl['"'] = 6;
	tbl['#'] = 24;
	tbl['$'] = 29;
	tbl['%'] = 22;
	tbl['&'] = 24;
	tbl['\''] = 3;
	tbl['('] = 12;
	tbl[')'] = 12;
	tbl['*'] = 17;
	tbl['+'] = 13;
	tbl[','] = 7;
	tbl['-'] = 7;
	tbl['.'] = 4;
	tbl['/'] = 10;
	tbl['0'] = 22;
	tbl['1'] = 19;
	tbl['2'] = 22;
	tbl['3'] = 23;
	tbl['4'] = 21;
	tbl['5'] = 27;
	tbl['6'] = 26;
	tbl['7'] = 16;
	tbl['8'] = 23;
	tbl['9'] = 26;
	tbl[':'] = 8;
	tbl[';'] = 11;
	tbl['<'] = 10;
	tbl['='] = 14;
	tbl['>'] = 10;
	tbl['?'] = 15;
	tbl['@'] = 32;
	tbl['A'] = 24;
	tbl['B'] = 29;
	tbl['C'] = 20;
	tbl['D'] = 26;
	tbl['E'] = 26;
	tbl['F'] = 20;
	tbl['G'] = 25;
	tbl['H'] = 25;
	tbl['I'] = 18;
	tbl['J'] = 18;
	tbl['K'] = 21;
	tbl['L'] = 16;
	tbl['M'] = 28;
	tbl['N'] = 25;
	tbl['O'] = 26;
	tbl['P'] = 23;
	tbl['Q'] = 31;
	tbl['R'] = 28;
	tbl['S'] = 25;
	tbl['T'] = 16;
	tbl['U'] = 23;
	tbl['V'] = 19;
	tbl['W'] = 26;
	tbl['X'] = 18;
	tbl['Y'] = 14;
	tbl['Z'] = 22;
	tbl['['] = 18;
	tbl['\\'] = 10;
	tbl[']'] = 18;
	tbl['^'] = 7;
	tbl['_'] = 8;
	tbl['`'] = 3;
	tbl['a'] = 23;
	tbl['b'] = 25;
	tbl['c'] = 17;
	tbl['d'] = 25;
	tbl['e'] = 23;
	tbl['f'] = 18;
	tbl['g'] = 30;
	tbl['h'] = 21;
	tbl['i'] = 15;
	tbl['j'] = 20;
	tbl['k'] = 21;
	tbl['l'] = 16;
	tbl['m'] = 22;
	tbl['n'] = 18;
	tbl['o'] = 20;
	tbl['p'] = 25;
	tbl['q'] = 25;
	tbl['r'] = 13;
	tbl['s'] = 21;
	tbl['t'] = 17;
	tbl['u'] = 17;
	tbl['v'] = 13;
	tbl['w'] = 19;
	tbl['x'] = 13;
	tbl['y'] = 24;
	tbl['z'] = 19;
	tbl['{'] = 18;
	tbl['|'] = 12;
	tbl['}'] = 18;
	tbl['~'] = 9;
	while (getline(cin, s))
	{
		for (i=0, ans=0; i<s.size(); i++)
		{
			ans += tbl[s[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}
