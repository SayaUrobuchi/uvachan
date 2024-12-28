#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e7+5;

char s[N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	fgets(s, sizeof(s), stdin);
	fgets(s, sizeof(s), stdin);
	s[n] = 0;
	int ans = n;
	for (i=1; i+i<=n; i++)
	{
		if (n % i == 0)
		{
			bool rep = true;
			// for (j=i; j<n&&rep; j+=i)
			// {
				// if (strncmp(s, s+j, i))
				// {
					// rep = false;
				// }
			// }
			for (j=0; j<i&&rep; j++)
			{
				for (k=j+i; k<n&&rep; k+=i)
				{
					if (s[k] != s[j])
					{
						rep = false;
					}
				}
			}
			if (rep)
			{
				ans = i;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}