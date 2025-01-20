#include <iostream>
using namespace std;

int main()
{
	int a, b, i;
	scanf("%d%d", &a, &b);
	int ans = 0;
	for (i=a; i<=b; i++)
	{
		string s = to_string(i);
		bool is_pal = true;
		int p, q;
		for (p=0, q=s.size()-1; p<q&&is_pal; ++p, --q)
		{
			if (s[p] != s[q])
			{
				is_pal = false;
			}
		}
		ans += is_pal;
	}
	printf("%d\n", ans);
	return 0;
}
