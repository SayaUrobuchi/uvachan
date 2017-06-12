#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int qcnt, cnt, cptr, gcsiz, csiz[32], opt[32][20005];
int pptr;
char buf[105], cmd[20005][50];

typedef struct data
{
	int n;
	struct data *frn, *bak;
}data;

data *phash[17048577], *head, *tail;
data pool[17048577];

void addr(int tar)
{
	int i;
	data *p;
	if(phash[tar])
	{
		p = phash[tar];
		if(p->bak)
		{
			if(p->frn)
			{
				p->frn->bak = p->bak;
				p->bak->frn = p->frn;
			}
			else
			{
				head = p->bak;
				p->bak->frn = NULL;
			}
			tail->bak = p;
			p->frn = tail;
			p->bak = NULL;
			tail = p;
		}
	}
	else
	{
		if(head == NULL)
		{
			head = &pool[pptr++];
			p = head;
			p->n = tar;
			p->frn = NULL;
			p->bak = NULL;
			phash[tar] = p;
			qcnt = 1;
			cnt++;
			tail = p;
		}
		else if(qcnt < gcsiz)
		{
			p = &pool[pptr++];
			p->n = tar;
			tail->bak = p;
			p->frn = tail;
			p->bak = NULL;
			phash[tar] = p;
			qcnt++;
			cnt++;
			tail = p;
		}
		else if(qcnt == gcsiz)
		{
			phash[head->n] = NULL;
			head = head->bak;
			head->frn = NULL;
			p = &pool[pptr++];
			p->n = tar;
			p->frn = tail;
			p->bak = NULL;
			tail->bak = p;
			tail = p;
			phash[tar] = p;
			cnt++;
		}
	}
}

int main()
{
	int i, j, k, p, q, r, cnum;
	data *pp;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &csiz[i]);
		}
		cnum = 0;
		gets(cmd[0]);
		while(gets(cmd[cnum]))
		{
			if(cmd[cnum][0] == 'E')
			{
				break;
			}
			cnum++;
		}
		for(i=0; i<n; i++)
		{
			cptr = 0;
			cnt = 0;
			head = NULL;
			gcsiz = csiz[i];
			pptr = 0;
			for(j=0; j<cnum; j++)
			{
				sscanf(cmd[j], "%s%d%d%d", buf, &p, &q, &r);
				if(strcmp(buf, "END") == 0)
				{
					break;
				}
				else if(strcmp(buf, "STAT") == 0)
				{
					opt[i][cptr++] = cnt;
					cnt = 0;
				}
				else if(strcmp(buf, "ADDR") == 0)
				{
					addr(p);
				}
				else if(strcmp(buf, "RANGE") == 0)
				{
					for(k=0; k<r; k++)
					{
						addr(p+q*k);
					}
				}
			}
			pp = head;
			if(pp)
			{
				do
				{
					phash[pp->n] = NULL;
				}while(pp=pp->bak);
			}
		}
		for(i=0; i<cptr; i++)
		{
			printf("%d", opt[0][i]);
			for(j=1; j<n; j++)
			{
				printf(" %d", opt[j][i]);
			}
			printf("\n");
		}
	}
	return 0;
}
