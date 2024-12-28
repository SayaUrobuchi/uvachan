#include <iostream>
using namespace std;

const int N = 128;

char s[N], t[N], fmt[N];

int main()
{
	int a, b, i;
	scanf("%d%d%s", &a, &b, s);
	bool gg = false;
	for (i=0; i<a+b+1&&!gg; i++)
	{
		if (i == a && s[i] != '-')
		{
			gg = true;
		}
		else if (i != a && s[i] == '-')
		{
			gg = true;
		}
	}
	puts(gg ? "No" : "Yes");
	return 0;
}
