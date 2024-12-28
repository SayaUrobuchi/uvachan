#include <iostream>
using namespace std;

const string KEY[] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
const int N = 16;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	bool appear = false;
	for (i=0; i<sizeof(KEY)/sizeof(string); i++)
	{
		if (s == KEY[i])
		{
			appear = true;
		}
	}
	puts(appear ? "Yes" : "No");
	return 0;
}
