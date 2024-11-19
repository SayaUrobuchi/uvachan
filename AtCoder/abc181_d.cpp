#include <iostream>
using namespace std;

const int N = 200005;

int tbl[16];
char s[N];

bool dfs(int depth, int val)
{
	int i;
	if (depth == 4 || !s[depth])
	{
		return !(val & 7);
	}
	for (i=1; i<=9; i++)
	{
		if (tbl[i])
		{
			--tbl[i];
			bool res = dfs(depth+1, val*10+i);
			++tbl[i];
			if (res)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int i;
	scanf("%s", s);
	for (i=0; s[i]; i++)
	{
		++tbl[ s[i] - '0' ];
	}
	puts(dfs(0, 0) ? "Yes" : "No");
	return 0;
}
