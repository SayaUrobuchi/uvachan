#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	string ans;
	vector<int> stk;
	for (i=0; i<n; i++)
	{
		if (s[i] == ')' && stk.size())
		{
			ans.resize(stk.back());
			stk.pop_back();
		}
		else
		{
			if (s[i] == '(')
			{
				stk.push_back(ans.size());
			}
			ans += s[i];
		}
	}
	puts(ans.c_str());
	return 0;
}
