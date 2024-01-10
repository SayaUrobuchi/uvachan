#include <iostream>
using namespace std;

const int M = 3200005;

int p, root;
int trie[M][26];
int cnt[M];
char buf[64];

inline int gen_node()
{
	return p++;
}

int search(int cur, const char *s)
{
	++cnt[cur];
	if (!*s)
	{
		return cnt[cur] - 1;
	}
	int b = *s - 'a';
	if (!trie[cur][b])
	{
		trie[cur][b] = gen_node();
	}
	return search(trie[cur][b], s+1);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	root = 1;
	p = 2;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		int ans = search(root, buf);
		printf("%d\n", ans);
	}
	return 0;
}
