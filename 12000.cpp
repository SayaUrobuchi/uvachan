#include <stdio.h>
#include <string.h>

#define N 64

long long res[N], res2[N], mat[N][N], mat2[N][N];
long long (*mp)[N], (*mq)[N], (*mt)[N];

int main()
{
	int count, cas, i, j, k, l, n, m;
	long long *p, *q, *t;
	scanf("%d", &count);
	cas = 0;
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(mat, 0, sizeof(mat));
		for(i=0; i<N; i++)
		{
			res[i] = 0;
			// 0 step
			mat[i][i/4+m*16] = 1;
			// 1 step
			if(m >= 1)
			{
				j = i / 4;
				k = j / 4;
				if(k > 0)
				{
					mat[i][j%4+(m)*4+(k-1)*16] = 1;
				}
			}
			// 2 step
			if(m >= 2)
			{
				j = i / 16;
				k = (i % 16) / 4;
				if(j > 0 && k > 0)
				{
					mat[i][(m)+(k-1)*4+(j-1)*16] = 1;
				}
			}
			// 3 step
			if(m >= 3)
			{
				j = i / 16;
				k = (i%16) / 4;
				l = i % 4;
				if(j > 0 && k > 0 && l > 0)
				{
					mat[i][(l-1)+(k-1)*4+(j-1)*16] = 1;
				}
			}
		}
		res[0] = 1;
		p = res;
		q = res2;
		mp = mat;
		mq = mat2;
		for(i=0; i<32&&(1<<i)<=n; i++)
		{
			if(n & (1<<i))
			{
				for(j=0; j<N; j++)
				{
					q[j] = 0;
					for(k=0; k<N; k++)
					{
						q[j] += p[k]*mp[k][j];
					}
					q[j] %= 73405;
				}
				t = p;
				p = q;
				q = t;
			}
			for(j=0; j<N; j++)
			{
				for(k=0; k<N; k++)
				{
					mq[j][k] = 0;
					for(l=0; l<N; l++)
					{
						mq[j][k] += mp[j][l]*mp[l][k];
					}
					mq[j][k] %= 73405;
				}
			}
			mt = mp;
			mp = mq;
			mq = mt;
		}
		for(i=1; i<N; i++)
		{
			p[0] += p[i];
		}
		p[0] %= 73405;
		printf("Case %d: %lld\n", ++cas, p[0]);
	}
	return 0;
}