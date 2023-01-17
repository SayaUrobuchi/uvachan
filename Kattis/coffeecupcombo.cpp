#include <iostream>
using namespace std;

char s[100005];

int main()
{
	int n, i, ans, coffee;
	scanf("%d%s", &n, s);
	for (i=0, ans=0, coffee=0; i<n; i++)
	{
		if (s[i] == '1')
		{
			coffee = 3;
		}
		if (coffee)
		{
			++ans;
			--coffee;
		}
	}
	printf("%d\n", ans);
	return 0;
}
