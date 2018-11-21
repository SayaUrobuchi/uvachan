#include <stdio.h>
#include <string.h>

int dp[301][151][155];
int len[301][151];
int buf[155], lenb;

void multi(int* p, int* q, int lenp, int lenq)
{
	int i, j;
	memset(buf, 0, sizeof(buf));
	for(i=0; i<lenp; i++)
	{
		for(j=0; j<lenq; j++)
		{
			buf[i+j] += p[i] * q[j];
			if(buf[i+j] >= 10000)
			{
				buf[i+j+1] += buf[i+j] / 10000;
				buf[i+j] %= 10000;
			}
		}
	}
	for(i=0; i<lenp+lenq; i++)
	{
		if(buf[i] >= 10000)
		{
			buf[i+1] += buf[i] / 10000;
			buf[i] %= 10000;
		}
	}
	for(; buf[i]; i++)
	{
		if(buf[i] >= 10000)
		{
			buf[i+1] += buf[i] / 10000;
			buf[i] %= 10000;
		}
	}
	lenb = i;
}

int add(int *p, int lenp)
{
	int i;
	for(i=0; i<lenb; i++)
	{
		p[i] += buf[i];
		if(p[i] >= 10000)
		{
			p[i+1] += p[i] / 10000;
			p[i] %= 10000;
		}
	}
	for(; i<lenp; i++)
	{
		if(p[i] >= 10000)
		{
			p[i+1] += p[i] / 10000;
			p[i] %= 10000;
		}
	}
	for(; p[i]; i++)
	{
		if(p[i] >= 10000)
		{
			p[i+1] += p[i] / 10000;
			p[i] %= 10000;
		}
	}
	return i;
}

void sub(int *p, int *q, int lenp, int lenq)
{
	int i;
	memset(buf, 0, sizeof(buf));
	for(i=0; i<lenp; i++)
	{
		buf[i] += p[i] - q[i];
		if(buf[i] < 0)
		{
			for(; buf[i]<0; )
			{
				buf[i] += 10000;
				buf[i+1]--;
			}
		}
	}
	for(; !buf[i]&&i>-1; i--);
	lenb = i + 1;
}

void calc(int n, int d)
{
	int i;
	if(len[n][d])
	{
		return;
	}
	if(!n)
	{
		dp[n][d][0] = 1;
		len[n][d] = 1;
		return;
	}
	if(!d)
	{
		dp[n][d][0] = 0;
		len[n][d] = 1;
		return;
	}
	for(i=2; i<=n; i+=2)
	{
		calc(i-2, d-1);
		calc(n-i, d);
		multi(dp[i-2][d-1], dp[n-i][d], len[i-2][d-1], len[n-i][d]);
		len[n][d] = add(dp[n][d], len[n][d]);
	}
}

int main()
{
	int n, m, i, j, k;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!m)
		{
			printf("%d\n", !n);
		}
		else
		{
			calc(n, m);
			calc(n, m-1);
			sub(dp[n][m], dp[n][m-1], len[n][m], len[n][m-1]);
			printf("%d", buf[lenb-1]);
			for(i=lenb-2; i>-1; i--)
			{
				printf("%04d", buf[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
