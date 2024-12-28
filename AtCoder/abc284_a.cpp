#include <iostream>
#include <algorithm>
using namespace std;

const int N = 16;
const int SN = 16;

string str[N];
char buf[SN];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		str[i] = buf;
	}
	reverse(str, str+n);
	for (i=0; i<n; i++)
	{
		puts(str[i].c_str());
	}
	return 0;
}
