#include <stdio.h>
#include <string.h>

char ary1[40], ary2[40];
char s1[15], s2[15], s3[15], s4[15];
char res[100];

int main()
{
	int cas, i, j, k, loc1, loc2;
	cas = 0;
	while(scanf("%s", s1) == 1)
	{
		if(s1[0] == '#')
		{
			break;
		}
		scanf("%s%s%s", s2, s3, s4);
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		memset(ary1, 32, sizeof(ary1));
		memset(ary2, 32, sizeof(ary2));
		for(i=0; s1[i]; i++)
		{
			for(j=0; s2[j]; j++)
			{
				if(s1[i] == s2[j])
				{
					break;
				}
			}
			if(s2[j])
			{
				break;
			}
		}
		if(s1[i])
		{
			loc1 = i;
			for(i=j-1, k=1; i>-1; i--, k++)
			{
				ary1[20-k] = s2[i];
			}
			for(i=j+1, k=1; s2[i]; i++, k++)
			{
				ary1[20+k] = s2[i];
			}
			for(i=0; s3[i]; i++)
			{
				for(j=0; s4[j]; j++)
				{
					if(s3[i] == s4[j])
					{
						break;
					}
				}
				if(s4[j])
				{
					break;
				}
			}
			if(s3[i])
			{
				loc2 = strlen(s1) + 3 + i;
				for(i=j-1, k=1; i>-1; i--, k++)
				{
					ary2[20-k] = s4[i];
				}
				for(i=j+1, k=1; s4[i]; i++, k++)
				{
					ary2[20+k] = s4[i];
				}
				memset(res, 32, sizeof(res));
				for(i=0; i<40; i++)
				{
					if(i == 20)
					{
						printf("%s   %s\n", s1, s3);
					}
					else
					{
						res[loc1] = ary1[i];
						res[loc2] = ary2[i];
						if(ary2[i] != 32)
						{
							res[loc2+1] = 0;
							printf("%s\n", res);
							res[loc2+1] = 32;
						}
						else if(ary1[i] != 32)
						{
							res[loc1+1] = 0;
							printf("%s\n", res);
							res[loc1+1] = 32;
						}
					}
				}
			}
			else
			{
				printf("Unable to make two crosses\n");
			}
		}
		else
		{
			printf("Unable to make two crosses\n");
		}
	}
	return 0;
}
