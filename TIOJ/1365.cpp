#include <stdio.h>
#include <stdlib.h>

int loc[1000005], sp[1000005], id[1000005];
long long ans;

typedef struct tree
{
	int n, c, cc;
	struct tree *left, *right;
}tree;

tree node[1000005], *p, *head;

int comp(const void *p, const void *q)
{
	if(loc[*(int*)p] == loc[*(int*)q])
	{
		return sp[*(int*)q] - sp[*(int*)p];
	}
	return loc[*(int*)q] - loc[*(int*)p];
}

void calc(tree *ptr, int target)
{
	if(target == ptr->n)
	{
		ptr->cc++;
		ans += ptr->c;
		return;
	}
	else if(target < ptr->n)
	{
		ptr->c++;
		if(ptr->left)
		{
			calc(ptr->left, target);
		}
		else
		{
			ptr->left = p++;
			ptr = ptr->left;
			ptr->n = target;
			ptr->c = 0;
			ptr->cc = 1;
			ptr->left = ptr->right = NULL;
		}
	}
	else
	{
		ans += ptr->c + ptr->cc;
		if(ptr->right)
		{
			calc(ptr->right, target);
		}
		else
		{
			ptr->right = p++;
			ptr = ptr->right;
			ptr->n = target;
			ptr->c = 0;
			ptr->cc = 1;
			ptr->left = ptr->right = NULL;
		}
	}
}

int main()
{
	int n, i, q;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &loc[i], &sp[i]);
			id[i] = i;
		}
		qsort(id, n, sizeof(int), comp);
		p = node;
		head = p++;
		head->n = sp[id[0]];
		head->c = 0;
		head->cc = 1;
		head->left = head->right = NULL;
		for(i=1, ans=0; i<n; i++)
		{
			q = id[i];
			calc(head, sp[q]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
