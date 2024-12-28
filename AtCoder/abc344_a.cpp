#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	string ans;
	bool need = true;
	for (i=0; s[i]; i++)
	{
		if (s[i] == '|')
		{
			need = !need;
		}
		else
		{
			if (need)
			{
				ans += s[i];
			}
		}
	}
	puts(ans.c_str());
	return 0;
}
