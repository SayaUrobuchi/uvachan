#include <iostream>
using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int n;
	scanf("%d%s", &n, s);
	bool ans = true;
	if (n >= 3 && s[0] == 'A' && s[n-1] == 'B')
	{
		ans = false;
	}
	else if (n == 2 && s[0] != s[1])
	{
		ans = false;
	}
	puts(ans ? "Yes" : "No");
	return 0;
}