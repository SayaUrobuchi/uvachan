#include <iostream>
using namespace std;

const int N = 100005;
const int LEFT = 1;
const int RIGHT = -1;

int tbl[128], mat[128];
char s[N], stk[N];

int main()
{
	int n, i, sn;
	tbl['('] = tbl['['] = tbl['{'] = LEFT;
	tbl[')'] = tbl[']'] = tbl['}'] = RIGHT;
	mat[')'] = '(';
	mat[']'] = '[';
	mat['}'] = '{';
	scanf("%d%s", &n, s);
	bool ok = true;
	for (i=0, sn=-1; ok&&i<n; i++)
	{
		if (tbl[s[i]] == LEFT)
		{
			stk[++sn] = s[i];
		}
		else if (tbl[s[i]] == RIGHT)
		{
			if (sn >= 0 && stk[sn] == mat[s[i]])
			{
				--sn;
			}
			else
			{
				ok = false;
			}
		}
	}
	ok &= (sn < 0);
	puts(ok?"Valid":"Invalid");
	return 0;
}
