#include <iostream>
using namespace std;

const string KEY = "MARCH";

int cnt[8];
int tbl[128];
char s[16];

int main()
{
	int n, i, j, k;
	for (i=0; i<KEY.size(); i++)
	{
		tbl[KEY[i]] = i + 1;
	}
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		++cnt[tbl[s[0]]];
	}
	long long ans = 0;
	for (i=1; i<=KEY.size(); i++)
	{
		for (j=i+1; j<=KEY.size(); j++)
		{
			for (k=j+1; k<=KEY.size(); k++)
			{
				ans += 1LL*cnt[i]*cnt[j]*cnt[k];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
