#include <stdio.h>
#include <string.h>

int n, m;
int prize[31], list[31];

typedef struct data
{
	int cnt, next;
	struct data *arr[31];
}data;

data pool[1000001], *head;

int calc(data *ptr, int dep, int st)
{
	int i, mi, temp;
	if(dep == n)
	{
		return ptr->cnt*prize[dep-1];
	}
	for(i=0, mi=2147483647; i<n; i++)
	{
		if(ptr->arr[i] && (st & (1<<i)) == 0)
		{
			list[dep] = i;
			temp = calc(ptr->arr[i], dep+1, st+(1<<i));
			if(temp < mi)
			{
				mi = temp;
				ptr->next = i;
			}
		}
		else if((st & (1<<i)) == 0 && mi > 0)
		{
			mi = 0;
			ptr->next = -1;
			break;
		}
	}
	return mi + (dep?ptr->cnt*prize[dep-1]:0);
}

void trace(data *ptr, int dep, int st)
{
	int i;
	if(dep == n)
	{
		return;
	}
	if(ptr == NULL || ptr->next == -1)
	{
		for(i=0; i<n; i++)
		{
			if((st & (1<<i)) == 0 && (ptr==NULL||ptr->arr[i] == NULL))
			{
				list[dep] = i;
				trace(NULL, dep+1, st+(1<<i));
				break;
			}
		}
	}
	else
	{
		list[dep] = ptr->next;
		trace(ptr->arr[ptr->next], dep+1, st+(1<<ptr->next));
	}
}

int main()
{
	int count, i, j, pp, len, temp;
	data *ptr;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%d", &prize[i]);
		}
		pp = 0;
		head = &pool[pp++];
		head->cnt = 0;
		memset(head->arr, 0, sizeof(head->arr));
		for(i=0; i<m; i++)
		{
			scanf("%d", &len);
			ptr = head;
			for(j=0; j<len; j++)
			{
				scanf("%d", &temp);
				temp--;
				if(ptr->arr[temp])
				{
					ptr = ptr->arr[temp];
				}
				else
				{
					ptr->arr[temp] = &pool[pp++];
					ptr = ptr->arr[temp];
					ptr->cnt = 0;
					memset(ptr->arr, 0, sizeof(ptr->arr));
				}
			}
			ptr->cnt++;
		}
		calc(head, 0, 0);
		trace(head, 0, 0);
		printf("%d", list[0]+1);
		for(i=1; i<n; i++)
		{
			printf(" %d", list[i]+1);
		}
		printf("\n");
	}
	return 0;
}
