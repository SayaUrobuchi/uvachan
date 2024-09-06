#include <iostream>
using namespace std;

char s[200005];

int main()
{
	int n, i, j, k, t;
	scanf("%d%s", &n, s);
	for (i=0, t=1; i<n; )
	{
		for (j=i; j<=n&&s[j]=='L'; j++);
		for (k=t+j-i; k>=t; k--)
		{
			printf("%d\n", k);
		}
		t += j-i + 1;
		i = j+1;
	}
	return 0;
}