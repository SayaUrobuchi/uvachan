#include <iostream>
using namespace std;
using pp = pair<int, int>;

const int N = 2500 * 2505;

pp ary[N];

void rec(int t, int tbl[])
{
	while (t)
	{
		++tbl[t%10];
		t /= 10;
	}
}

bool check(int a, int b)
{
	int i;
	int tbl[2][10] = {};
	rec(a, tbl[0]);
	rec(b, tbl[0]);
	rec(a*b, tbl[1]);
	for (i=0; i<10; i++)
	{
		if (tbl[0][i] != tbl[1][i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int a, b, i, j, ans;
	scanf("%d%d", &a, &b);
	for (i=a, ans=0; i<=b; i++)
	{
		for (j=i; j<=b; j++)
		{
			if (check(i, j))
			{
				ary[ans++] = make_pair(i, j);
			}
		}
	}
	printf("%d digit-preserving pair(s)\n", ans);
	for (i=0; i<ans; i++)
	{
		printf("x = %d, y = %d, xy = %d\n", 
				ary[i].first, ary[i].second, 
				ary[i].first*ary[i].second);
	}
	return 0;
}
