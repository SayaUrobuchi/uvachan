#include <stdio.h>
#include <vector>
#include <algorithm>

const int N = 5000000;

struct node
{
	int st, used, cmd, tar;
	std::vector<int> v;
};

int lim;
int dp[32];
std::vector<node> path;

bool comp(node &p, node &q)
{
	return p.tar < q.tar;
}

int lis(std::vector<int> &v)
{
	int i, j, res;
	dp[0] = v[0];
	for (i=1, res=0; i<v.size(); i++)
	{
		for (j=res; j>=0&&v[i]<=dp[j]; j--);
		dp[j+1] = v[i];
		if (j+1 > res)
		{
			res = j+1;
		}
	}
	return (v.size() - res)/2;
}

int ida(int i)
{
	int k, l, p, q;
	node *cur = &(path[i]), nxt;
	std::vector<node> opt;
	for (k=1; k<cur->v.size(); k++)
	{
		if (cur->v[k] <= cur->v[k-1])
		{
			break;
		}
	}
	q = k-1;
	if (k >= cur->v.size())
	{
		printf("%d\n", i);
		for (k=1; k<=i; k++)
		{
			printf("%d %d\n", (path[k].cmd>>4)+1, (path[k].cmd&15)+1);
		}
		return 1;
	}
	k = cur->st;
	/*if (k < q)
	{
		k = q;
	}*/
	for (; k<cur->v.size(); k++)
	{
		if (!(cur->used & (1<<k)))
		{
			/*if (k+1 < cur->v.size() && cur->v[k] == cur->v[k+1])
			{
				continue;
			}*/
			for (l=q; l<cur->v.size(); l++)
			{
				if (l != k)
				{
					if (l+1 < cur->v.size() && cur->v[l] == cur->v[l+1])
					{
						continue;
					}
					nxt.v = cur->v;
					nxt.v[l] += nxt.v[k];
					nxt.used = (cur->used | (1 << l));
					for (p=k; p+1<nxt.v.size(); p++)
					{
						nxt.v[p] = nxt.v[p+1];
					}
					nxt.v.resize(nxt.v.size()-1);
					nxt.used = ((nxt.used & ((1<<k)-1)) | ((nxt.used >> (k+1)) << k));
					nxt.st = k;
					nxt.cmd = (k<<4) + l;
					nxt.tar = lis(nxt.v);
					if (i + nxt.tar >= lim)
					{
						continue;
					}
					opt.emplace_back(nxt);
				}
			}
		}
	}
	std::sort(opt.begin(), opt.end(), comp);
	for (k=0; k<opt.size(); k++)
	{
		if (opt[k].tar - opt[0].tar > 1 || opt[k].tar > cur->tar)
		{
			break;
		}
		path[i+1] = opt[k];
		if (ida(i+1))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int count, n, i, j, k, l, p, q, nused;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		path.resize(n);
		path[0].v.resize(n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &path[0].v[i]);
		}
		path[0].st = 0;
		path[0].used = 0;
		path[0].tar = lis(path[0].v);
		for (lim=path[0].tar; lim<n; lim++)
		{
			if (ida(0))
			{
				break;
			}
		}
	}
	return 0;
}
