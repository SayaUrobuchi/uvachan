#include<stdio.h>
#include <vector>

const int N = 1048576;
const int DEC = 0;
const int INC = 1;

std::vector<int> v[N];
int dir[N], ary[N];

int main()
{
	int n, i, j, t, up, down, ans, cur, rev;
	long long dis, mx;
	scanf("%d", &n);
	for (i=1, up=0, down=0, dis=0; i<=n; i++)
	{
		scanf("%d", &t);
		if (t > i)
		{
			dir[t] = DEC;
			down++;
			v[t-i].emplace_back(t);
		}
		else
		{
			dir[t] = INC;
			up++;
			v[t-i+n].emplace_back(t);
		}
		dis += (t>i ? t-i : i-t);
		ary[i] = t;
	}
	mx = dis;
	ans = 0;
	for (i=1; i<n; i++)
	{
		dis = dis + up - down;
		rev = ary[n-i+1];
		if (dir[rev] == INC)
		{
			dis--;
		}
		else
		{
			dis++;
		}
		dis -= n-rev;
		dis += rev-1;
		if (dis < mx)
		{
			mx = dis;
			ans = i;
		}
		dir[rev] = DEC;
		down++;
		up--;
		for (j=0; j<v[i].size(); j++)
		{
			cur = v[i][j];
			if (dir[cur] == INC)
			{
				dir[cur] = DEC;
				up--;
				down++;
			}
			else
			{
				dir[cur] = INC;
				up++;
				down--;
			}
		}
	}
	printf("%lld %d\n", mx, ans);
	return 0;
}
