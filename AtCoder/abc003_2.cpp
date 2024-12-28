#include <iostream>
using namespace std;

const int N = 16;
const string KEY = "atcoder";

char s0[N], s1[N];
bool atcoder[128];

int main()
{
	int i;
	for (i=0; i<KEY.size(); i++)
	{
		atcoder[KEY[i]] = true;
	}
	scanf("%s%s", s0, s1);
	bool ok = true;
	for (i=0; s0[i]&&ok; i++)
	{
		if (s0[i] != s1[i])
		{
			if (!(s0[i] == '@' && atcoder[s1[i]]
				|| s1[i] == '@' && atcoder[s0[i]]))
			{
				ok = false;
			}
		}
	}
	puts(ok?"You can win":"You will lose");
	return 0;
}
