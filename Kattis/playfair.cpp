#include <iostream>
using namespace std;

int ucnt;
int tbl[128], used[128];
int board[8][8];

inline int adj(int t)
{
	return t & ~32;
}

int main()
{
	int i, j, c0, c1, p, q;
	string key, text;
	while (getline(cin, key))
	{
		++ucnt;
		for (i=0, j=0; i<key.size(); i++)
		{
			if (key[i] != ' ')
			{
				if (used[key[i]] != ucnt)
				{
					used[key[i]] = ucnt;
					tbl[key[i]] = j;
					board[j/5][j%5] = key[i];
					j++;
				}
			}
		}
		for (i='a'; i<='z'; i++)
		{
			if (i != 'q' && used[i] != ucnt)
			{
				tbl[i] = j;
				board[j/5][j%5] = i;
				j++;
			}
		}
		getline(cin, text);
		for (i=0, j=0; i<text.size(); i++)
		{
			if (text[i] != ' ')
			{
				text[j++] = text[i];
			}
		}
		text.resize(j);
		for (i=0; i<text.size(); i++)
		{
			c0 = text[i];
			if (i+1 >= text.size() || text[i] == text[i+1])
			{
				c1 = 'x';
			}
			else
			{
				c1 = text[i+1];
				++i;
			}
			p = tbl[c0];
			q = tbl[c1];
			if (p/5 == q/5)
			{
				putchar(adj(board[p/5][(p%5+1)%5]));
				putchar(adj(board[q/5][(q%5+1)%5]));
			}
			else if (p%5 == q%5)
			{
				putchar(adj(board[(p/5+1)%5][p%5]));
				putchar(adj(board[(q/5+1)%5][q%5]));
			}
			else
			{
				putchar(adj(board[p/5][q%5]));
				putchar(adj(board[q/5][p%5]));
			}
		}
		puts("");
	}
	return 0;
}