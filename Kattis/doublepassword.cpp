#include <iostream>
using namespace std;

int main()
{
	int i, ans;
	char s1[8], s2[8];
	scanf("%s%s", s1, s2);
	for (i=0, ans=1; s1[i]; i++)
	{
		ans *= 1 + (s1[i] != s2[i]);
	}
	printf("%d\n", ans);
	return 0;
}
