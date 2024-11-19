#include <iostream>
#include <cstring>
using namespace std;

const int N = 200005;

char s0[N], s1[N];

int main()
{
	int n0, n1, i, j;
	scanf("%s%s", s0, s1);
	n0 = strlen(s0);
	n1 = strlen(s1);
	bool ok = true;
	for (i=0, j=0; i<n0&&ok; )
	{
		int a, b, t;
		if (j >= n1 || s0[i] != s1[j])
		{
			ok = false;
			break;
		}
		for (t=i; t<n0&&s0[t]==s0[i]; t++);
		a = t - i;
		for (t=j; t<n1&&s1[t]==s1[j]; t++);
		b = t - j;
		if (a > b || (a == 1 && a != b))
		{
			ok = false;
			break;
		}
		i += a;
		j += b;
	}
	if (j < n1)
	{
		ok = false;
	}
	puts(ok ? "Yes" : "No");
	return 0;
}