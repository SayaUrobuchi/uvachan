#include <stdio.h>
#include <string.h>

int total, c;
char command[100], action[100];

typedef struct node
{
	int number, remain, exist;
	struct node *left, *right;
}node;

node nodes[200000], *head;

int insert(node *ptr, int target)
{
	int temp;
	if(target < ptr->number)
	{
		if(ptr->left == NULL)
		{
			ptr->left = nodes + c++;
			ptr = ptr->left;
			ptr->number = target;
			ptr->left = ptr->right = NULL;
			ptr->remain = 1;
			ptr->exist = 1;
			return 1;
		}
		else
		{
			ptr->remain += (temp=insert(ptr->left, target));
			return temp;
		}
	}
	else if(target == ptr->number)
	{
		return ptr->exist ? 0 : ptr->exist=1;
	}
	else
	{
		if(ptr->right == NULL)
		{
			ptr->right = nodes + c++;
			ptr = ptr->right;
			ptr->number = target;
			ptr->left = ptr->right = NULL;
			ptr->remain = 1;
			ptr->exist = 1;
			return 1;
		}
		else
		{
			return insert(ptr->right, target);
		}
	}
}

void search(node *ptr, int target)
{
	if(target <= ptr->remain)
	{
		if(ptr->exist)
		{
			printf("%d\n", ptr->number);
		}
		else
		{
			search(ptr->left, target);
		}
	}
	else
	{
		search(ptr->right, target-ptr->remain);
	}
}

void removes(node *ptr, int target)
{
	if(target < ptr->number)
	{
		if(ptr->left != NULL)
		{
			removes(ptr->left, target);
		}
	}
	else if(target == ptr->number)
	{
		total -= (ptr->exist);
		ptr->remain -= ptr->exist;
		ptr->exist = 0;
	}
	else
	{
		if(ptr->right != NULL)
		{
			removes(ptr->right, target);
		}
	}
}

int main()
{
	int target;
	total = c = 0;
	while(gets(command))
	{
		sscanf(command, "%s%d", action, &target);
		if(strcmp(action, "exit") == 0)
		{
			break;
		}
		else if(strcmp(action, "insert") == 0)
		{
			if(head == NULL)
			{
				head = nodes + c++;
				head->number = target;
				head->left = head->right = NULL;
				head->remain = 1;
				head->exist = 1;
				total++;
			}
			else
			{
				total += insert(head, target);
			}
		}
		else if(strcmp(action, "ask") == 0)
		{
			if(head == NULL || total < target)
			{
				puts("error");
			}
			else
			{
				search(head, target);
			}
		}
		else if(strcmp(action, "remove") == 0)
		{
			if(head != NULL)
			{
				removes(head, target);
			}
		}
	}
	return 0;
}
