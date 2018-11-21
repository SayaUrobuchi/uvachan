#include <stdio.h>
#include <string.h>

char str[10000][100];
char buf[10000];

int nnn(int left, int right)
{
	int i;
	char *ptr;
	ptr = buf;
	for(i=left; i<=right; i++)
	{
		strcpy(ptr, str[i]);
		ptr += strlen(ptr);
	}
	for(i=0; buf[i]; i++)
	{
		if(buf[i] < 48 || buf[i] > 57)
		{
			return 0;
		}
	}
	return 1;
}

int cas(int left, int right)
{
	if(left == right)
	{
		return !strcmp(str[left], "CAS");
	}
	return !strcmp(str[left], "CHANGE") && !strcmp(str[left+1], "AVERAGE") && !strcmp(str[left+2], "SPEED");
}

int change(int left, int right)
{
	return (left+2 <= right-1 && cas(left, left) && !strcmp(str[left+1], "TO") && nnn(left+2, right-1) && !strcmp(str[right], "KMH")) || 
		   (left+4 <= right-1 && cas(left, left+2) && !strcmp(str[left+3], "TO") && nnn(left+4, right-1) && !strcmp(str[right], "KMH"));
}

int record(int left, int right)
{
	return left+1 == right && !strcmp(str[left], "RECORD") && !strcmp(str[right], "TIME");
}

int time_keeping(int left, int right)
{
	return record(left, right) || change(left, right);
}

int letter(int left, int right)
{
	return (buf[left] > 64 && buf[right] < 91) || buf[left] == '.';
}

int s_word(int left, int right)
{
	return (left == right && letter(left, right)) || (left < right && s_word(left, right-1) && letter(right, right));
}

int signwords(int left, int right)
{
	return (left == right && s_word(left, right)) || (left < right && signwords(left, right-1) && s_word(right, right));
}

int sign(int left, int right)
{
	int i;
	char *ptr;
	if(str[left][0] == '"' && str[right][strlen(str[right])-1] == '"')
	{
		ptr = buf;
		strcpy(buf, str[left]+1);
		ptr += strlen(ptr);
		for(i=left+1; i<=right; i++)
		{
			strcpy(ptr, str[i]);
			ptr += strlen(ptr);
		}
		*(--ptr) = 0;
		return signwords(0, strlen(buf)-1);
	}
	return 0;
}

int where(int left, int right)
{
	return left < right && !strcmp(str[left], "AT") && sign(left+1, right);
}

int when(int left, int right)
{
	return left == right && (!strcmp(str[left], "FIRST") || !strcmp(str[left], "SECOND") || !strcmp(str[left], "THIRD"));
}

int direction(int left, int right)
{
	return !strcmp(str[left], "RIGHT") || !strcmp(str[left], "LEFT");
}

int how(int left, int right)
{
	if(left == right)
	{
		return !strcmp(str[left], "GO") || !strcmp(str[right], "KEEP");
	}
	return !strcmp(str[left], "GO") && when(left+1, right);
}

int directional(int left, int right)
{
	int i;
	for(i=left; i<left+2&&i+1<=right; i++)
	{
		if(how(left, i) && direction(i+1, i+1))
		{
			if(i+1 != right)
			{
				if(where(i+2, right))
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
	}
	return 0;
}

int navigational(int left, int right)
{
	int i;
	if(directional(left, right))
	{
		return 1;
	}
	for(i=left+2; i<right; i++)
	{
		if(!strcmp(str[i-1], "AND") && !strcmp(str[i], "THEN"))
		{
			if(navigational(left, i-2) && directional(i+1, right))
			{
				return 1;
			}
		}
	}
	return 0;
}

int instruction(int left, int right)
{
	int i;
	if(navigational(left, right) || time_keeping(left, right))
	{
		return 1;
	}
	for(i=left+1; i<right; i++)
	{
		if(!strcmp(str[i], "AND"))
		{
			if(navigational(left, i-1) && time_keeping(i+1, right))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cas, n, i;
	char *ptr;
	cas = 0;
	while(gets(buf))
	{
		if(!strcmp(buf, "#"))
		{
			break;
		}
		ptr = strtok(buf, " ");
		if(ptr)
		{
			n = 0;
			do
			{
				strcpy(str[n++], ptr);
			}while(ptr=strtok(NULL, " "));
		}
		if(n && instruction(0, n-1))
		{
			printf("%3d. %s", ++cas, str[0]);
			for(i=1; i<n; i++)
			{
				printf(" %s", str[i]);
			}
			printf("\n");
		}
		else
		{
			printf("%3d. Trap!\n", ++cas);
		}
	}
	return 0;
}
