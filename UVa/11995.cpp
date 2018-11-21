#include <stdio.h>
#include <string.h>

int heap[105], stk[1005], que[1005];

int main()
{
	int n, i, fs, fq, fh, top, head, tail, mx, p, q;
	while(scanf("%d", &n) == 1)
	{
		top = 0;
		head = 0;
		tail = 0;
		memset(heap, 0, sizeof(heap));
		mx = -1;
		fs = 1;
		fq = 1;
		fh = 1;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			if(p == 1)
			{
				stk[top++] = q;
				que[tail++] = q;
				heap[q]++;
				if(q > mx)
				{
					mx = q;
				}
			}
			else
			{
				--top;
				if(top < 0 || stk[top] != q)
				{
					fs = 0;
				}
				if(head == tail || que[head] != q)
				{
					fq = 0;
				}
				if(head < tail)
				{
					head++;
				}
				for(; mx>-1; mx--)
				{
					if(heap[mx])
					{
						break;
					}
				}
				if(mx > -1)
				{
					heap[mx]--;
					if(mx != q)
					{
						fh = 0;
					}
				}
				else
				{
					fh = 0;
				}
			}
		}
		if(fs+fq+fh > 1)
		{
			printf("not sure\n");
		}
		else if(fs+fq+fh == 0)
		{
			printf("impossible\n");
		}
		else
		{
			if(fs)
			{
				printf("stack\n");
			}
			else if(fq)
			{
				printf("queue\n");
			}
			else
			{
				printf("priority queue\n");
			}
		}
	}
	return 0;
}
