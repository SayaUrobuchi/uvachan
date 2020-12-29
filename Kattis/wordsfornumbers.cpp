#include <iostream>
#include <sstream>
using namespace std;

string tbl[100] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", 
	"twenty"
};

int main()
{
	int n, i, j;
	bool first, sent;
	string s;
	tbl[30] = "thirty";
	tbl[40] = "forty";
	tbl[50] = "fifty";
	tbl[60] = "sixty";
	tbl[70] = "seventy";
	tbl[80] = "eighty";
	tbl[90] = "ninety";
	for (i=20; i<=90; i+=10)
	{
		for (j=1; j<=9; j++)
		{
			tbl[i+j] = tbl[i] + "-" + tbl[j];
		}
	}
	while (getline(cin, s))
	{
		stringstream ss(s);
		first = true;
		sent = true;
		while (ss >> s)
		{
			if (!first)
			{
				cout << " ";
			}
			first = false;
			if (s[0] >= '0' && s[0] <= '9')
			{
				sscanf(s.c_str(), "%d", &n);
				if (sent)
				{
					tbl[n][0] -= 32;
				}
				cout << tbl[n];
				if (sent)
				{
					tbl[n][0] += 32;
				}
			}
			else
			{
				cout << s;
			}
			sent = false;
		}
		cout << "\n";
	}
	return 0;
}
