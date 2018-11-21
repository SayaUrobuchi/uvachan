#include <stdio.h>
#include <map>

const int N = 65536;
const int SQN = 256;
const int TN = 64;
const unsigned long long MAX = (((1LLU << 63) - 1) << 1) + 1;

int pn, npn;
int tbl[N];
int prime[N];
int pt_lim[N];
int np[TN];
unsigned long long pt_cache[N][TN];

std::map<unsigned long long, int> ans;

void dfs(int cur_pid, int tim, unsigned long long val)
{
	int i;
	ans[val] = 1;
	for (i=cur_pid; i<pn&&pt_lim[i]>tim&&MAX/pt_cache[i][tim]>=val; i++)
	{
		dfs(i, tim, val*pt_cache[i][tim]);
	}
}

int main()
{
	int i, j, k, p;
	unsigned long long res;
	pn = 1;
	prime[0] = 2;
	for (i=3; i<SQN; i+=2)
	{
		if (!tbl[i])
		{
			prime[pn++] = i;
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
			prime[pn++] = i;
		}
	}
	npn = 0;
	for (i=4, j=2; i<TN; i++)
	{
		if (i != prime[j])
		{
			np[npn++] = i;
		}
		else
		{
			j++;
		}
	}
	for (i=0; i<pn; i++)
	{
		p = prime[i];
		res = (unsigned long long)p * p * p * p;
		pt_cache[i][0] = res;
		for (j=4, k=1; k<npn; k++)
		{
			for (; j<np[k]&&MAX/p>=res; j++, res*=p);
			if (j < np[k])
			{
				break;
			}
			pt_cache[i][k] = res;
		}
		pt_lim[i] = k;
	}
	for (i=0; i<npn; i++)
	{
		dfs(0, i, 1LLU);
	}
	for (std::map<unsigned long long, int>::iterator it=ans.begin(); it!=ans.end(); it++)
	{
		printf("%llu\n", it->first);
	}
	//printf("%d\n", ans.size());
	return 0;
}
