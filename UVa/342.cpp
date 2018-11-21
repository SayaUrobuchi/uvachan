#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char str[11];
	int n, line;
	node* next;
};

char buf2[11];
node *head, *ptr, *pre;
int compare;

void release(node* ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	if(ptr -> n < compare || compare == -1)
	{
		compare = ptr -> n;
		strcpy(buf2, ptr -> str);
	}
	free(ptr);
}

int main()
{
	int cas, n, m, i, line, count;
	char ans, str, *str2, end, comp, exit;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		ans = 0;
		head = NULL;
		count = 0;
		gets(buf2);
		for(m=0; m<n; m++)
		{
			while(scanf("%c", &str) == 1)
			{
				if(!ans || (ans == 3 && head))
				{
					if(str == '<')
					{
						scanf("%c", &str);
						end = 0;
						if(str == '/')
						{
							end = 1;
							scanf("%c", &str);
						}
						for(i=0, str2=buf2; ; i++)
						{
							if(str == '>')
							{
								if(!i && !ans)
								{
									ans = 2;
									line = m + 1;
								}
								break;
							}
							if(!ans)
							{
								if(str < 65 || str > 90)
								{
									ans = 1;
									line = m + 1;
									continue;
								}
								if(i == 10)
								{
									ans = 2;
									line = m + 1;
								}
							}
							if(i < 10)
							{
								*(str2++) = str;
							}
							scanf("%c", &str);
							if(str == 10)
							{
								break;
							}
						}
						if(str == 10)
						{
							ans = 1;
							line = m + 1;
							break;
						}
						*str2 = 0;
						if(end)
						{
							if(!ans && head == NULL)
							{
								ans = 3;
								line = m + 1;
								continue;
							}
							for(ptr = head; ptr; )
							{
								comp = strcmp(buf2, ptr -> str);
								if(comp > 0)
								{
									if(!ans)
									{
										ans = 3;
										line = m + 1;
									}
									break;
								}
								if(!comp)
								{
									if(ptr == head)
									{
										head = head -> next;
										free(ptr);
									}
									else
									{
										pre -> next = ptr -> next;
										free(ptr);
									}
									break;
								}
								pre = ptr;
								ptr = ptr -> next;
							}
							if(!ptr)
							{
								if(!ans)
								{
									ans = 3;
									line = m + 1;
								}
							}
						}
						else
						{
							if(ans)
							{
								continue;
							}
							if(head == NULL)
							{
								head = (node*)malloc(sizeof(node));
								strcpy(head -> str, buf2);
								head -> n = count++;
								head -> line = m + 1;
								head -> next = NULL;
							}
							else
							{
								for(ptr = head; ptr; )
								{
									comp = strcmp(buf2, ptr -> str);
									if(comp <= 0)
									{
										break;
									}
									pre = ptr;
									ptr = ptr -> next;
								}
								if(ptr == head)
								{
									ptr = (node*)malloc(sizeof(node));
									strcpy(ptr -> str, buf2);
									ptr -> next = head -> next;
									ptr -> n = count++;
									ptr -> line = m + 1;
									head = ptr;
								}
								else
								{
									ptr = (node*)malloc(sizeof(node));
									strcpy(ptr -> str, buf2);
									ptr -> next = pre -> next;
									ptr -> n = count++;
									ptr -> line = m + 1;
									pre -> next = ptr;
								}
							}
						}
					}
				}
				if(str == 10)
				{
					break;
				}
			}
		}
		printf("Test Case %d\n", ++cas);
		if(ans)
		{
			if(ans == 1)
			{
				printf("line %d: bad character in tag name.\n", line);
			}
			else if(ans == 2)
			{
				printf("line %d: too many/few characters in tag name.\n", line);
			}
			else
			{
				if(head)
				{
                    compare = -1;
					release(head);
					printf("line %d: expected </%s>\n", n, buf2);
				}
				else
				{
					printf("line %d: no matching begin tag.\n", line);
				}
			}
		}
		else
		{
			if(head == NULL)
			{
				printf("OK\n");
			}
			else
			{
				compare = -1;
				release(head);
				printf("line %d: expected </%s>\n", n, buf2);
			}
		}
	}
	return 0;
}
