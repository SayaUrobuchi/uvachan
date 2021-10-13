#include <iostream>
using namespace std;

const int N = 3;
const int M = 12;
const int LIGHT = -1;
const int NORMAL = 0;
const int HEAVY = 1;
const int UP = -1;
const int EVEN = 0;
const int DOWN = 1;

int coin[M], res[N];
char ll[N][16], rr[N][16], buf[16];

const char *getnam(int t)
{
	if (t == HEAVY)
	{
		return "heavy";
	}
	return "light";
}

int sum(const char *s)
{
	int res;
	for (res=0; *s; res+=coin[*s-'A'], ++s);
	return res;
}

bool check(int id, int t)
{
	int i, a, b;
	bool ans;
	coin[id] = t;
	for (i=0, ans=true; i<N; i++)
	{
		a = sum(ll[i]);
		b = sum(rr[i]);
		if (a == b && res[i] != EVEN
			|| a > b && res[i] != UP
			|| a < b && res[i] != DOWN)
		{
			ans = false;
			break;
		}
	}
	coin[id] = NORMAL;
	return ans;
}

int main()
{
	int count, i, ans, typ;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0; i<N; i++)
		{
			scanf("%s%s%s", ll[i], rr[i], buf);
			if (*buf == 'e')
			{
				res[i] = EVEN;
			}
			else if (*buf == 'u')
			{
				res[i] = UP;
			}
			else
			{
				res[i] = DOWN;
			}
		}
		for (i=0; i<M; i++)
		{
			if (check(i, LIGHT))
			{
				ans = i;
				typ = LIGHT;
				break;
			}
			if (check(i, HEAVY))
			{
				ans = i;
				typ = HEAVY;
				break;
			}
		}
		printf("%c is the counterfeit coin and it is %s.\n", ans+'A', getnam(typ));
	}
	return 0;
}
