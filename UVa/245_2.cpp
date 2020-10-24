#include <iostream>
using namespace std;

struct node
{
	string str;
	int nxt;
};

int pp;
node pool[1048576];

int gen(string &s, int nxt)
{
	pool[pp].str = s;
	pool[pp].nxt = nxt;
	return pp++;
}

int main()
{
	int i, j, num, t, u;
	string s, word;
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	pp = 0;
	word = "";
	gen(word, -1);
	num = 0;
	while (getline(cin, s))
	{
		if (s == "0")
		{
			break;
		}
		s += "\n";
		for (i=0; i<s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			{
				word += s[i];
			}
			else
			{
				if (num)
				{
					--num;
					for (j=0, t=0; j<num; j++, t=pool[t].nxt);
					u = pool[t].nxt;
					pool[t].nxt = pool[u].nxt;
					pool[u].nxt = pool[0].nxt;
					pool[0].nxt = u;
					cout << pool[u].str;
					num = 0;
				}
				else if (word.size())
				{
					pool[0].nxt = gen(word, pool[0].nxt);
					cout << word;
					word.clear();
				}
				cout << s[i];
			}
		}
	}
	return 0;
}
