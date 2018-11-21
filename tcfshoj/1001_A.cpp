#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

char nam[25], s1[25], s2[25], buf[1048576];

void up(char *p)
{
	while(*p)
	{
		if(*p >= 'A' && *p <= 'Z')
		{
			*p += 'a'-'A';
		}
		p++;
	}
}

int main()
{
	int y, cnt;
	std::map<std::string, int>::iterator it;
	std::map<std::string, int> min_y, max_y;
	while(scanf("%d%s", &y, nam) == 2)
	{
		up(nam);
		it = min_y.find(nam);
		if(it == min_y.end() || y < it->second)
		{
			min_y[nam] = y;
		}
		it = max_y.find(nam);
		if(it == max_y.end() || y > it->second)
		{
			max_y[nam] = y;
		}
		gets(buf);
	}
	gets(buf);
	scanf("%d", &cnt);
	while(cnt--)
	{
		scanf("%s%s", s1, s2);
		if(max_y[s1] >= min_y[s2] && max_y[s2] >= min_y[s1])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
