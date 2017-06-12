#include <stdio.h>
#include <string.h>

int main()
{
	int path[26], count, n, check, tmp, tmp2, i, j, k;
	char buf[1001], connect[26][26], appear[26];
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(path, 0, 104);
		memset(appear, 0, 26);
		memset(connect, 0, 26 * 26);
		while(n--)
		{
			scanf("%s", buf);
			tmp = buf[0] - 97;
			path[tmp]++;
			appear[tmp] = 1;
			tmp2 = buf[strlen(buf) - 1] - 97;
			path[tmp2]--;
			appear[tmp2] = 1;
			connect[tmp][tmp2] = 1;
		}
		for(n=0, check=0; n<26; n++)
		{
			if(path[n] > 1 || path[n] < -1) break;
			if(path[n] == 1)
			{
				if(check % 10) break;
				check++;
			}
			else if(path[n] == -1)
			{
				if(check / 10) break;
				check += 10;
			}
		}
		if(n == 26)
		{
			if(check) printf("Ordering is possible.\n");
			else
			{
				for(k=0; k<26; k++)
				{
					for(i=0; i<26; i++)
					{
						for(j=0; j<26; j++)
						{
							if(connect[i][k] && connect[k][j]) connect[i][j] = 1;
						}
					}
				}
				for(i=0; !appear[i]; i++);
				for(j=i+1; j<26; j++)
				{
					if(appear[j] && !connect[i][j]) break;
				}
				if(j == 26) printf("Ordering is possible.\n");
				else printf("The door cannot be opened.\n");
			}
		}
		else printf("The door cannot be opened.\n");
	}
	return 0;
}
