#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deg[500], map[500][500], mnum[500], q[500];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, m, nn, i, j, k, temp, qs, qd, ans, now, t, mx, c, d, ac, ad, l;
	while(scanf("%d%d", &m, &n) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		nn = n*m;
		memset(deg, 0, sizeof(deg));
		for(i=0; i<nn-1; i++)
		{
			scanf("%d", &k);
			if(k == -1)
			{
				for(j=i+1, k=0; j<=i+n&&j<nn; j++, k++)
				{
					map[i][k] = j;
					deg[j]++;
				}
				mnum[i] = k;
			}
			else
			{
				mnum[i] = k;
				for(; k>0; k--)
				{
					scanf("%d", &temp);
					temp--;
					map[i][k-1] = temp;
					deg[temp]++;
				}
			}
			for(j=i+n+1; j<nn; j++)
			{
				map[i][mnum[i]++] = j;
				deg[j]++;
			}
		}
		i = nn-1;
		mnum[i] = 0;
		for(i=0, qs=qd=0; i<nn; i++)
		{
			if(deg[i] == 0)
			{
				q[qd++] = i;
			}
		}
		for(i=0, ans=0; i<nn; ans++)
		{
			if(qd-qs > 3)
			{
				for(j=qs; j<=qs+1; j++)
				{
					now = q[j];
					for(k=0; k<mnum[now]; k++)
					{
						t = map[now][k];
						deg[t]--;
						if(deg[t] == 0)
						{
							q[qd++] = t;
						}
					}
				}
				qs += 2;
				i += 2;
			}
			else if(qd-qs == 1)
			{
				now = q[qs];
				for(k=0; k<mnum[now]; k++)
				{
					t = map[now][k];
					deg[t]--;
					if(deg[t] == 0)
					{
						q[qd++] = t;
					}
				}
				qs++;
				i++;
			}
			else
			{
				qsort(q+qs, qd-qs, sizeof(int), comp);
				for(j=qs, mx=-1; j<qd; j++)
				{
					c = 0;
					now = q[j];
					for(k=0; k<mnum[now]; k++)
					{
						t = map[now][k];
						deg[t]--;
						if(deg[t] == 0)
						{
							c++;
						}
					}
					for(l=j+1; l<qd; l++)
					{
						now = q[l];
						d = 0;
						for(k=0; k<mnum[now]; k++)
						{
							t = map[now][k];
							deg[t]--;
							if(deg[t] == 0)
							{
								d++;
							}
						}
						if(c+d > mx)
						{
							mx = c+d;
							ac = j;
							ad = l;
						}
						for(k=0; k<mnum[now]; k++)
						{
							t = map[now][k];
							deg[t]++;
						}
					}
					now = q[j];
					for(k=0; k<mnum[now]; k++)
					{
						t = map[now][k];
						deg[t]++;
					}
				}
				ac = q[ac];
				ad = q[ad];
				for(j=qs; j<qd; j++)
				{
					if(q[j] != ac && q[j] != ad)
					{
						q[qd-1] = q[j];
						break;
					}
				}
				qs += 2;
				i += 2;
				now = ac;
				for(k=0; k<mnum[now]; k++)
				{
					t = map[now][k];
					deg[t]--;
					if(deg[t] == 0)
					{
						q[qd++] = t;
					}
				}
				now = ad;
				for(k=0; k<mnum[now]; k++)
				{
					t = map[now][k];
					deg[t]--;
					if(deg[t] == 0)
					{
						q[qd++] = t;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
