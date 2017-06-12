#include <stdio.h>

typedef struct node
{
	int c;
	struct node *next;
}node;

char s[10000005];
node *head, *ptr, *tail, *ptt, pool[10000005];

int main()
{
	int i;
	while(gets(s))
	{
		ptt = pool;
		ptt->next = NULL;
		head = ptt++;
		tail = head;
		ptr = head;
		for(i=0; s[i]; i++)
		{
			if(s[i] == '[')
			{
				ptr = head;
			}
			else if(s[i] == ']')
			{
				ptr = tail;
			}
			else
			{
				ptt->c = s[i];
				ptt->next = ptr->next;
				ptr->next = ptt;
				ptr = ptt;
				ptt++;
				if(ptr->next == NULL)
				{
					tail = ptr;
				}
			}
		}
		i = 0;
		for(ptr=head->next; ptr; ptr=ptr->next)
		{
			s[i++] = ptr->c;
		}
		s[i] = 0;
		printf("%s\n", s);
	}
	return 0;
}
