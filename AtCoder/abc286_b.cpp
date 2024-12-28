#include <iostream>
using namespace std;

const int N = 1024;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	string ans;
	for (i=0; i<n; i++)
	{
		if (i && s[i] == 'a' && s[i-1] == 'n')
		{
			ans += "y";
		}
		ans += s[i];
	}
	puts(ans.c_str());
	return 0;
}
