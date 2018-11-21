#include <stdio.h>

int dp[1000005];

typedef struct __node
{
	int st, len;
	struct __node *next;
}node;

node *ptt, pool[10000005], *head, *tail;

int main()
{
	int count, n, m, i, j, t, at, left, right, ans;
	node *p, *q, *lp, *lq, *lhead, *ltail, *tmp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		ptt = pool;
		head = ptt++;
		head->st = 1;
		head->len = (n<<1);
		head->next = NULL;
		tail = head;
		for(i=0; i<m; i++)
		{
			scanf("%d", &t);
			//printf("!! %d\n", t);
			at = t;
			if(at < 0)
			{
				at = -at;
			}
			left = n-at;
			right = n+at;
			for(j=0, p=head; j+p->len<left; j+=p->len, p=p->next);
			if(j+p->len > left)
			{
				tmp = ptt++;
				tmp->st = p->st+p->len-(j+p->len-left);
				tmp->len = j+p->len-left;
				tmp->next = p->next;
				p->len = left-j;
				p->next = tmp;
				lp = p;
				lhead = tmp;
			}
			else
			{
				lp = p;
				lhead = p->next;
			}
			//printf("!! %d %d %d\n", t, j, j+p->len);
			for(; j+p->len<right; j+=p->len, p=p->next);
			//printf("!! %d %d\n", t, j);
			if(j+p->len > right)
			{
				tmp = ptt++;
				tmp->st = p->st+p->len-(j+p->len-right);
				tmp->len = j+p->len-right;
				tmp->next = p->next;
				p->len = p->len-(j+p->len-right);
				lq = tmp;
				ltail = p;
				if(p->next == NULL)
				{
					tail = tmp;
				}
				//printf("?? %d %d\n", tmp->st, tmp->len);
			}
			else
			{
				lq = p->next;
				ltail = p;
			}
			lp->next = lq;
			//printf("yoooo %d %d -> %d %d\n", lp->st, lp->len, lq->st, lq->len);
			if(t > 0)
			{
				ltail->next = head;
				head = lhead;
			}
			else
			{
				tail->next = lhead;
				tail = ltail;
				tail->next = NULL;
			}
			for(p=head; p; p=p->next)
			{
				//printf("oh %d %d\n", p->st, p->len);
			}
		}
		/for(i=0, p=head, ans=0; p; p=p->next, i++)
		{
			dp[i] = 0;
			for(j=0, q=head; q!=p; q=q->next, j++)
			{
				if(p->st > q->st && dp[j]>dp[i])
				{
					dp[i] = dp[j];
				}
			}
			dp[i] += p->len;
			if(dp[i] > ans)
			{
				ans = dp[i];
			}
			//printf("!! %d %d %d\n", dp[i], p->st, p->len);
		}
		printf("%d\n", 2*n-ans);
	}
	return 0;
}
