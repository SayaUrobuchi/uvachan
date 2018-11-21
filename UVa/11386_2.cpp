#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 2000003

int ary[5010];

struct node
{
	int n;
	struct node *next;
};

struct node *head[N], *tail[N];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, i, j, k, l, maximum, ans, index, temp;
	unsigned int sum;
	struct node *ptr;
	while(scanf("%d", &n) == 1)
	{
		memset(head, 0, sizeof(head));
		for(i=0, maximum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			temp = ary[i] % N;
			if(head[temp])
			{
				ptr = tail[temp];
				ptr->next = (struct node*)malloc(sizeof(struct node));
				ptr = ptr->next;
				ptr->n = ary[i];
				ptr->next = NULL;
				tail[temp] = ptr;
			}
			else
			{
				head[temp] = (struct node*)malloc(sizeof(struct node));
				ptr = head[temp];
				ptr->n = ary[i];
				ptr->next = NULL;
				tail[temp] = ptr;
			}
			if(ary[i] > maximum)
			{
				maximum = ary[i];
			}
		}
		qsort(ary, n, sizeof(int), comp);
		for(i=0, ans=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				sum = (unsigned int)ary[i] + ary[j];
				if(sum > maximum)
				{
					break;
				}
				temp = sum % N;
				for(ptr=head[temp]; ptr; ptr=ptr->next)
				{
					if(ptr->n == sum)
					{
						ans++;
					}
				}
			}
			if(j == i + 1)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
