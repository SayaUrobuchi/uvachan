#include <iostream>
#include <map>
using namespace std;

string dig[4][10] = {
	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
	{"", "M", "MM", "MMM", "", "", "", "", "", ""},
};
string roma[4000];
map<string, int> roma_rev;

int main()
{
	int i, j, k;
	string s;
	for (i=1; i<4000; i++)
	{
		for (j=0, k=i; j<4; j++, k/=10)
		{
			roma[i] = dig[j][k%10] + roma[i];
		}
		roma_rev[ roma[i] ] = i;
	}
	while (getline(cin, s))
	{
		if (s[0] >= '0' && s[0] <= '9')
		{
			sscanf(s.c_str(), "%d", &i);
			cout << roma[i] << "\n";
		}
		else
		{
			cout << roma_rev[s] << "\n";
		}
	}
	return 0;
}
