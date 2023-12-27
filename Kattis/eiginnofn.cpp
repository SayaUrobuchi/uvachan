#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<string, string>;

const int N = 100005;
const int BUF_N = 32;
const string NONE = " ";

pp ary[N];
char buf[BUF_N], buf0[BUF_N], buf1[BUF_N];

int main()
{
	int n, m, i;
	scanf("%d", &n);
	fgets(buf, sizeof(buf), stdin);
	for (i=0; i<n; i++)
	{
		fgets(buf, sizeof(buf), stdin);
		int c = sscanf(buf, "%s%s", buf0, buf1);
		ary[i].first = buf0;
		ary[i].second = (c == 1 ? NONE : buf1);
	}
	sort(ary, ary+n);
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%s", buf);
		string tmp = buf;
		int id = lower_bound(ary, ary+n, make_pair(tmp, NONE)) - ary;
		if (id >= n || ary[id].first != tmp)
		{
			puts("Neibb");
		}
		else if (ary[id].second == NONE)
		{
			puts("Jebb");
		}
		else
		{
			printf("Neibb en %s %s er heima\n", 
					tmp.c_str(), ary[id].second.c_str());
		}
	}
	return 0;
}
