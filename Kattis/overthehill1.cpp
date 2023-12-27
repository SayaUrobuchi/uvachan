#include <iostream>
using namespace std;

const int N = 16;
const int M = 37;

int mat[N][N];
char tbl[128];
char buf[128];

int main()
{
	int n, i, j, k;
	string key;
	for (i='A'; i<='Z'; i++)
	{
		key += (char)i;
	}
	for (i='0'; i<='9'; i++)
	{
		key += (char)i;
	}
	key += ' ';
	for (i=0; i<key.size(); i++)
	{
		tbl[key[i]] = i;
	}
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	fgets(buf, sizeof(buf), stdin);
	fgets(buf, sizeof(buf), stdin);
	string s = buf;
	s.pop_back();
	//printf("%d\n", (int)s.size());
	while (s.size() % n)
	{
		s += ' ';
	}
	string t;
	for (i=0; i<s.size(); i++)
	{
		int c = 0;
		for (j=0, k=i-i%n; j<n; j++)
		{
			int p = tbl[s[k+j]];
			c = (c + mat[i%n][j] * p) % M;
		}
		t += key[c];
	}
	puts(t.c_str());
	return 0;
}