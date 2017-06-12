#include <stdio.h>
#include <string.h>

int len, n;
int dis[101];
int from[101];
int s[401], e[401], length[401];
char type[401][30];
char name[101][30];
char str[1024];

int trans(char *ptr)
{
	int i, result;
	for(i=0, result=0; ptr[i]; i++)
	{
		result *= 10;
		result += ptr[i] - 48;
	}
	return result;
}

int search(char *ptr)
{
	int i;
	for(i=0; i<len; i++)
	{
		if(!strcmp(name[i], ptr))
		{
			return i;
		}
	}
	strcpy(name[len++], ptr);
	return len-1;
}

void backtracing(int now)
{
	if(from[now] != EOF)
	{
		backtracing(s[from[now]]);
		printf("%-21s%-21s%-11s%5d\n", name[s[from[now]]], name[now], type[from[now]], length[from[now]]);
	}
}

int main()
{
	int start, end, i, j;
	n = 0;
	while(gets(str))
	{
		if(!str[0])
		{
			break;
		}
		s[n] = search(strtok(str, ","));
		e[n] = search(strtok(NULL, ","));
		strcpy(type[n], strtok(NULL, ","));
		length[n++] = trans(strtok(NULL, ","));
		s[n] = e[n-1];
		e[n] = s[n-1];
		strcpy(type[n], type[n-1]);
		length[n] = length[n-1];
		n++;
	}
	while(gets(str))
	{
		start = search(strtok(str, ","));
		end = search(strtok(NULL, ","));
		for(i=0; i<len; i++)
		{
			dis[i] = 100000;
		}
		dis[start] = 0;
		from[start] = -1;
		for(i=1; i<len; i++)
		{
			for(j=0; j<n; j++)
			{
				if(dis[s[j]] + length[j] < dis[e[j]])
				{
					dis[e[j]] = dis[s[j]] + length[j];
					from[e[j]] = j;
				}
			}
		}
		puts("\n\nFrom                 To                   Route      Miles");
		puts("-------------------- -------------------- ---------- -----");
		backtracing(end);
		puts("                                                     -----");
		printf("                                          Total      %5d\n", dis[end]);
	}
	return 0;
}
