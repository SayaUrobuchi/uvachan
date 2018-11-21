#include <stdio.h>
#include <string.h>

int ary[1005];
char buf[100005];

int main()
{
	int count, i, j, ans, cnt, cmp, loc;
	char *str, *astr;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", buf);
		for(str=buf, ans=-1; *str; str++)
		{
			ary[0] = -1;
			for(i=1, j=-1; str[i]; i++)
			{
				ary[i] = j+1;
				for(j++; j!=-1; j=ary[j])
				{
					if(str[i] == str[j])
					{
						break;
					}
				}
			}
			for(i=0, j=0; buf[i]; i++)
			{
				if(buf+i == str)
				{
					j = 0;
					continue;
				}
				for(; j!=-1; j=ary[j])
				{
					if(buf[i] == str[j])
					{
						break;
					}
				}
				j++;
				if(j > ans)
				{
					ans = j;
					astr = str;
					cnt = 2;
					loc = i;
				}
				else if(j == ans)
				{
					cmp = strncmp(astr, str, ans);
					if(cmp > 0)
					{
						astr = str;
					}
					else if(cmp == 0 && loc == i)
					{
						cnt++;
					}
				}
			}
		}
		if(ans <= 0)
		{
			printf("No repetitions found!\n");
		}
		else
		{
			printf("%.*s %d\n", ans, astr, cnt);
		}
	}
	return 0;
}
