#include <iostream>
using namespace std;

char s[128];

int main()
{
	int i;
	char c;
	scanf("%s %c", s, &c);
	string ans;
	for (i=0; s[i]; i++)
	{
		ans += s[i];
		if (s[i] == c)
		{
			ans += s[i];
		}
	}
	puts(ans.c_str());
	return 0;
}