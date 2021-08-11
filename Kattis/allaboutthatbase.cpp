#include <iostream>
using namespace std;

const long long LIM = (1LL<<32);

long long n[4];
char s[4][128], op[128];
int tbl[128];
char rev[128];

long long ext(const char *s, int b)
{
	int i;
	long long res;
	if (b == 1)
	{
		for (res=0; s[res]; ++res);
	}
	else
	{
		for (i=0, res=0; s[i]&&res<LIM; i++)
		{
			res = (res*b) + tbl[s[i]];
		}
	}
	return res;
}

int main()
{
	int count, i, j, best, c;
	bool res, ans, one;
	for (i=0, j='0'; j<='9'; i++, j++)
	{
		rev[i] = j;
		tbl[j] = i;
	}
	for (i=10, j='a'; j<='z'; i++, j++)
	{
		rev[i] = j;
		tbl[j] = i;
	}
	rev[36] = '0';
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%s%s%*s%s", s[0], op, s[1], s[2]);
		for (i=0, best=1, one=true; i<3; i++)
		{
			for (j=0; s[i][j]; j++)
			{
				c = tbl[s[i][j]];
				best = max(best, c);
				if (s[i][j] != '1')
				{
					one = false;
				}
			}
		}
		++best;
		if (one)
		{
			best = 1;
		}
		for (i=best, ans=false; i<=36; i++)
		{
			for (j=0; j<3; j++)
			{
				n[j] = ext(s[j], i);
				if (n[j] >= LIM)
				{
					break;
				}
			}
			res = false;
			if (j >= 3)
			{
				res = ((*op == '+' && n[0]+n[1] == n[2])
					|| (*op == '-' && n[0]-n[1] == n[2])
					|| (*op == '*' && n[0]*n[1] == n[2])
					|| (*op == '/' && n[1] != 0 && n[0] == n[2]*n[1]));
			}
			if (res)
			{
				putchar(rev[i]);
				ans = true;
			}
		}
		if (!ans)
		{
			puts("invalid");
		}
		else
		{
			puts("");
		}
	}
	return 0;
}
