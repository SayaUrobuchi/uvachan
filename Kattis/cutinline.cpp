#include <iostream>
#include <map>
using namespace std;
using pp = pair<string, string>;

const int N = 1005;
const string DUMMY_HEAD = "__DUMMY_H";
const string DUMMY_TAIL = "__DUMMY_T";
const string CUT = "cut";

string str[N];
map<string, pp> list;

void conn(const string &f, const string &t)
{
	pp &fp = list[f];
	pp &tp = list[t];
	fp.second = t;
	tp.first = f;
}

void cut(const string &f, const string &t)
{
	pp &tp = list[t];
	conn(tp.first, f);
	conn(f, t);
}

void leave(const string &t)
{
	pp &tp = list[t];
	conn(tp.first, tp.second);
}

void print()
{
	string cur = list[DUMMY_HEAD].second;
	while (cur != DUMMY_TAIL)
	{
		puts(cur.c_str());
		cur = list[cur].second;
	}
}

int main()
{
	int n, m, i;
	string cmd, a, b;
	scanf("%d", &n);
	str[0] = DUMMY_HEAD;
	for (i=1; i<=n; i++)
	{
		cin >> str[i];
		conn(str[i-1], str[i]);
	}
	str[n+1] = DUMMY_TAIL;
	conn(str[n], str[n+1]);
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		cin >> cmd;
		if (cmd == CUT)
		{
			cin >> a >> b;
			cut(a, b);
		}
		else
		{
			cin >> a;
			leave(a);
		}
	}
	print();
	return 0;
}
