#include <stdio.h>

#define N 1000003

int c[2505][2505];

typedef struct node
{
	int n, lc;
	struct node *left, *right;
}node;

node *head, pool[100005], *ptt;

void insert(node *ptr, int n)
{
	if(n < ptr->n)
	{
		ptr->lc++;
		if(ptr->left)
		{
			insert(ptr->left, n);
		}
		else
		{
			ptr->left = ptt++;
			ptr = ptr->left;
			ptr->n = n;
			ptr->left = ptr->right = NULL;
			ptr->lc = 0;
		}
	}
	else
	{
		if(ptr->right)
		{
			insert(ptr->right, n);
		}
		else
		{
			ptr->right = ptt++;
			ptr = ptr->right;
			ptr->n = n;
			ptr->left = ptr->right = NULL;
			ptr->lc = 0;
		}
	}
}

int calc(node *ptr, int nn)
{
	int n, m, p, q;
	if(ptr == NULL)
	{
		return 1;
	}
	n = calc(ptr->left, p=ptr->lc);
	m = calc(ptr->right, q=nn-ptr->lc-1);
	n = (int)(((long long)n*m)%N);
	n = (int)(((long long)n*c[p+q][q])%N);
	return n;
}

int main()
{
	int n, m, i, j, p, count;
	c[0][0] = 1;
	for(i=1; i<=2500; i++)
	{
		c[i][0] = 1;
		for(j=1; j<=i; j++)
		{
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%N;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		ptt = pool;
		for(i=0; i<n; i++)
		{
			scanf("%d", &p);
			if(i == 0)
			{
				head = ptt++;
				head->n = p;
				head->left = head->right = NULL;
				head->lc = 0;
			}
			else
			{
				insert(head, p);
			}
		}
		//printf("%d\n", (calc(head)*c[m][n])%1000003);
		printf("%d\n", (int)(((long long)calc(head, n)*c[m][n])%N));
	}
	return 0;
}
