#include <stdio.h>
#include <string.h>

int ans, turn;
int tbl[128];
char s[1005];

typedef struct __trie
{
	int cnt, chk;
	struct __trie *child[128];
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
	for(i=0; i<128; i++)
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
			ans += ptr->cnt;
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
	int count;
	tbl['O'] = '0';
	tbl['0'] = 'O';
	tbl['1'] = 'l';
	tbl['l'] = '1';
	tbl['Z'] = '2';
	tbl['2'] = 'Z';
	tbl['E'] = '3';
	tbl['3'] = 'E';
	tbl['R'] = '4';
	tbl['4'] = 'R';
	tbl['5'] = 'S';
	tbl['S'] = '5';
	tbl['b'] = '6';
	tbl['6'] = 'b';
	tbl['J'] = '7';
	tbl['7'] = 'J';
	tbl['B'] = '8';
	tbl['8'] = 'B';
	tbl['9'] = 'q';
	tbl['q'] = '9';
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
			insert(head, s);
		}
		turn = 1;
		while(scanf("%s", s) == 1)
		{
			if(strcmp(s, "===") == 0)
			{
				break;
			}
			turn++;
			ans = 0;
			dfs(head, s, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}
