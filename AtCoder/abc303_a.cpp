#include <iostream>
using namespace std;

const int N = 128;

char s[N], t[N];

int main()
{
	int n, i;
	scanf("%d%s%s", &n, s, t);
	bool is_similar = true;
	for (i=0; i<n&&is_similar; i++)
	{
		if (s[i] != t[i])
		{
			int a = min(s[i], t[i]);
			int b = max(s[i], t[i]);
			bool pass = (a == '0' && b == 'o')
						|| (a == '1' && b == 'l');
			if (!pass)
			{
				is_similar = false;
			}
		}
	}
	puts(is_similar ? "Yes" : "No");
	return 0;
}
