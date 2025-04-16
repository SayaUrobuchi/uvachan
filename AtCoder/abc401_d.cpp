#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

char buf[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	scanf("%s", buf);
	string s = buf;
	for (i=0; i<s.size(); i++)
	{
		if (s[i] == '?')
		{
			if ((i > 0 && s[i-1] == 'o') || (i+1<s.size() && s[i+1] == 'o'))
			{
				s[i] = '.';
			}
		}
		else if (s[i] == 'o')
		{
			--m;
		}
	}
	vector<int> pos;
	vector<int> cnt;
	int total = 0;
	for (i=0; i<s.size(); i=j)
	{
		if (s[i] != '?')
		{
			j = i + 1;
		}
		else
		{
			for (j=i+1; j<s.size()&&s[j]=='?'; j++);
			int c = j-i;
			pos.emplace_back(i);
			cnt.emplace_back(c);
			total += ((c+1) >> 1);
		}
	}
	if (total == m)
	{
		for (i=0; i<cnt.size(); i++)
		{
			int c = cnt[i];
			if (c & 1)
			{
				for (j=0; j<c; j++)
				{
					s[pos[i]+j] = (j&1 ? '.' : 'o');
				}
			}
		}
	}
	else if (m == 0)
	{
		for (i=0; i<s.size(); i++)
		{
			if (s[i] == '?')
			{
				s[i] = '.';
			}
		}
	}
	puts(s.c_str());
	return 0;
}
