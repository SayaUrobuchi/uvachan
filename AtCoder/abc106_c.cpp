#include <iostream>
using namespace std;

const int N = 105;

char s[N];

int main()
{
	int i;
	long long n;
	scanf("%s%lld", s, &n);
	int ans = 0;
	for (i=0; s[i]; i++)
	{
		if (s[i] != '1' || i+1 == n)
		{
			ans = s[i] - '0';
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
