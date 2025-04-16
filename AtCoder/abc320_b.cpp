#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int i, j;
	scanf("%s", buf);
	string s = buf;
	int ans = 1;
	for (i=0; i<s.size(); i++)
	{
		for (j=0; j<2; j++)
		{
			int a, b;
			for (a=i, b=i+j; a>=0&&b<s.size()&&s[a]==s[b]; --a, ++b);
			ans = max(ans, b-a-1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
