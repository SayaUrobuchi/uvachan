#include <iostream>

const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;
const int E = 4;
const int F = 5;
const int MAXN = (1<<22);

int ucnt;
int used[MAXN], qq[MAXN], qs[MAXN];
char s0[1024], s1[1024];

int encode(char *s)
{
	int i, t, res;
	for (i=0, t=1, res=0; s[i]; i++, t*=6)
	{
		res += (s[i]-'A') * t;
	}
	return res;
}

int encode2(int ary[])
{
	int i, t, res;
	for (i=1, t=1, res=0; i<=8; i++, t*=6)
	{
		res += ary[i] * t;
	}
	return res;
}

void rot(int &t)
{
	t = (t+1) % 6;
}

int press(int n, int p)
{
	int i;
	int ary[16];
	for (i=1; i<=8; i++, n/=6)
	{
		ary[i] = n%6;
	}
	if (ary[p] == A)
	{
		if (p-1 >= 1)
		{
			rot(ary[p-1]);
		}
		if (p+1 <= 8)
		{
			rot(ary[p+1]);
		}
	}
	else if (ary[p] == B)
	{
		if (p+1 <= 8 && p-1 >= 1)
		{
			ary[p+1] = ary[p-1];
		}
	}
	else if (ary[p] == C)
	{
		rot(ary[9-p]);
	}
	else if (ary[p] == D)
	{
		if (p <= 4)
		{
			for (i=1; i<p; i++)
			{
				rot(ary[i]);
			}
		}
		else
		{
			for (i=p+1; i<=8; i++)
			{
				rot(ary[i]);
			}
		}
	}
	else if (ary[p] == E)
	{
		if (p != 1 && p != 8)
		{
			if (p <= 4)
			{
				rot(ary[1]);
				rot(ary[p+(p-1)]);
			}
			else
			{
				rot(ary[8]);
				rot(ary[p-(8-p)]);
			}
		}
	}
	else if (ary[p] == F)
	{
		if (p & 1)
		{
			rot(ary[(p+9)>>1]);
		}
		else
		{
			rot(ary[p>>1]);
		}
	}
	return encode2(ary);
}

int main()
{
	int i, j, k, st, ed, cur, nxt, ans;
	while (scanf("%s%s", s0, s1) == 2)
	{
		st = encode(s0);
		ed = encode(s1);
		++ucnt;
		used[st] = ucnt;
		qq[0] = st;
		qs[0] = 0;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			if (cur == ed)
			{
				ans = qs[i];
				break;
			}
			for (k=1; k<=8; k++)
			{
				nxt = press(cur, k);
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					qq[j] = nxt;
					qs[j] = qs[i] + 1;
					j++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
