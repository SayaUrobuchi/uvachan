#include <iostream>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<long long, pp>;

const int N = 100005;
const int START_POS = 10;

char buf[N];

ppp parse(int &idx)
{
	ppp recurs(int &, int);
	int x, step;
	char cmd;
	ppp res;
	sscanf(buf+idx, "%c%d%n", &cmd, &x, &step);
	idx += step;
	if (cmd == 'L')
	{
		res = recurs(idx, x);
		++idx;
	}
	else
	{
		res = make_pair(0LL, make_pair(x, x));
	}
	return res;
}

/*                              also treats a loop as
 *                      (st               ->              ed)
 *  (st -> ed) ----> Lx (st -> ed) ----> ... ----> (st -> ed) E ----> (st -> ed)
 *                       ^             x times             |
 *                       |                                 |
 *                       |                                 |
 *                       +---------------------------------+
 *                                   (x-1) times
 */
ppp recurs(int &idx, int loop)
{
	ppp res;
	res.first = 0;
	bool is_first = true;
	ppp first, last;
	while (buf[idx] && buf[idx]!='E')
	{
		ppp temp = parse(idx);
		res.first += temp.first;
		if (is_first)
		{
			first = last = temp;
			is_first = false;
		}
		else
		{
			res.first += abs(last.second.second - temp.second.first);
			last = temp;
		}
	}
	res.first *= loop;
	res.first += abs(first.second.first - last.second.second) * (loop - 1);
	res.second = make_pair(first.second.first, last.second.second);
	return res;
}

int main()
{
	int idx = 0;
	scanf("%s", buf);
	ppp res = recurs(idx, 1);
	long long ans = res.first + abs(res.second.first - START_POS);
	printf("%lld\n", ans);
	return 0;
}
