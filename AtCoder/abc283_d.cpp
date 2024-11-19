#include <iostream>
#include <vector>
using namespace std;

const int N = 300005;

int tbl[128];
char buf[N];

int main()
{
	int i, j;
	scanf("%s", buf);
	bool ok = true;
	vector<vector<char> > stk(1);
	for (i=0; buf[i]&&ok; i++)
	{
		if (buf[i] == '(')
		{
			stk.emplace_back();
		}
		else if (buf[i] == ')')
		{
			for (j=0; j<stk.back().size(); j++)
			{
				--tbl[(stk.back())[j]];
			}
			stk.pop_back();
		}
		else
		{
			stk.back().emplace_back(buf[i]);
			if (tbl[buf[i]])
			{
				ok = false;
			}
			++tbl[buf[i]];
		}
	}
	puts(ok?"Yes":"No");
	return 0;
}
