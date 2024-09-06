#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		int n, i, j;
		scanf("%d%s", &n, s);
		vector<int> cnt(26);
		for (i=0; i<n; i++)
		{
			++cnt[s[i]-'a'];
		}
		string ans;
		for (i=0; i<n; i++)
		{
			int best = 0;
			int best_pos;
			for (j=0; j<26; j++)
			{
				if (cnt[j] > best)
				{
					best = cnt[j];
					best_pos = j;
				}
			}
			ans += best_pos + 'a';
			--cnt[best_pos];
		}
		puts(ans.c_str());
	}
	return 0;
}
