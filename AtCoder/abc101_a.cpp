#include <iostream>
using namespace std;

const int N = 8;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	int ans = 0;
	for (i=0; s[i]; i++)
	{
		if (s[i] == '+')
		{
			++ans;
		}
		else
		{
			--ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
