#include <stdio.h>
#include <unordered_map>
#include <algorithm>

const int N = 10005;

std::unordered_map<int, int> tbl;
int ant[N], res[N], dir[N];
int left[N], ln;
int right[N], rn;
int sr[N*N], sl[N*N], idx[N*N], sn;
char buf[16];

bool comp(int p, int q)
{
	return ant[p] < ant[q];
}

bool scomp(int p, int q)
{
	return ant[sl[p]]-ant[sr[p]] < ant[sl[q]]-ant[sr[q]];
}

int main()
{
	int count, cas, n, len, tim, i, j, k, p, q, t;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &len, &tim, &n);
		rn = ln = 0;
		tbl.clear();
		for (i=0; i<n; i++)
		{
			scanf("%d%s", &t, buf);
			ant[i] = t;
			dir[i] = *buf;
			if (*buf == 'R')
			{
				right[rn++] = i;
				res[i] = t + tim;
			}
			else
			{
				left[ln++] = i;
				res[i] = t - tim;
			}
			tbl[res[i]]++;
		}
		std::sort(right, right+rn, comp);
		std::sort(left, left+ln, comp);
		for (i=0, j=0, sn=0; i<rn; i++)
		{
			for (; j<ln&&ant[left[j]]<ant[right[i]]; j++);
			for (k=j; k<ln&&res[left[k]]<=res[right[i]]; k++, sn++)
			{
				sr[sn] = i;
				sl[sn] = k;
				idx[sn] = sn;
			}
		}
		std::sort(idx, idx+sn, scomp);
		for (i=0; i<sn; i++)
		{
			p = sr[idx[i]];
			q = sl[idx[i]];
			std::swap(res[right[p]], res[left[q]]);
			std::swap(dir[right[p]], dir[left[q]]);
		}
		printf("Case #%d:\n", ++cas);
		for (i=0; i<n; i++)
		{
			if (res[i] < 0 || res[i] > len)
			{
				puts("Fell off");
			}
			else
			{
				printf("%d %s\n", res[i], tbl[res[i]]>1 ? "Turning" : (dir[i] == 'R' ? "R" : "L"));
			}
		}
		puts("");
	}
	return 0;
}
