#include <iostream>
using namespace std;

char buf[55];
string s[105];

bool ispalin(const string &s)
{
	int i, j;
	for (i=0, j=s.size()-1; i<j; i++, j--)
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
	int n, i, j;
	scanf("%d", &n);
	bool found = false;
	for (i=0; i<n&&!found; i++)
	{
		scanf("%s", buf);
		s[i] = buf;
		for (j=0; j<i&&!found; j++)
		{
			if (ispalin(s[i]+s[j]) || ispalin(s[j]+s[i]))
			{
				found = true;
			}
		}
	}
	puts(found ? "Yes" : "No");
	return 0;
}
