#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	int ans = 0;
	for (i=0; s[i]; i++)
	{
		if (s[i] == 'w')
		{
			ans += 2;
		}
		else
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
