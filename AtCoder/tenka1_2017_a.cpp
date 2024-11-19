#include <iostream>
using namespace std;

const int N = 8;

char s[N];

int main()
{
	int i, ans;
	scanf("%s", s);
	for (i=0, ans=0; s[i]; i++)
	{
		ans += (s[i] == '1');
	}
	printf("%d\n", ans);
	return 0;
}