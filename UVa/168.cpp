#include <stdio.h>
#include <string.h>

int map[26][26], num[26];
int cand[26];
char str[256];
char s1[100], s2[100];

int main()
{
	int m, i, ch, now, mino, c;
	char *ptr;
	while(scanf("%s", str) == 1)
	{
		if(str[0] == '#')
		{
			break;
		}
		scanf("%s%s%d", s1, s2, &m);
		memset(num, 0, sizeof(num));
		ptr = strtok(str, ";.");
		do
		{
			ch = ptr[0] - 65;
			for(i=2; ptr[i]; i++)
			{
				map[ch][num[ch]++] = ptr[i] - 65;
			}
		}while(ptr=strtok(NULL, ";."));
		now = s2[0] - 65;
		mino = s1[0] - 65;
		memset(cand, 0, sizeof(cand));
		for(c=1; ; c++)
		{
			/*printf("now %c, mino %c\n", now+65, mino+65);*/
			for(i=0; i<num[mino]; i++)
			{
				if(!cand[map[mino][i]] && map[mino][i] != now)
				{
					break;
				}
			}
			if(i == num[mino])
			{
				printf("/%c\n", mino+65);
				break;
			}
			if(c == m)
			{
				printf("%c ", mino+65);
				cand[mino] = 1;
				c = 0;
			}
			now = mino;
			mino = map[mino][i];
		}
	}
	return 0;
}
