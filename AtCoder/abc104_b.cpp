#include <iostream>
using namespace std;

int main()
{
	int i;
	char buf[16];
	scanf("%s", buf);
	string s = buf;
	string t;
	int pos[16];
	for (i=0; i<s.size(); i++)
	{
		if (isupper(s[i]))
		{
			pos[t.size()] = i;
			t += s[i];
		}
	}
	bool ac = false;
	if (t == "AC")
	{
		if (pos[0] == 0 && pos[1] >= 2 && pos[1] <= (int)s.size() - 2)
		{
			ac = true;
		}
	}
	puts(ac ? "AC" : "WA");
	return 0;
}
