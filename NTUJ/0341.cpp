#include <stdio.h>
#include <stdlib.h>

int px[80000], py[80000], id[80000];
long long ans;

typedef struct tree
{
	int n, c;
	struct tree *left, *right;
}tree;

tree node[80000], *head, *p;

int comp(const void *p, const void *q)
{
	if(px[*(int*)p] == px[*(int*)q])
	{
		return py[*(int*)p] - py[*(int*)q];
	}
	return px[*(int*)q] - px[*(int*)p];
}

void find(tree *ptr, int target)
{
	if(target == ptr->n)
	{
		ans += ptr->c++;
		return;
	}
	else if(target < ptr->n)
	{
		ptr->c++;
		if(ptr->left)
		{
			find(ptr->left, target);
		}
		else
		{
			ptr->left = p++;
			ptr = ptr->left;
			ptr->n = target;
			ptr->c = 1;
			ptr->left = ptr->right = NULL;
		}
	}
	else
	{
		ans += ptr->c;
		if(ptr->right)
		{
			find(ptr->right, target);
		}
		else
		{
			ptr->right = p++;
			ptr = ptr->right;
			ptr->n = target;
			ptr->c = 1;
			ptr->left = ptr->right = NULL;
		}
	}
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		p = node;
		head = p++;
		head->n = py[id[0]];
		head->c = 1;
		head->left = head->right = NULL;
		for(i=1, ans=0; i<n; i++)
		{
			find(head, py[id[i]]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
