#include <iostream>
using namespace std;

const int MAX_L = 20;

int cnt[MAX_L+5];

int main()
{
	int n, a, b, i, j, t, sum, ans;
	scanf("%d%d%d", &n, &a, &b);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		++cnt[t];
	}
	for (i=1, sum=0, ans=0; i<=MAX_L; i++)
	{
		bool full = true;
		for (j=0; j<cnt[i]; j++)
		{
			sum += i * a;
			if (sum > b * (ans+1))
			{
				full = false;
				break;
			}
			++ans;
		}
		if (!full)
		{
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
