#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	bool found = false;
	for (i=1; i<n; i++)
	{
		int a = min(s[i], s[i-1]);
		int b = max(s[i], s[i-1]);
		if (a == 'a' && b == 'b')
		{
			found = true;
		}
	}
	puts(found ? "Yes" : "No");
	return 0;
}
