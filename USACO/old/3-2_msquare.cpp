/*
	ID: sa072682
	LANG: C
	TASK: msquare
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[8], queue[50000], last[50000], c;
char str[50000][9], target[9], buf[9];

struct node
{
	char s[9];
	struct node *left, *right;
};

struct node *head;

int chk(struct node *ptr)
{
	int comp;
	if(!ptr)
	{
		return 1;
	}
	comp = strcmp(buf, ptr->s);
	if(!comp)
	{
		return 0;
	}
	else if(comp > 0)
	{
		if(ptr -> left)
		{
			return chk(ptr->left);
		}
		ptr -> left = (struct node*)malloc(sizeof(struct node));
		ptr = ptr -> left;
	}
	else
	{
		if(ptr -> right)
		{
			return chk(ptr->right);
		}
		ptr -> right = (struct node*)malloc(sizeof(struct node));
		ptr = ptr -> right;
	}
	strcpy(ptr->s, buf);
	ptr -> left = ptr -> right = NULL;
	return 1;
}

void A()
{
	char ch;
	ch = buf[0];
	buf[0] = buf[7];
	buf[7] = ch;
	ch = buf[1];
	buf[1] = buf[6];
	buf[6] = ch;
	ch = buf[2];
	buf[2] = buf[5];
	buf[5] = ch;
	ch = buf[3];
	buf[3] = buf[4];
	buf[4] = ch;
}

void B()
{
	char ch;
	ch = buf[3];
	buf[3] = buf[2];
	buf[2] = buf[1];
	buf[1] = buf[0];
	buf[0] = ch;
	ch = buf[4];
	buf[4] = buf[5];
	buf[5] = buf[6];
	buf[6] = buf[7];
	buf[7] = ch;
}

void C()
{
	char ch;
	ch = buf[1];
	buf[1] = buf[6];
	buf[6] = buf[5];
	buf[5] = buf[2];
	buf[2] = ch;
}

void backtracing(int now, int depth)
{
	if(!queue[now])
	{
		printf("%d\n", depth);
		return;
	}
	backtracing(last[now], depth+1);
	if(c == 60)
	{
		printf("\n");
		c = 0;
	}
	printf("%c", queue[now]);
	c++;
}

int main()
{
	int i, j;
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
	for(i=0; i<8; i++)
	{
		scanf("%d", &ary[i]);
		target[i] = ary[i] + 48;
	}
	target[8] = 0;
	strcpy(str[0], "12345678");
	if(!strcmp(str[0], target))
	{
		printf("0\n\n");
	}
	else
	{
		head = (struct node*)malloc(sizeof(struct node));
		strcpy(head->s, str[0]);
		head -> left = head -> right = NULL;
		queue[0] = 0;
		last[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			strcpy(buf, str[i]);
			A();
			if(chk(head))
			{
				strcpy(str[j], buf);
				queue[j] = 'A';
				last[j++] = i;
				if(!strcmp(buf, target))
				{
					break;
				}
			}
			strcpy(buf, str[i]);
			B();
			if(chk(head))
			{
				strcpy(str[j], buf);
				queue[j] = 'B';
				last[j++] = i;
				if(!strcmp(buf, target))
				{
					break;
				}
			}
			strcpy(buf, str[i]);
			C();
			if(chk(head))
			{
				strcpy(str[j], buf);
				queue[j] = 'C';
				last[j++] = i;
				if(!strcmp(buf, target))
				{
					break;
				}
			}
		}
		c = 0;
		backtracing(j-1, 0);
		printf("\n");
	}
	scanf(" ");
	return 0;
}
