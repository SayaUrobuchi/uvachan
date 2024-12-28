#include <iostream>
using namespace std;

const int N = 16;

char s[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	int agree = 0;
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		string t = s;
		agree += (t == "For");
	}
	bool ans = (agree + agree > n);
	puts(ans ? "Yes" : "No");
	return 0;
}
