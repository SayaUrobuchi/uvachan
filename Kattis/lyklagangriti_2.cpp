#include <iostream>

const int HEAD = 0;
const int TAIL = 1;

struct node
{
	char c;
	int pre, nxt;
};

char s[1048576];
int pp;
node pool[1048576];

int main()
{
	int prev, next, cur, tar;
	char *cmd;
	while (scanf("%s", s) == 1)
	{
		cmd = s;
		pp = TAIL+1;
		cur = HEAD;
		pool[HEAD].nxt = TAIL;
		pool[TAIL].pre = HEAD;
		while (*cmd)
		{
			if (*cmd == 'R')
			{
				cur = pool[cur].nxt;
			}
			else if (*cmd == 'L')
			{
				cur = pool[cur].pre;
			}
			else if (*cmd == 'B')
			{
				next = pool[cur].nxt;
				prev = pool[cur].pre;
				pool[prev].nxt = next;
				pool[next].pre = prev;
				cur = prev;
			}
			else
			{
				tar = pp++;
				next = pool[cur].nxt;
				pool[tar].c = *cmd;
				pool[tar].nxt = next;
				pool[cur].nxt = tar;
				pool[next].pre = tar;
				pool[tar].pre = cur;
				cur = tar;
			}
			++cmd;
		}
		for (cur=pool[HEAD].nxt; cur!=TAIL; cur=pool[cur].nxt)
		{
			putchar(pool[cur].c);
		}
		puts("");
	}
	return 0;
}
