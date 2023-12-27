#include <iostream>
#include <algorithm>
using namespace std;

int ary[2];
char buf[256], rev[128];

int trans(const char *buf)
{
	string s = buf;
	int i;
	reverse(s.begin(), s.end());
	for (i=0; i<s.size(); i++)
	{
		s[i] = rev[s[i]];
	}
	return stol(s);
}

int main()
{
	int i;
	for (i='0'; i<='9'; i++)
	{
		rev[i] = i;
	}
	swap(rev['2'], rev['5']);
	for (i=0; i<2; i++)
	{
		scanf("%s", buf);
		ary[i] = trans(buf);
	}
	puts(ary[0]>ary[1]?"1":"2");
	return 0;
}
