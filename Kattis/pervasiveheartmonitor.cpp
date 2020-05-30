#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
using namespace std;

string nam[256];
char buf[1024];

int main()
{
	int n, i, c, t;
	double sum, u;
	string s;
	while (getline(cin, s))
	{
		sum = 0;
		n = 0;
		c = 0;
		stringstream ss;
		if (sscanf(s.c_str(), "%lf", &u) != 1)
		{
			sscanf(s.c_str(), "%[^0-9]%n", buf, &t);
			ss << s.substr(t);
		}
		else
		{
			sscanf(s.c_str(), "%*[^A-Z]%n", &t);
			strcpy(buf, s.c_str()+t);
			ss << s.substr(0, t);
		}
		while (ss >> u)
		{
			sum += u;
			++c;
		}
		cout << fixed << setprecision(6) << sum/c << " " << buf << "\n";
	}
	return 0;
}
