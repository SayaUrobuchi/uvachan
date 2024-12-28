/*
	ID: sa072682
	LANG: C
	TASK: butter
*/
#include <stdio.h>

int ary[501], map[801][801], cost[801][801], num[801], dis[801], chk[801], heap[10000], l;

void heapup(int now)
{
	int temp, t;
	if(!(temp = now / 2))
	{
		return;
	}
	if(dis[heap[now]] < dis[heap[temp]])
	{
		t = heap[now];
		heap[now] = heap[temp];
		heap[temp] = t;
		heapup(temp);
	}
}

void heapdown(int now)
{
	int left, right, temp;
	left = now * 2;
	right = left + 1;
	if(left >= l)
	{
		return;
	}
	if(right >= l || dis[heap[left]] < dis[heap[right]])
	{
		if(dis[heap[left]] < dis[heap[now]])
		{
			temp = heap[left];
			heap[left] = heap[now];
			heap[now] = temp;
			heapdown(left);
		}
	}
	else
	{
		if(dis[heap[right]] < dis[heap[now]])
		{
			temp = heap[right];
			heap[right] = heap[now];
			heap[now] = temp;
			heapdown(right);
		}
	}
}

int pop()
{
	if(l == 1)
	{
		return 0;
	}
	heap[0] = heap[1];
	heap[1] = heap[--l];
	heapdown(1);
	return 1;
}

void push(int now)
{
	heap[l++] = now;
	heapup(l-1);
}

int main()
{
	int n, m, o, i, j, k, now, ans;
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &o);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	while(o--)
	{
		scanf("%d%d%d", &i, &j, &k);
		map[i][num[i]] = j;
		cost[i][num[i]++] = k;
		map[j][num[j]] = i;
		cost[j][num[j]++] = k;
	}
	for(i=1, ans=2147483647; i<=m; i++)
	{
		for(j=1; j<=m; j++)
		{
			dis[j] = 0;
			chk[j] = 0;
		}
		for(j=0, l=1; j<num[i]; j++)
		{
			dis[map[i][j]] = cost[i][j];
			push(map[i][j]);
		}
		chk[i] = 1;
		while(pop())
		{
			if(chk[heap[0]])
			{
				break;
			}
			now = heap[0];
			chk[now] = 0;
			for(j=0; j<num[now]; j++)
			{
				if(!chk[map[now][j]] && (!dis[map[now][j]] || cost[now][j] + dis[now] < dis[map[now][j]]))
				{
					dis[map[now][j]] = dis[now] + cost[now][j];
					push(map[now][j]);
				}
			}
		}
		for(j=0, k=0; j<n; j++)
		{
			k += dis[ary[j]];
		}
		if(k < ans)
		{
			ans = k;
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
