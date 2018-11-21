#include <stdio.h>
#include <string.h>

int ans, turn;
int tbl[128], has[128];
char s[1005];

typedef struct __trie
{
	int cnt, chk;
	struct __trie *child[65];
}trie;

trie *head, *ptt, pool[2000000];

void insert(trie *ptr, char *s)
{
	if(!*s)
	{
		ptr->cnt++;
		return;
	}
	if(!(ptr->child[*s]))
	{
		ptr->child[*s] = ptt++;
		memset(ptr->child[*s], 0, sizeof(trie));
	}
	insert(ptr->child[*s], s+1);
}

void dfs(trie *ptr, char *s, int cost)
{
	int i;
	if(cost > 3)
	{
		return;
	}
	for(i=1; i<63; i++)
	{
		if(ptr->child[i])
		{
			dfs(ptr->child[i], s, cost+2);
		}
	}
	if(!*s)
	{
		if(ptr->cnt && cost && ptr->chk != turn)
		{
			ptr->chk = turn;
			ans++;
		}
		return;
	}
	if(ptr->child[*s])
	{
		dfs(ptr->child[*s], s+1, cost);
	}
	if(tbl[*s] && ptr->child[tbl[*s]])
	{
		dfs(ptr->child[tbl[*s]], s+1, cost+1);
	}
	dfs(ptr, s+1, cost+2);
}

int main()
{
	int count, i, j;
	for(i='0', j=0; i<='9'; i++)
	{
		has[i] = ++j;
	}
	for(i='a'; i<='z'; i++)
	{
		has[i] = ++j;
	}
	for(i='A'; i<='Z'; i++)
	{
		has[i] = ++j;
	}
	tbl[has['O']] = has['0'];
	tbl[has['0']] = has['O'];
	tbl[has['1']] = has['l'];
	tbl[has['l']] = has['1'];
	tbl[has['Z']] = has['2'];
	tbl[has['2']] = has['Z'];
	tbl[has['E']] = has['3'];
	tbl[has['3']] = has['E'];
	tbl[has['R']] = has['4'];
	tbl[has['4']] = has['R'];
	tbl[has['5']] = has['S'];
	tbl[has['S']] = has['5'];
	tbl[has['b']] = has['6'];
	tbl[has['6']] = has['b'];
	tbl[has['J']] = has['7'];
	tbl[has['7']] = has['J'];
	tbl[has['B']] = has['8'];
	tbl[has['8']] = has['B'];
	tbl[has['9']] = has['q'];
	tbl[has['q']] = has['9'];
	scanf("%d", &count);
	while(count--)
	{
		ptt = pool;
		head = ptt++;
		memset(head, 0, sizeof(trie));
		while(scanf("%s", s) == 1)
		{
			if(strcmp(s, "===") == 0)
			{
				break;
			}
			for(i=0; s[i]; i++)
			{
				s[i] = has[s[i]];
			}
			insert(head, s);
		}
		turn = 1;
		while(scanf("%s", s) == 1)
		{
			if(strcmp(s, "===") == 0)
			{
				break;
			}
			for(i=0; s[i]; i++)
			{
				s[i] = has[s[i]];
			}
			turn++;
			ans = 0;
			dfs(head, s, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}
