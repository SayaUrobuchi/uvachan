#include <iostream>
using namespace std;

const int N = 100005;

char buf[N];

int main()
{
	int i, j;
	scanf("%s", buf);
	string s = buf;
	bool is_able = true;
	int ans = 0;
	for (i=0, j=s.size()-1; i<j&&is_able; )
	{
		if (s[i] == s[j])
		{
			++i;
			--j;
		}
		else
		{
			if (s[i] == 'x')
			{
				++ans;
				++i;
			}
			else if (s[j] == 'x')
			{
				++ans;
				--j;
			}
			else
			{
				is_able = false;
			}
		}
	}
	if (!is_able)
	{
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}