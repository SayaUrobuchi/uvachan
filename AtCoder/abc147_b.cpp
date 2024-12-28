#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	string s = buf;
	int ans = 0;
	for (i=0; i<s.size(); i++)
	{
		if (s[i] != s.back())
		{
			++ans;
		}
		s.pop_back();
	}
	printf("%d\n", ans);
	return 0;
}
