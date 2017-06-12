#include <stdio.h>
#include <string.h>

int f[25], d[25], t[25], ary[25], heap[25], buf[25], tbl[25], num;

void heapdown(int n)
{
	int left, right, tmp;
	left = n * 2;
	right = n * 2 + 1;
	if(left <= num)
	{
		if(right <= num)
		{
			if(ary[heap[left]] > ary[heap[right]])
			{
				if(ary[heap[left]] > ary[heap[n]])
				{
					tmp = heap[n];
					heap[n] = heap[left];
					heap[left] = tmp;
					heapdown(left);
				}
				else if(ary[heap[left]] == ary[heap[n]])
				{
					if(heap[left] < heap[n])
					{
						tmp = heap[n];
						heap[n] = heap[left];
						heap[left] = tmp;
						heapdown(left);
					}
				}
			}
			else if(ary[heap[left]] == ary[heap[right]])
			{
				if(heap[left] < heap[right])
				{
                    if(ary[heap[left]] > ary[heap[n]])
					{
						tmp = heap[n];
						heap[n] = heap[left];
						heap[left] = tmp;
						heapdown(left);
					}
					else if(ary[heap[left]] == ary[heap[n]])
					{
						if(heap[left] < heap[n])
						{
							tmp = heap[n];
							heap[n] = heap[left];
							heap[left] = tmp;
							heapdown(left);
						}
					}
				}
				else
				{
                    if(ary[heap[right]] > ary[heap[n]])
					{
						tmp = heap[n];
						heap[n] = heap[right];
						heap[right] = tmp;
						heapdown(right);
					}
					else if(ary[heap[right]] == ary[heap[n]])
					{
						if(heap[right] < heap[n])
						{
							tmp = heap[n];
							heap[n] = heap[right];
							heap[right] = tmp;
							heapdown(right);
						}
					}
				}
			}
			else
			{
                if(ary[heap[right]] > ary[heap[n]])
				{
					tmp = heap[n];
					heap[n] = heap[right];
					heap[right] = tmp;
					heapdown(right);
				}
				else if(ary[heap[right]] == ary[heap[n]])
				{
					if(heap[right] < heap[n])
					{
						tmp = heap[n];
						heap[n] = heap[right];
						heap[right] = tmp;
						heapdown(right);
					}
				}
			}
		}
		else
		{
            if(ary[heap[left]] > ary[heap[n]])
			{
				tmp = heap[n];
				heap[n] = heap[left];
				heap[left] = tmp;
				heapdown(left);
			}
			else if(ary[heap[left]] == ary[heap[n]])
			{
				if(heap[left] < heap[n])
				{
					tmp = heap[n];
					heap[n] = heap[left];
					heap[left] = tmp;
					heapdown(left);
				}
			}
		}
	}
}

int main()
{
	int count, n, h, i, j, precost, cost, fish, ans;
	char bline;
	bline = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d", &h);
		h *= 60;
		for(i=0; i<n; i++)
		{
			scanf("%d", &f[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &d[i]);
		}
		for(i=1; i<n; i++)
		{
			scanf("%d", &t[i]);
		}
		for(i=0, precost=0, ans=-1; i<n; i++)
		{
			precost += t[i] * 5;
			cost = precost;
			memset(buf, 0, sizeof(buf));
			for(j=0; j<=i; j++)
			{
				ary[j] = f[j];
				heap[j+1] = j;
			}
			num = j;
			for(; j; j--)
			{
				heapdown(j);
			}
			fish = 0;
			while(cost < h)
			{
				fish += ary[heap[1]];
				ary[heap[1]] -= d[heap[1]];
				buf[heap[1]] += 5;
				if(ary[heap[1]] < 0)
				{
					ary[heap[1]] = 0;
				}
				cost += 5;
				heapdown(1);
			}
			if(fish > ans)
			{
				ans = fish;
				memcpy(tbl, buf, sizeof(buf));
			}
		}
		if(bline)
		{
			printf("\n");
		}
		bline = 1;
		printf("%d", tbl[0]);
		for(i=1; i<n; i++)
		{
			printf(", %d", tbl[i]);
		}
		printf("\nNumber of fish expected: %d\n", ans);
	}
	return 0;
}
