#include <iostream>
using namespace std;

const int N = 128;
const string KEY = "aeiou";

bool del[128];
char buf[N];

int main()
{
	int i;
	for (i=0; i<KEY.size(); i++)
	{
		del[KEY[i]] = true;
	}
	scanf("%s", buf);
	string s = buf;
	string ans;
	for (i=0; i<s.size(); i++)
	{
		if (!del[s[i]])
		{
			ans += s[i];
		}
	}
	puts(ans.c_str());
	return 0;
}
