#include <stdio.h>
#include <string.h>

#define BASE 1000
#define DIGIT 3

int ary[105];

typedef struct bignum
{
	int num[190], len, neg;
}bignum;

bignum t, ans;

bignum stol(int num)
{
	bignum temp;
	memset(temp.num, 0, sizeof(temp.num));
	if(num < 0)
	{
		temp.neg = 1;
		num = -num;
	}
	else if(num == 0)
	{
		temp.neg = 0;
		temp.num[0] = 0;
		temp.len = 1;
		return temp;
	}
	else
	{
		temp.neg = 0;
	}
	for(temp.len=0; num; temp.num[temp.len++]=num%BASE, num/=BASE);
	return temp;
}

int comp(bignum p, bignum q)
{
	int i;
	if(p.neg != q.neg)
	{
		return q.neg - p.neg;
	}
	if(p.neg)
	{
		if(p.len != q.len)
		{
			return q.len - p.len;
		}
		for(i=p.len-1; i>=0; i--)
		{
			if(p.num[i] != q.num[i])
			{
				return q.num[i] - p.num[i];
			}
		}
		return 0;
	}
	else
	{
		if(p.len != q.len)
		{
			return p.len - q.len;
		}
		for(i=p.len-1; i>=0; i--)
		{
			if(p.num[i] != q.num[i])
			{
				return p.num[i] - q.num[i];
			}
		}
		return 0;
	}
}

bignum multi(bignum now, int m)
{
	int neg, i;
	if(m < 0)
	{
		neg = 1;
		m = -m;
	}
	else
	{
		neg = 0;
	}
	now.neg ^= neg;
	for(i=0; i<now.len; i++)
	{
		now.num[i] *= m;
	}
	for(i=0; i<now.len||now.num[i]; i++)
	{
		if(now.num[i] >= BASE)
		{
			now.num[i+1] += now.num[i] / BASE;
			now.num[i] %= BASE;
		}
	}
	now.len = i;
	return now;
}

void output(bignum now)
{
	int i;
	if(now.neg)
	{
		printf("-");
	}
	printf("%d", now.num[now.len-1]);
	for(i=now.len-2; i>=0; i--)
	{
		printf("%0*d", DIGIT, now.num[i]);
	}
	printf("\n");
}

int main()
{
	int n, i, j;
	n = 0;
	while(scanf("%d", &ary[n]) == 1)
	{
		if(ary[n] == -999999)
		{
			ans = stol(ary[0]);
			for(i=0; i<n; i++)
			{
				t = stol(ary[i]);
				if(comp(t, ans) > 0)
				{
					ans = t;
				}
				if(ary[i])
				{
					for(j=i+1; j<n; j++)
					{
						if(ary[j] == 0)
						{
							break;
						}
						t = multi(t, ary[j]);
						if(comp(t, ans) > 0)
						{
							ans = t;
						}
					}
				}
			}
			output(ans);
			n = 0;
		}
		else
		{
			n++;
		}
	}
	return 0;
}
