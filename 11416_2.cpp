#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int opr[128];
int used[1005][1005];
int tbl[1005][1005];
char *frm[1005][1005], buf[100005];

typedef struct stk
{
	int stop, ttop;
	int stk[1000], tmp[1000];
	int f[1000];
}stack;

int calc(int x, int y);
void push_int(stack *stk, int val, int f);

void init(stack *stk)
{
	stk->stop = stk->ttop = 0;
}

void push_opr(stack *stk, int op)
{
	for(stk->stop--; stk->stop>=0; stk->stop--)
	{
		if(opr[stk->stk[stk->stop]] >= opr[op])
		{
			push_int(stk, stk->stk[stk->stop], 1);
		}
		else
		{
			break;
		}
	}
	stk->stk[++stk->stop] = op;
	stk->stop++;
	while(stk->stop>1000);
}

void push_int(stack *stk, int val, int f)
{
	stk->f[stk->ttop] = f;
	stk->tmp[stk->ttop++] = val;
	while(stk->ttop>1000);
}

void push_lpa(stack *stk)
{
	stk->stk[stk->stop++] = '(';
	while(stk->stop>1000);
}

void push_rpa(stack *stk)
{
	for(stk->stop--; stk->stop>=0; stk->stop--)
	{
		if(stk->stk[stk->stop] == '(')
		{
			break;
		}
		push_int(stk, stk->stk[stk->stop], 1);
	}
}

void clear(stack *stk)
{
	for(stk->stop--; stk->stop>=0; stk->stop--)
	{
		push_int(stk, stk->stk[stk->stop], 1);
	}
}

int calc_stk(stack *stk)
{
	int i, op;
	stk->stop = 0;
	for(i=0; i<stk->ttop; i++)
	{
		if(stk->f[i])
		{
			op = stk->tmp[i];
			if(op == '+')
			{
				stk->stk[stk->stop-2] += stk->stk[stk->stop-1];
				stk->stop--;
			}
			else if(op == '-')
			{
				stk->stk[stk->stop-2] -= stk->stk[stk->stop-1];
				stk->stop--;
			}
			else if(op == '*')
			{
				stk->stk[stk->stop-2] *= stk->stk[stk->stop-1];
				stk->stop--;
			}
			else if(op == '/')
			{
				stk->stk[stk->stop-2] /= stk->stk[stk->stop-1];
				stk->stop--;
			}
			else if(op == '(' || op == ')')
			{
				while(1);
			}
		}
		else
		{
			stk->stk[stk->stop++] = stk->tmp[i];
		}
	}
	return stk->stk[0];
}

int is_alp(int c)
{
	return c >= 'A' && c <= 'Z';
}

int is_dig(int c)
{
	return c >= '0' && c <= '9';
}

void translate(char *s, int *x, int *y)
{
	int i, temp;
	for(i=0, *y=0; is_alp(s[i]); i++)
	{
		*y *= 26;
		*y += s[i] - 'A';
	}
	*x = atoi(s+i) - 1;
	for(i--, temp=26; i>0; i--, temp*=26)
	{
		*y += temp;
	}
}

int get_res(char *s)
{
	int i, x, y;
	stack stk;
	init(&stk);
	for(i=0; s[i]; i++)
	{
		if(opr[s[i]])
		{
			push_opr(&stk, s[i]);
		}
		else if(s[i] == '(')
		{
			push_lpa(&stk);
		}
		else if(s[i] == ')')
		{
			push_rpa(&stk);
		}
		else
		{
			translate(s+i, &x, &y);
			push_int(&stk, calc(x, y), 0);
			for(; (is_alp(s[i])||is_dig(s[i]))&&s[i]!=0; i++);
			i--;
		}
	}
	clear(&stk);
	return calc_stk(&stk);
}

int calc(int x, int y)
{
	if(used[x][y])
	{
		return tbl[x][y];
	}
	used[x][y] = 1;
	if(*frm[x][y] == 'e')
	{
		tbl[x][y] = get_res(frm[x][y]+1);
	}
	else
	{
		tbl[x][y] = atoi(frm[x][y]);
	}
	return tbl[x][y];
}

int main()
{
	int count, n, m, i, j;
	opr['+'] = opr['-'] = 1;
	opr['*'] = opr['/'] = 2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		while(n>1000||m>1000);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%s", buf);
				if(frm[i][j])
				{
					free(frm[i][j]);
				}
				frm[i][j] = (char*)malloc(strlen(buf)+1);
				strcpy(frm[i][j], buf);
			}
		}
		memset(used, 0, sizeof(used));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(used[i][j] == 0)
				{
					calc(i, j);
				}
				if(j)
				{
					printf(" ");
				}
				printf("%d", tbl[i][j]);
			}
			printf("\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
