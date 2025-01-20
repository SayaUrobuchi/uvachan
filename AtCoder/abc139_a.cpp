#include <iostream>
using namespace std;

const int N = 8;

char s0[N], s1[N];

int main()
{
	int i;
	scanf("%s%s", s0, s1);
	int ans = 0;
	for (i=0; i<3; i++)
	{
		if (s0[i] == s1[i])
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
