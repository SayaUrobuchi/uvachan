#include <iostream>
using namespace std;

const int N = 1205;
const int TN = 4;
const int msk[][4] = {
	{0b10000000},
	{0b11100000, 0b11000000},
	{0b11110000, 0b11000000, 0b11000000},
	{0b11111000, 0b11000000, 0b11000000, 0b11000000}
};
const int val[][4] = {
	{0b00000000},
	{0b11000000, 0b10000000},
	{0b11100000, 0b10000000, 0b10000000},
	{0b11110000, 0b10000000, 0b10000000, 0b10000000}
};

int ary[N], cnt[TN];
char buf[16];

int main()
{
	int n, i, j, k, t;
	bool is_invalid, is_ok;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0, t=0; buf[j]; t=(t<<1)|(buf[j]&1), j++);
		ary[i] = t;
	}
	for (i=0, is_invalid=false; i<n&&!is_invalid; i+=k+1)
	{
		for (k=0; k<TN; k++)
		{
			if ((ary[i] & msk[k][0]) == val[k][0])
			{
				break;
			}
		}
		if (k >= TN)
		{
			is_invalid = true;
			continue;
		}
		if (i+k >= n)
		{
			is_invalid = true;
			continue;
		}
		for (j=1, is_ok=true; j<=k; j++)
		{
			if ((ary[i+j] & msk[k][j]) != val[k][j])
			{
				is_ok = false;
				break;
			}
		}
		if (!is_ok)
		{
			is_invalid = true;
			continue;
		}
		++cnt[k];
	}
	if (is_invalid)
	{
		puts("invalid");
	}
	else
	{
		for (i=0; i<TN; i++)
		{
			printf("%d\n", cnt[i]);
		}
	}
	return 0;
}
