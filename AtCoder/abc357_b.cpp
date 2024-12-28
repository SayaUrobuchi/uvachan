#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	string s = buf;
	int upp = 0;
	int low = 0;
	for (i=0; i<s.size(); i++)
	{
		if (islower(s[i]))
		{
			++low;
		}
		else
		{
			++upp;
		}
	}
	for (i=0; i<s.size(); i++)
	{
		if (upp > low)
		{
			s[i] = toupper(s[i]);
		}
		else
		{
			s[i] = tolower(s[i]);
		}
	}
	puts(s.c_str());
	return 0;
}
