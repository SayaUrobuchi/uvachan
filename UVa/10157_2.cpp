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
		buf[i] = p[i] - q[i];
		if(buf[i] < 0)
		{
			buf[i] += 10000;
			buf[i+1]--;
		}
	}
	for(; !buf[i]&&i>-1; i--);
	lenb = i + 1;
}

int main()
{
	int n, m, i, j, k;
	for(i=0; i<301; i++)
	{
		for(j=0; j<151; j++)
		{
			len[i][j] = 1;
		}
	}
	for(i=0; i<151; i++)
	{
		dp[0][i][0] = 1;
	}
	for(n=2; n<301; n+=2)
	{
		for(i=1; i<151; i++)
		{
			for(j=2; j<=n; j+=2)
			{
				multi(dp[j-2][i-1], dp[n-j][i], len[j-2][i-1], len[n-j][i]);
				len[n][i] = add(dp[n][i], len[n][i]);
			}
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!m)
		{
			printf("%d\n", !n);
		}
		else
		{
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
