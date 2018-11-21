#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *buf;
int variable[11][4];
char str[2000];

struct node
{
	char str[256];
	struct node *success, *failed;
};

struct node *head[11];

int getaction(struct node *ptr)
{
	int i, ope, temp, num, result;
	char *s;
	if(ptr->str[0] == 'C')
	{
		return 1;
	}
	else if(ptr->str[0] == 'T')
	{
		return 2;
	}
	for(i=0, ope=0, s=ptr->str; s[i]; i++)
	{
		if((s[i] == 'M' && s[i+1] == 'Y') || (s[i] == 'Y' && s[i+1] == 'O'))
		{
			if(s[i] == 'M' && s[i+1] == 'Y')
			{
				num = 0;
			}
			else
			{
				num = 1;
			}
			for(i+=2; s[i]; i++)
			{
				if(s[i] == 49 || s[i] == 50)
				{
					break;
				}
			}
			if(s[i] == 50)
			{
				num += 2;
			}
			for(i++; s[i]; i++)
			{
				if(s[i] == '#')
				{
					temp = 0;
					break;
				}
				else if(s[i] == '=')
				{
					temp = 1;
					break;
				}
			}
			for(i++; s[i]; i++)
			{
				if(s[i] == 'C')
				{
					if(temp)
					{
						temp = (buf[num]==1);
					}
					else
					{
						temp = (buf[num]!=1);
					}
					break;
				}
				else if(s[i] == 'T')
				{
					if(temp)
					{
						temp = (buf[num]==2);
					}
					else
					{
						temp = (buf[num]!=2);
					}
					break;
				}
				else if(s[i] == 'N')
				{
					if(temp)
					{
						temp = (buf[num]==0);
					}
					else
					{
						temp = (buf[num]!=0);
					}
					break;
				}
			}
			if(!ope)
			{
				result = temp;
			}
			else if(ope == 1)
			{
				result = (result || temp);
			}
			else
			{
				result = (result && temp);
			}
		}
		else if(s[i] == 'O' && s[i+1] == 'R')
		{
			ope = 1;
		}
		else if(s[i] == 'A' && s[i+1] == 'N')
		{
			ope = 2;
		}
	}
	if(result)
	{
		return getaction(ptr->success);
	}
	return getaction(ptr->failed);
}

void build(struct node *ptr, int left, int right)
{
	int i, j, k, c;
	for(i=left; i<=right; i++)
	{
		if(str[i] == 'I')
		{
			for(j=i+2; j<right; j++)
			{
				if(str[j] == 'T' && str[j+1] == 'H')
				{
					str[j] = 0;
					strcpy(ptr->str, str+i+2);
					break;
				}
			}
			for(k=j+4, c=1; k<right; k++)
			{
				if(str[k] == 'I' && str[k+1] == 'F')
				{
					c++;
				}
				else if(str[k] == 'E' && str[k+1] == 'L')
				{
					c--;
				}
				if(!c)
				{
					ptr->success = (struct node*)malloc(sizeof(struct node));
					/*printf("IF %s\n", ptr->str);*/
					build(ptr->success, j+4, k-1);
					ptr->failed = (struct node*)malloc(sizeof(struct node));
					/*printf("ELSE %s\n", ptr->str);*/
					build(ptr->failed, k+4, right);
					break;
				}
			}
			return;
		}
		else if(str[i] == 'C')
		{
			strcpy(ptr->str, "CHEAT");
			/*printf("%s\n", ptr->str);*/
			return;
		}
		else if(str[i] == 'T')
		{
			strcpy(ptr->str, "TRADE");
			/*printf("%s\n", ptr->str);*/
			return;
		}
	}
}

int main()
{
	int n, i, j, k, p1, p2, chk, score;
	char *ptr;
	n = 0;
	while(gets(str))
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		ptr = str + (chk=strlen(str));
		if(!chk || *(ptr-1) != '.')
		{
			while(gets(ptr))
			{
				ptr += (chk=strlen(ptr));
				if(chk && *(ptr-1) == '.')
				{
					*(ptr-1) = 0;
					break;
				}
			}
		}
		head[n] = (struct node*)malloc(sizeof(struct node));
		build(head[n], 0, strlen(str)-1);
		n++;
	}
	for(i=0; i<n; i++)
	{
		score = 0;
		memset(variable, 0, sizeof(variable));
		for(j=0; j<n; j++)
		{
			if(i != j)
			{
				memset(variable[i], 0, sizeof(variable[i]));
				k = 10;
				while(k--)
				{
					buf = variable[i];
					p1 = getaction(head[i]);
					buf = variable[j];
					p2 = getaction(head[j]);
					if(p1 == 1)
					{
						if(p2 == 1)
						{
							score--;
						}
						else
						{
							score += 2;
						}
					}
					else
					{
						if(p2 == 1)
						{
							score -= 2;
						}
						else
						{
							score++;
						}
					}
					variable[i][2] = variable[i][0];
					variable[i][3] = variable[i][1];
					variable[i][0] = p1;
					variable[i][1] = p2;
					variable[j][2] = variable[j][0];
					variable[j][3] = variable[j][1];
					variable[j][0] = p2;
					variable[j][1] = p1;
				}
			}
		}
		printf("%3d\n", score);
	}
	scanf(" ");
	return 0;
}
