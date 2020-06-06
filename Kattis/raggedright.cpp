#include <iostream>
using namespace std;

int ary[1024];

int main()
{
	int best, i, j, ans;
	string s;
	best = 0;
	i = 0;
	while (getline(cin, s))
	{
		ary[i] = s.size();
		if (ary[i] > best)
		{
			best = ary[i];
		}
		i++;
	}
	for (j=0, ans=0; j<i-1; j++)
	{
		ans += (best-ary[j]) * (best-ary[j]);
	}
	cout << ans << "\n";
	return 0;
}
