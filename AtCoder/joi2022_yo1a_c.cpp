#include <iostream>
using namespace std;

char s[128];
bool appear[128];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		if (!appear[s[i]])
		{
			++ans;
		}
		appear[s[i]] = true;
	}
	puts(ans >= 3 ? "Yes" : "No");
	return 0;
}
