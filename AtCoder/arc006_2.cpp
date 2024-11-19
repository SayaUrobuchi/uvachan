#include <iostream>
using namespace std;

const int N = 16;

int pos[N];
char s[N<<2];

int main()
{
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	fgets(s, sizeof(s), stdin);
	for (i=1; i<=n; i++)
	{
		pos[i] = i;
	}
	for (i=0; i<m; i++)
	{
		fgets(s, sizeof(s), stdin);
		for (j=1, k=1; j<n; j++, k+=2)
		{
			if (s[k] == '-')
			{
				swap(pos[j], pos[j+1]);
			}
		}
	}
	int ans;
	fgets(s, sizeof(s), stdin);
	for (j=1, k=0; j<=n; j++, k+=2)
	{
		if (s[k] == 'o')
		{
			ans = pos[j];
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
