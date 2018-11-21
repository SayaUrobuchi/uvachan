#include <iostream>
using namespace std;

const int N = 131072;
const char* IF = "IF";
const char* ELSE = "ELSE";
const char* END_IF = "END_IF";
const char* END_P = "ENDPROGRAM";
const char* S = "S";

int cur, len;
string s[N];

int recurs()
{
	int res = 1;
	while (cur < len)
	{
		if (s[cur] == ELSE || s[cur] == END_IF)
		{
			break;
		}
		if (s[cur] == IF)
		{
			cur++;
			int t = recurs();
			cur++;
			t += recurs();
			res *= t;
		}
		cur++;
	}
	return res;
}

int main()
{
	int count;
	cin >> count;
	while (count--)
	{
		for (len=0; ; len++)
		{
			cin >> s[len];
			if (s[len] == END_P)
			{
				break;
			}
		}
		cur = 0;
		cout << recurs() << '\n';
	}
	return 0;
}
