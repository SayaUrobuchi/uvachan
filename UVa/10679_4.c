#include <stdio.h>
#include <string.h>

int next[1005];
char str[100005], s[1005];

int main()
{
	int count, m, i, j, len, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", str, &m);
		/*for(i=0, j=strlen(str)-1; i<j; i++, j--)
		 * 		{
		 * 					temp = str[i];
		 * 								str[i] = str[j];
		 * 											str[j] = temp;
		 * 													}*/
		while(m--)
		{
			scanf("%s", s);
			/*for(i=0, j=strlen(s)-1; i<j; i++, j--)
			 * 			{
			 * 							temp = s[i];
			 * 											s[i] = s[j];
			 * 															s[j] = temp;
			 * 																		}*/
			/*if(strstr(str, s))*/
			if(strlen(str)>=strlen(s) && strncmp(str, s, strlen(s)) == 0)
			{
				printf("y\n");
			}
			else
			{
				printf("n\n");
			}
		}
	}
	return 0;
}

