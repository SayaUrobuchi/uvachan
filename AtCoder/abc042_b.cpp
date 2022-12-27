#include <iostream>
#include <algorithm>
using namespace std;

char buf[128];
string str[128];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		str[i] = buf;
	}
	sort(str, str+n);
	for (i=0; i<n; i++)
	{
		printf("%s", str[i].c_str());
	}
	puts("");
	return 0;
}