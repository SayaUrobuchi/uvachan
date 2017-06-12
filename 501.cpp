#include <stdio.h>

int ary[30001], maxheap[30001], minheap[30001], maxn, minn;

void maxheapdown(int now)
{
	int left, right, temp;
	left = now + now;
	if(left > maxn)
	{
		return;
	}
	right = left + 1;
	if(right > maxn || maxheap[left] > maxheap[right])
	{
		if(maxheap[left] > maxheap[now])
		{
			temp = maxheap[left];
			maxheap[left] = maxheap[now];
			maxheap[now] = temp;
			maxheapdown(left);
		}
	}
	else
	{
		if(maxheap[right] > maxheap[now])
		{
			temp = maxheap[right];
			maxheap[right] = maxheap[now];
			maxheap[now] = temp;
			maxheapdown(right);
		}
	}
}

void minheapdown(int now)
{
	int left, right, temp;
	left = now + now;
	if(left > minn)
	{
		return;
	}
	right = left + 1;
	if(right > minn || minheap[left] < minheap[right])
	{
		if(minheap[left] < minheap[now])
		{
			temp = minheap[left];
			minheap[left] = minheap[now];
			minheap[now] = temp;
			minheapdown(left);
		}
	}
	else
	{
		if(minheap[right] < minheap[now])
		{
			temp = minheap[right];
			minheap[right] = minheap[now];
			minheap[now] = temp;
			minheapdown(right);
		}
	}
}

void maxheapup(int now)
{
	int parent, temp;
	if(now == 1)
	{
		return;
	}
	parent = now / 2;
	if(maxheap[parent] < maxheap[now])
	{
		temp = maxheap[parent];
		maxheap[parent] = maxheap[now];
		maxheap[now] = temp;
		maxheapup(parent);
	}
}

void minheapup(int now)
{
	int parent, temp;
	if(now == 1)
	{
		return;
	}
	parent = now / 2;
	if(minheap[parent] > minheap[now])
	{
		temp = minheap[parent];
		minheap[parent] = minheap[now];
		minheap[now] = temp;
		minheapup(parent);
	}
}

void insertmax(int target)
{
	maxheap[++maxn] = target;
	maxheapup(maxn);
}

void insertmin(int target)
{
	minheap[++minn] = target;
	minheapup(minn);
}

void popmax()
{
	maxheap[0] = maxheap[1];
	maxheap[1] = maxheap[maxn--];
	maxheapdown(1);
}

void popmin()
{
	minheap[0] = minheap[1];
	minheap[1] = minheap[minn--];
	minheapdown(1);
}

int main()
{
	int count, n, m, i, j, buf;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		maxheap[1] = ary[0];
		maxn = 1;
		minn = 0;
		for(i=1, j=1; i<=m; i++)
		{
			scanf("%d", &buf);
			for(; j<buf; j++)
			{
				if(ary[j] < maxheap[1])
				{
					insertmax(ary[j]);
				}
				else
				{
					insertmin(ary[j]);
				}
			}
			if(maxn == i)
			{
				printf("%d\n", maxheap[1]);
			}
			else if(maxn > i)
			{
				for(; maxn>i; )
				{
					popmax();
					insertmin(maxheap[0]);
				}
				printf("%d\n", maxheap[1]);
			}
			else
			{
				for(; maxn<i; )
				{
					popmin();
					insertmax(minheap[0]);
				}
				printf("%d\n", maxheap[1]);
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
