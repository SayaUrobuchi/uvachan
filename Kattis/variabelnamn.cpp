#include <iostream>
#include <set>
using namespace std;

const int N = 10005;

int nxt[N];

int main()
{
	int n, i, t;
	set<int> se;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		if (!nxt[t])
		{
			nxt[t] = t;
		}
		while (se.count(nxt[t]))
		{
			nxt[t] += t;
		}
		se.insert(nxt[t]);
		printf("%d\n", nxt[t]);
	}
	return 0;
}
