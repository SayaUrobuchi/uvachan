#include <iostream>
using namespace std;

int main()
{
	int n, i;
	char buf[128];
	scanf("%d%s", &n, buf);
	const string KEY = "|*|";
	string s;
	for (i=0; i<n; i++)
	{
		if (buf[i] != '.')
		{
			s += buf[i];
		}
	}
	puts(s == KEY ? "in" : "out");
	return 0;
}
