#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<string, int>;

const int N = 100005;
const int BLEN = 16;

pp nam[N];
char buf[BLEN], buf2[BLEN];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		nam[i].first = buf;
		nam[i].second = i;
	}
	sort(nam, nam+n);
	for (i=0; i<m; i++)
	{
		scanf("%s%s", buf, buf2);
		string t = buf;
		int a = lower_bound(nam, nam+n, make_pair(t, -1))->second;
		string u = buf2;
		int b = lower_bound(nam, nam+n, make_pair(u, -1))->second;
		int d = abs(a - b);
		printf("%d\n", d-1);
	}
	return 0;
}
