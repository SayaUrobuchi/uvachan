#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tree
{
	char str[22];
	int n;
	tree *left, *right;
};

tree *head;
char queue[10000][22], step[10000], method[10000], method2[10000], target[22], buf[22];
int last[10000], last2[10000];

char addnode(tree* ptr, char* str, int n)
{
	int comp;
	comp = strcmp(ptr -> str, str);
	if(!comp)
	{
		return 0;
	}
	else if(comp > 0)
	{
		if(ptr -> left == NULL)
		{
			ptr -> left = (tree*)malloc(sizeof(tree));
			ptr = ptr -> left;
			strcpy(ptr -> str, str);
			ptr -> n = n;
			ptr -> left = NULL;
			ptr -> right = NULL;
			return 1;
		}
		return addnode(ptr -> left, str, n);
	}
	else
	{
		if(ptr -> right == NULL)
		{
			ptr -> right = (tree*)malloc(sizeof(tree));
			ptr = ptr -> right;
			strcpy(ptr -> str, str);
			ptr -> n = n;
			ptr -> left = NULL;
			ptr -> right = NULL;
			return 1;
		}
		return addnode(ptr -> right, str, n);
	}
}

int findnode(tree* ptr, char* str)
{
	int comp;
	if(ptr == NULL)
	{
		return 0;
	}
	comp = strcmp(ptr -> str, str);
	if(!comp)
	{
		return ptr -> n;
	}
	else if(comp > 0)
	{
		return findnode(ptr -> left, str);
	}
	else
	{
		return findnode(ptr -> right, str);
	}
}

void recursion(int n)
{
	if(last[n] == -1)
	{
		return;
	}
	recursion(last[n]);
	printf("%d", method[n]);
}

int main()
{
	int count, i, j, k, num[24], tmp, tmp2, ans;
	strcpy(target, "034305650121078709:90");
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<21; i++)
		{
			scanf("%d", &num[i]);
			queue[0][i] = num[i]+48;
		}
		queue[0][i] = 0;
		for(i; i<24; i++)
		{
			scanf("%d", &num[i]);
		}
		if(!strcmp(target, queue[0]))
		{
			printf("PUZZLE ALREADY SOLVED\n");
			continue;
		}
		step[0] = 0;
		method[0] = 0;
		last[0] = -1;
		head = (tree*)malloc(sizeof(tree));
		head -> n = 0;
		strcpy(head -> str, queue[0]);
		head -> left = NULL;
		head -> right = NULL;
		for(i=0, j=1; i<j; i++)
		{
			if(step[i] == 8)
			{
				break;
			}
			if(method[i] != 3)
			{
				strcpy(buf, queue[i]);
				tmp = buf[10];
				tmp2 = buf[11];
				for(k=9; k>-1; k--)
				{
					buf[k+2] = buf[k];
				}
				buf[0] = tmp;
				buf[1] = tmp2;
				if(!strcmp(buf, target))
				{
					ans = 1;
					break;
				}
				if(addnode(head, buf, j))
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last[j] = i;
					method[j++] = 1;
				}
			}
			if(method[i] != 2)
			{
				strcpy(buf, queue[i]);
				tmp = buf[19];
				tmp2 = buf[20];
				for(k=18; k>8; k--)
				{
					buf[k+2] = buf[k];
				}
				buf[9] = tmp;
				buf[10] = tmp2;
				if(!strcmp(buf, target))
				{
					ans = 4;
					break;
				}
				if(addnode(head, buf, j))
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last[j] = i;
					method[j++] = 4;
				}
			}
			if(method[i] != 1)
			{
				strcpy(buf, queue[i]);
				tmp = buf[0];
				tmp2 = buf[1];
				for(k=0; k<10; k++)
				{
					buf[k] = buf[k+2];
				}
				buf[10] = tmp;
				buf[11] = tmp2;
				if(!strcmp(buf, target))
				{
					ans = 3;
					break;
				}
				if(addnode(head, buf, j))
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last[j] = i;
					method[j++] = 3;
				}
			}
			if(method[i] != 4)
			{
				strcpy(buf, queue[i]);
				tmp = buf[9];
				tmp2 = buf[10];
				for(k=9; k<19; k++)
				{
					buf[k] = buf[k+2];
				}
				buf[19] = tmp;
				buf[20] = tmp2;
				if(!strcmp(buf, target))
				{
					ans = 2;
					break;
				}
				if(addnode(head, buf, j))
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last[j] = i;
					method[j++] = 2;
				}
			}
		}
		if(step[i] < 8)
		{
			printf("%d", ans);
			recursion(i);
			printf("\n");
			continue;
		}
		strcpy(queue[0], target);
		step[0] = 0;
		method2[0] = 0;
		last2[0] = -1;
		for(i=0, j=1; i<j; i++)
		{
			if(step[i] == 8)
			{
				break;
			}
			if(method2[i] != 1)
			{
				strcpy(buf, queue[i]);
				tmp = buf[10];
				tmp2 = buf[11];
				for(k=9; k>-1; k--)
				{
					buf[k+2] = buf[k];
				}
				buf[0] = tmp;
				buf[1] = tmp2;
				tmp = findnode(head, buf);
				if(findnode(head, buf))
				{
					ans = 3;
					break;
				}
				else
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last2[j] = i;
					method2[j++] = 3;
				}
			}
			if(method2[i] != 4)
			{
				strcpy(buf, queue[i]);
				tmp = buf[19];
				tmp2 = buf[20];
				for(k=18; k>8; k--)
				{
					buf[k+2] = buf[k];
				}
				buf[9] = tmp;
				buf[10] = tmp2;
				tmp = findnode(head, buf);
				if(findnode(head, buf))
				{
					ans = 2;
					break;
				}
				else
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last2[j] = i;
					method2[j++] = 2;
				}
			}
			if(method2[i] != 3)
			{
				strcpy(buf, queue[i]);
				tmp = buf[0];
				tmp2 = buf[1];
				for(k=0; k<10; k++)
				{
					buf[k] = buf[k+2];
				}
				buf[10] = tmp;
				buf[11] = tmp2;
				tmp = findnode(head, buf);
				if(findnode(head, buf))
				{
					ans = 1;
					break;
				}
				else
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last2[j] = i;
					method2[j++] = 1;
				}
			}
			if(method2[i] != 2)
			{
				strcpy(buf, queue[i]);
				tmp = buf[9];
				tmp2 = buf[10];
				for(k=9; k<19; k++)
				{
					buf[k] = buf[k+2];
				}
				buf[19] = tmp;
				buf[20] = tmp2;
				tmp = findnode(head, buf);
				if(findnode(head, buf))
				{
					ans = 4;
					break;
				}
				else
				{
					strcpy(queue[j], buf);
					step[j] = step[i] + 1;
					last2[j] = i;
					method2[j++] = 4;
				}
			}
		}
		if(step[i] == 8)
		{
			printf("NO SOLUTION WAS FOUND IN 16 STEPS\n");
		}
		else
		{
			recursion(tmp);
			printf("%d", ans);
			while(last2[i] != -1)
			{
				printf("%d", method2[i]);
				i = last2[i];
			}
			printf("\n");
		}
	}
	return 0;
}