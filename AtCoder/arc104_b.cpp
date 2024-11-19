#include <iostream>
using namespace std;

const int N = 5005;

int tbl[128];
char s[N];

int main()
{
	int n, i, j;
	tbl['A'] = 0;
	tbl['T'] = 1;
	tbl['G'] = 2;
	tbl['C'] = 3;
	scanf("%d%s", &n, s);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int cnt[4] = {};
		for (j=i; j<n; j++)
		{
			++cnt[ tbl[s[j]] ];
			if (cnt[0] == cnt[1] && cnt[2] == cnt[3])
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
