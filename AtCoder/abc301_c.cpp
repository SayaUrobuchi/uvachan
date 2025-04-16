#include <iostream>
using namespace std;

const int N = 200005;
const char SPC = '@';
const string KEY = "atcoder";

int acnt[128], bcnt[128];
char buf[2][N];
bool atc[128];

bool is_atcoder(char c)
{
	return atc[c];
}

int main()
{
	int i;
	for (i=0; i<KEY.size(); i++)
	{
		atc[KEY[i]] = true;
	}
	scanf("%s%s", buf[0], buf[1]);
	for (i=0; buf[0][i]; i++)
	{
		++acnt[buf[0][i]];
		++bcnt[buf[1][i]];
	}
	bool gg = false;
	for (i='a'; i<='z'&&!gg; i++)
	{
		if (acnt[i] != bcnt[i])
		{
			if (!is_atcoder(i))
			{
				gg = true;
			}
			else
			{
				int *less = acnt;
				int *more = bcnt;
				if (less[i] > more[i])
				{
					swap(less, more);
				}
				int d = more[i] - less[i];
				if (less[SPC] >= d)
				{
					less[SPC] -= d;
				}
				else
				{
					gg = true;
				}
			}
		}
	}
	puts(gg ? "No" : "Yes");
	return 0;
}
