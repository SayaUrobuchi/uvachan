#include <iostream>
using namespace std;

int ucnt;
int used[128];

int main()
{
	int i, j, a, b;
	string s, t;
	while (getline(cin, s))
	{
		getline(cin, t);
		++ucnt;
		for (i=0, a=0; i<s.size(); i=j, a=b)
		{
			for (j=i+1; j<s.size()&&s[j]==s[i]; j++);
			for (b=a+1; b<t.size()&&t[b]==t[a]; b++);
			if (j-i != b-a)
			{
				if (used[s[i]] != ucnt)
				{
					used[s[i]] = ucnt;
					putchar(s[i]);
				}
			}
		}
		puts("");
	}
	return 0;
}