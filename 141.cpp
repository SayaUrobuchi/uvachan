#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char buf[3000], board[51][51];

struct node
{
	int move;
	char str[3000];
	struct node *left, *right;
};

char* keep()
{
	int i, j, k;
	for(i=0, k=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			buf[k++] = board[i][j];
		}
	}
	buf[k] = 0;
	return buf;
}

char* rot1()
{
	int i, j, k;
	for(i=0, k=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			buf[k++] = board[n-j-1][i];
		}
	}
	buf[k] = 0;
	return buf;
}

char* rot2()
{
	int i, j, k;
	for(i=0, k=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			buf[k++] = board[n-i-1][n-j-1];
		}
	}
	buf[k] = 0;
	return buf;
}

char* rot3()
{
	int i, j, k;
	for(i=0, k=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			buf[k++] = board[j][n-i-1];
		}
	}
	buf[k] = 0;
	return buf;
}

int chkrep(struct node *ptr, char *str, int m)
{
	int cmp;
	cmp = strcmp(ptr->str, str);
	if(!cmp)
	{
		return m != ptr -> move;
	}
	else if(cmp > 0)
	{
		if(ptr->left)
		{
			return chkrep(ptr->left, str, m);
		}
		ptr -> left = (struct node*)malloc(sizeof(struct node));
		ptr = ptr -> left;
	}
	else
	{
		if(ptr -> right)
		{
			return chkrep(ptr->right, str, m);
		}
		ptr -> right = (struct node*)malloc(sizeof(struct node));
		ptr = ptr -> right;
	}
	ptr -> move = m;
	strcpy(ptr->str, str);
	ptr -> left = ptr -> right = NULL;
	return 0;
}

int main()
{
	int n2, i, x, y, move, winner;
	char str[3000];
	struct node *head;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(board, 1, sizeof(board));
		head = (struct node*)malloc(sizeof(struct node));
		head -> move = -1;
		strcpy(head->str, keep());
		head -> left = head -> right = NULL;
		for(i=0, n2=n+n, winner=1, move=0; i<n2; i++)
		{
			scanf("%d%d%s", &x, &y, str);
			if(!move)
			{
				if(str[0] == '+')
				{
					board[x-1][y-1]++;
				}
				else
				{
					board[x-1][y-1]--;
				}
				if(chkrep(head, keep(), i) || chkrep(head, rot1(), i) || chkrep(head, rot2(), i) || chkrep(head, rot3(), i))
				{
					move = i+1;
					continue;
				}
				winner = 1 - winner;
			}
		}
		if(move)
		{
			printf("Player %d wins on move %d\n", winner+1, move);
		}
		else
		{
			printf("Draw\n");
		}
	}
	return 0;
}
