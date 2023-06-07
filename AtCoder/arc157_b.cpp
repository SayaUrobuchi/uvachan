#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char s[200005];

int main()
{
	int n, m, i, j, ans, sum;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int k=0; k<2; k++)
	{
		vector<int> v;
		for (i=0, ans=0, sum=0; i<n; i=j)
		{
			for (j=i+1; j<n&&s[j]==s[i]; j++);
			int fix = 0;
			if (i == 0)
			{
				++fix;
			}
			if (j == n)
			{
				++fix;
			}
			if (s[i] == 'X')
			{
				sum += j-i;
				if (!fix)
				{
					v.emplace_back(j-i);
				}
			}
			else
			{
				ans += (j-i) - 1;
			}
		}
		if (sum == n)
		{
			ans = max(0, m-1);
			k = 2;
		}
		else if (m == sum)
		{
			ans = n-1;
			k = 2;
		}
		else if (m < sum)
		{
			sort(v.begin(), v.end());
			for (i=0; i<v.size()&&m>0; i++)
			{
				if (m >= v[i])
				{
					ans += v[i] + 1;
					m -= v[i];
				}
				else
				{
					ans += m;
					m = 0;
				}
			}
			ans += m;
			k = 2;
		}
		else
		{
			for (i=0; i<n; i++)
			{
				s[i] ^= 1;
			}
			m = n - m;
		}
	}
	printf("%d\n", ans);
	return 0;
}