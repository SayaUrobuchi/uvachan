#include <iostream>
using namespace std;

const int N = 105;

char s[N], t[N];

int main()
{
	int i, j, ans;
	scanf("%s%s", s, t);
	for (i=0; s[i]&&t[i]&&s[i]==t[i]; i++);
	for (ans=0, j=i; s[j]; j++, ans++);
	for (j=i; t[j]; j++, ans++);
	printf("%d\n", ans);
	return 0;
}
