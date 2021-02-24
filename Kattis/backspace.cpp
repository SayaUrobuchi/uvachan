#include<iostream>
using namespace std;

char s[1048576];

int main()
{
	int i;
	string t;
	while (scanf("%s", s) == 1)
	{
		t.clear();
		for (i=0; s[i]; i++)
		{
			if (s[i] == '<')
			{
				if (t.size())
				{
					t.pop_back();
				}
			}
			else
			{
				t += s[i];
			}
		}
		puts(t.c_str());
	}
	return 0;
}
