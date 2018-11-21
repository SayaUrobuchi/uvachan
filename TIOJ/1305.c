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
			ptr->remain++;
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
		ptr->remain += 1-ptr->exist;
		return ptr->exist ? 0 : (ptr->exist=1);
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
		if(ptr->exist && target == ptr->remain)
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
		search(ptr->right, target-(ptr->remain));
	}
}

int removes(node *ptr, int target)
{
	int temp;
	if(target < ptr->number)
	{
		temp = 0;
		if(ptr->left != NULL)
		{
			ptr->remain -= (temp=removes(ptr->left, target));
		}
		return temp;
	}
	else if(target == ptr->number)
	{
		ptr->remain -= (temp=ptr->exist);
		ptr->exist = 0;
		return temp;
	}
	else
	{
		if(ptr->right != NULL)
		{
			return removes(ptr->right, target);
		}
		return 0;
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
			if(target < 1 || head == NULL || total < target)
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
				total -= removes(head, target);
			}
		}
	}
	return 0;
}
