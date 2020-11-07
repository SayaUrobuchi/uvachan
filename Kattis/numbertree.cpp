#include <iostream>
using namespace std;

char buf[1048576];

int main()
{
	int h, i;
	long long ans;
	string s;
	while (getline(cin, s))
	{
		if (sscanf(s.c_str(), "%d%s", &h, buf) == 1)
		{
			*buf = 0;
		}
		for (i=0, ans=1; buf[i]; i++)
		{
			ans <<= 1;
			if (buf[i] == 'R')
			{
				++ans;
			}
		}
		printf("%lld\n", (1LL<<(h+1))-ans);
	}
	return 0;
}
