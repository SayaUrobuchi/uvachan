#include <stdio.h>
#include <string.h>

const int N = 100005;
const int SQN = 360;
const int TRN = 1048576;
const int LEN = 512;

int pp, ans;
int tbl[N];
int ptr[TRN][10], val[TRN];
int ary[16];
char s[LEN];

void build(int p)
{
	int i, j, dig;
	for (i=0, j=p; j>0; i++, j/=10)
	{
		ary[i] = j % 10;
	}
	for (j=0, i--; i>=0; i--)
	{
		dig = ary[i];
		if (ptr[j][dig] == 0)
		{
			ptr[j][dig] = pp++;
		}
		j = ptr[j][dig];
	}
	val[j] = p;
}

void travel(int p, int idx)
{
	int dig;
	if (val[p] > ans)
	{
		ans = val[p];
	}
	if (!s[idx])
	{
		return;
	}
	dig = s[idx] - '0';
	if (ptr[p][dig])
	{
		travel(ptr[p][dig], idx+1);
	}
}

int main()
{
	int i, j, k, len;
	pp = 0;
	build(2);
	for (i=3; i<SQN; i+=2)
	{
		if (!tbl[i])
		{
			build(i);
			for (j=i*i, k=i+i; j<N; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	for (; i<N; i+=2)
	{
		if (!tbl[i])
		{
			build(i);
		}
	}
	while (fgets(s, LEN, stdin))
	{
		len = strlen(s);
		s[--len] = 0;
		if (strcmp(s, "0") == 0)
		{
			break;
		}
		ans = 0;
		for (i=0; s[i]; i++)
		{
			travel(0, i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
