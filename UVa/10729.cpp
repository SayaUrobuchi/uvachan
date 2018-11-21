#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, c, num[205], map[205][205];
char id[205], buf1[2008], buf2[2008], *ptr;

typedef struct data
{
	int id, num;
	char str[205];
	data *map[205];
}data;

data *head;

void analyze(data *p)
{
	char *q;
	/*printf("%c\n", *ptr);*/
	n++;
	if(p == NULL)
	{
		head = (data*)malloc(sizeof(data));
		p = head;
	}
	q = p->str;
	p->id = *(ptr++);
	p->num = 0;
	if(*ptr == '(')
	{
		ptr++;
		for(; ; )
		{
			p->map[p->num] = (data*)malloc(sizeof(data));
			*(q++) = *ptr;
			analyze(p->map[p->num]);
			p->num++;
			if(*(ptr++) == ')')
			{
				break;
			}
		}
	}
	*q = 0;
}

void build()
{
	int now, temp;
	now = c++;
	id[now] = *(ptr++);
	if(*ptr == '(')
	{
		ptr++;
		for(; ; )
		{
			map[now][num[now]++] = c;
			map[c][num[c]++] = now;
			build();
			if(*(ptr++) == ')')
			{
				break;
			}
		}
	}
}

int equal(data *p, int now, int parent)
{
	int i, j, k, temp;
	char buf[405], *q;
	if(parent == -1)
	{
		if(!num[now])
		{
			return 1;
		}
		for(i=0; i<num[now]; i++)
		{
			buf1[i] = id[map[now][i]];
		}
		buf1[i] = 0;
		sprintf(buf, "%s%s\0", buf1, buf1);
		for(i=0; i<num[now]; i++)
		{
			if(!strncmp(buf+i, p->str, num[now]))
			{
				for(j=i, k=0; k<num[now]; j++, k++)
				{
					if(j >= num[now])
					{
						j -= num[now];
					}
					if(equal(p->map[k], map[now][j], now) == 0)
					{
						break;
					}
				}
				if(k == num[now])
				{
					return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		/*printf("%d %d\n", now, parent);*/
		if(num[now] - 1 != p->num)
		{
			return 0;
		}
		for(i=0, q=buf; map[now][i]!=parent; i++);
		for(i++, j=1; j<num[now]; i++, j++)
		{
			if(i >= num[now])
			{
				i -= num[now];
			}
			*(q++) = id[map[now][i]];
		}
		*q = 0;
		/*printf("%s %s\n", p->str, buf);*/
		if(strcmp(p->str, buf))
		{
			return 0;
		}
		for(temp=i+1, i=1; i<num[now]; i++, temp++)
		{
			if(temp >= num[now])
			{
				temp -= num[now];
			}
			if(equal(p->map[i-1], map[now][temp], now) == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s", buf1, buf2);
		n = 0;
		memset(num, 0, sizeof(num));
		head = NULL;
		ptr = buf1;
		analyze(head);
		ptr = buf2;
		c = 0;
		build();
		/*for(i=0; i<c; i++)
		{
			printf("%d => %c\n", i, id[i]);
		}*/
		if(n != c)
		{
			/*printf("Special");*/
			printf("different\n");
		}
		else
		{
			for(i=0; i<c; i++)
			{
				if(id[i] == head->id && num[i] == head->num)
				{
					if(equal(head, i, -1))
					{
						break;
					}
				}
			}
			if(i == c)
			{
				printf("different\n");
			}
			else
			{
				printf("same\n");
			}
		}
	}
	return 0;
}
