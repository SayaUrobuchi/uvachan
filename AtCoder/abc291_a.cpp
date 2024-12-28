#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	int ans;
	for (i=0; s[i]; i++)
	{
		if (isupper(s[i]))
		{
			ans = i + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
