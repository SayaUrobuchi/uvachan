#include <iostream>
using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int n, i;
	string t;
	scanf("%d%s", &n, s);
	for (i=0; i<n; i++)
	{
		t += s[i];
		if (t.size() >= 3 && t.substr(t.size()-3) == "fox")
		{
			t.resize(t.size()-3);
		}
	}
	printf("%llu\n", t.size());
	return 0;
}
