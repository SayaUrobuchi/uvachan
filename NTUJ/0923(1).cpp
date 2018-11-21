#include <stdio.h>
#include <string.h>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int px[5000], py[5000], pl[5000];
int map[2005][4005], mnum[2005];
int qq[9000000], qlow[9000000], qhigh[9000000], used[2005][4005];

int heap[9000000],hpn;

int heap_func(int k){
    return pl[qhigh[k]]-pl[qlow[k]];
}
bool cmp(int a,int b){
    return heap_func(a)>heap_func(b);
}
void push(int inp){
    heap[hpn++]=inp;
    push_heap(heap,heap+hpn,cmp);
}

int pop(){
    int tmp = heap[0];
    pop_heap(heap,heap+hpn,cmp);
    hpn--;
    return tmp;
}


int gettar(int p, int q)
{
	if(px[p] == q)
	{
		return py[p];
	}
	return px[p];
}

int main()
{
	int count, n, m, i, j, k, p, q, r, st, ed, now, ll, hh, low, high, ans, tar, road, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &n, &m, &st, &ed);
		memset(mnum, 0, sizeof(mnum));
		hpn=0;
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			map[p][mnum[p]++] = i;
			map[q][mnum[q]++] = i;
			px[i] = p;
			py[i] = q;
			pl[i] = r;
		}
		memset(used, -1, sizeof(used));
		for(i=0, j=0; i<mnum[st]; i++)
		{
			qq[j] = gettar(map[st][i], st);
			qlow[j] = qhigh[j] = map[st][i];
			used[qq[j]][qlow[j]] = qhigh[j];
			push(j);
			j++;
		}
		for(i=0, ans=-1; i<j; i++)
		{
			temp = i;
			i = pop();
			now = qq[i];
			low = qlow[i];
			high = qhigh[i];
			if(used[now][low] == high)
			{
				if(now == ed)
				{
					ans = pl[high] - pl[low];
					break;
				}
				for(k=0; k<mnum[now]; k++)
				{
					road = map[now][k];
					tar = gettar(map[now][k], now);
					ll = low;
					hh = high;
					if(pl[road] < pl[ll])
					{
						ll = road;
					}
					if(pl[road] > pl[hh])
					{
						hh = road;
					}
					if(used[tar][ll] == -1 || pl[hh] < pl[used[tar][ll]])
					{
						used[tar][ll] = hh;
						qq[j] = tar;
						qlow[j] = ll;
						qhigh[j] = hh;
						push(j);
						j++;
					}
				}
			}
			i = temp;
		}
		if(ans == -1)
		{
			printf("NO PATH\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}

