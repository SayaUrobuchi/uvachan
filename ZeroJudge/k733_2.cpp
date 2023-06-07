#include <iostream>
#include <sstream>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<long long, pp>;

const int N = 100005;
const int START_POS = 10;
const char LOOP = 'L';
const char TELEPORT = 'T';
const char END_LOOP = 'E';

ppp parse(char cmd)
{
	ppp recurs(int);
	int x;
	ppp res;
	cin >> x;
	if (cmd == LOOP)
	{
		res = recurs(x);
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
ppp recurs(int loop)
{
	ppp res;
	res.first = 0;
	bool is_first = true;
	ppp first, last;
	char cmd;
	while (cin >> cmd)
	{
		if (cmd == END_LOOP)
		{
			break;
		}
		ppp temp = parse(cmd);
		res.first += temp.first;
		if (is_first)
		{
			first = temp;
			is_first = false;
		}
		else
		{
			res.first += abs(last.second.second - temp.second.first);
		}
		last = temp;
	}
	res.first *= loop;
	res.first += abs(first.second.first - last.second.second) * (loop - 1);
	res.second = make_pair(first.second.first, last.second.second);
	return res;
}

int main()
{
	ppp res = recurs(1);
	long long ans = res.first + abs(res.second.first - START_POS);
	cout << ans << "\n";
	return 0;
}
