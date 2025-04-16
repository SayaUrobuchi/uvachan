#include <iostream>
using namespace std;

const int N = 128;
const int SLEN = 16;

char buf[SLEN];
string s[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	bool ok = true;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		s[i] = buf;
		if (i > 0 && s[i][0] != s[i-1].back())
		{
			ok = false;
		}
		for (j=0; j<i&&ok; j++)
		{
			if (s[i] == s[j])
			{
				ok = false;
			}
		}
	}
	puts(ok ? "Yes" : "No");
	return 0;
}
