#include <iostream>
using namespace std;

const int N = 512;
const int NAN = -1;

int top;
long long stk[N], tmp[N], big[N], small[N];
bool is_f[N];

void refresh()
{
	stk[top] *= tmp[top];
	tmp[top] = 0;
}

long long pop()
{
	long long res;
	if (is_f[top])
	{
		res = big[top] - small[top];
	}
	else
	{
		refresh();
		res = stk[top];
	}
	--top;
	return res;
}

void push(bool f)
{
	++top;
	is_f[top] = f;
	big[top] = -1e18;
	small[top] = 1e18;
	stk[top] = 1;
	tmp[top] = 0;
}

void pop_merge(bool is_end)
{
	long long t = pop();
	big[top] = max(big[top], t);
	small[top] = min(small[top], t);
	if (is_end)
	{
		t = pop();
		tmp[top] += t;
	}
	else
	{
		push(false);
	}
}

int main()
{
	int i;
	long long t;
	string s;
	getline(cin, s);
	s += " ";
	top = -1;
	push(false);
	for (i=0, t=NAN; i<s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (t == NAN)
			{
				t = 0;
			}
			t = t * 10 + (s[i] - '0');
		}
		else
		{
			if (t != NAN)
			{
				tmp[top] += t;
				t = NAN;
			}
			if (s[i] == '*')
			{
				refresh();
			}
			else if (s[i] == ',' || s[i] == ')')
			{
				pop_merge(s[i] == ')');
			}
			else if (s[i] == '(')
			{
				push(true);
				push(false);
			}
		}
	}
	printf("%lld\n", pop());
	return 0;
}
