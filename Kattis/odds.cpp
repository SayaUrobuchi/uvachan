#include <iostream>
using namespace std;

int a, b;
int dice[16], st[16], ed[16];
char ch[16];

int gcd(int a, int b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int calc(int a, int b)
{
	int c;
	if (a == b)
	{
		return a << 10;
	}
	if (a < b)
	{
		swap(a, b);
	}
	c = a*10 + b;
	if (c == 21)
	{
		return c << 20;
	}
	return c;
}

void dfs(int depth)
{
	int i;
	if (depth == 4)
	{
		if (calc(dice[0], dice[1]) > calc(dice[2], dice[3]))
		{
			++a;
		}
		++b;
		return;
	}
	for (i=st[depth]; i<=ed[depth]; i++)
	{
		dice[depth] = i;
		dfs(depth+1);
	}
}

int main()
{
	int i;
	while (cin >> ch[0] >> ch[1] >> ch[2] >> ch[3])
	{
		if (ch[0] == '0' && ch[1] == '0' && ch[2] == '0' && ch[3] == '0')
		{
			break;
		}
		for (i=0; i<4; i++)
		{
			if (ch[i] == '*')
			{
				st[i] = 1;
				ed[i] = 6;
			}
			else
			{
				st[i] = ed[i] = ch[i]-'0';
			}
		}
		a = b = 0;
		dfs(0);
		if (a == b)
		{
			puts("1");
		}
		else if (a == 0)
		{
			puts("0");
		}
		else
		{
			i = gcd(a, b);
			printf("%d/%d\n", a/i, b/i);
		}
	}
	return 0;
}
