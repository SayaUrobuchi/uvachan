#include <iostream>
#include <cctype>
using namespace std;

const char *key = "abcdefghijklmnopqrstuvwxyz0123456789";
const char *morse = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.. ----- .---- ..--- ...-- ....- ..... -.... --... ---.. ----.";

char s[128];
char tbl[128][16];

bool is_pal(const string &s)
{
	int i, j;
	if (s.empty())
	{
		return false;
	}
	for (i=0, j=(int)s.size()-1; i<j; i++, j--)
	{
		if (s[i] != s[j])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int i, p;
	for (i=0, p=0; key[i]; i++)
	{
		int t;
		sscanf(morse+p, " %s%n", tbl[key[i]], &t);
		p += t;
	}
	fgets(s, sizeof(s), stdin);
	string res;
	for (i=0; s[i]>=32; i++)
	{
		if (isalnum(s[i]))
		{
			if (isupper(s[i]))
			{
				s[i] = tolower(s[i]);
			}
			res += tbl[s[i]];
		}
	}
	printf("%d\n", is_pal(res));
	return 0;
}
