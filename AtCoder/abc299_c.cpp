#include <iostream>
using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int n, i, j;
	scanf("%d%s", &n, s);
	int ans = -1;
	for (i=0; i<n; i=j)
	{
		if (s[i] == '-')
		{
			j = i + 1;
		}
		else
		{
			for (j=i+1; j<n&&s[j]=='o'; j++);
			if (i > 0 || j < n)
			{
				ans = max(ans, j-i);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}