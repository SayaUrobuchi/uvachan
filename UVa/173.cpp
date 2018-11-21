#include <stdio.h>
#include <string.h>

int conn[26][26];
int used[26];
char str[1000];
char s1[10], s2[10];

int main()
{
	int i, j, paskill, lisper, ptrap, ltrap, ldes, ch, len;
	char *ptr, *buf;
	while(gets(str))
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		memset(conn, 0, sizeof(conn));
		buf = strtok(str, ".");
		ptr = strtok(NULL, ".");
		sscanf(ptr, "%s%s", s1, s2);
		paskill = s1[0] - 65;
		lisper = s2[0] - 65;
		ptr = strtok(buf, ";");
		do
		{
			ch = *ptr - 65;
			for(i=2; ptr[i]; i++)
			{
				conn[ch][ptr[i]-65] = 1;
				conn[ptr[i]-65][ch] = 1;
			}
		}while(ptr=strtok(NULL, ";"));
		memset(used, 0, sizeof(used));
		if(lisper == paskill)
		{
			printf("Both annihilated in node %c\n", paskill+65);
		}
		else
		{
			for(ptrap=ltrap=ldes=0; ; )
			{
				/*printf("%c %c\n", paskill+65, lisper+65);*/
				used[paskill] = 2;
				used[lisper] = 1;
				for(i=paskill; ; )
				{
					i++;
					if(i == 26)
					{
						i = 0;
					}
					if(i == paskill || (conn[paskill][i] && !used[i]))
					{
						break;
					}
				}
				if(i == paskill)
				{
					ptrap = 1;
				}
				paskill = i;
				for(i=lisper; ; )
				{
					i--;
					if(i == -1)
					{
						i = 25;
					}
					if(i == lisper || (conn[lisper][i] && used[i] != 1))
					{
						break;
					}
				}
				if(i == lisper)
				{
					ltrap = 1;
				}
				else if(used[i] == 2)
				{
					ldes = 1;
				}
				lisper = i;
				if(lisper == paskill || ptrap || ltrap || ldes)
				{
					break;
				}
			}
			if(ptrap)
			{
				printf("Paskill trapped in node %c", paskill+65);
			}
			if(lisper == paskill)
			{
				if(ptrap)
				{
					printf(" ");
				}
				printf("Both annihilated in node %c", lisper+65);
			}
			else if(ldes)
			{
				if(ptrap)
				{
					printf(" ");
				}
				printf("Lisper destroyed in node %c", lisper+65);
			}
			else if(ltrap)
			{
				if(ptrap)
				{
					printf(" ");
				}
				printf("Lisper trapped in node %c", lisper+65);
			}
			printf("\n");
		}
	}
	return 0;
}
