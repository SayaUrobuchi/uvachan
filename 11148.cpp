#include <stdio.h>
#include <string.h>

int lcd(int p, int q)
{
	if(!q) return 1;
	if(p % q) return lcd(q, p % q);
	else return q;
}

int main()
{
	int n, in, in2, in3, i, recog, son, mother, lcdtmp, len;
	char buf[1000], *str, check, tmp, tmp2, *ptr;
	scanf("%d", &n);
	gets(buf);
	while(n--)
	{
		son = 1;
		mother = 1;
		gets(buf);
		str = strtok(buf, " ");
		do
		{
			for(i=0; str[i]; i++)
			{
				if(str[i] > 47 && str[i] < 58)
				{
					ptr = str + i;
					recog = sscanf(ptr, "%d%c%d%c%d", &in, &tmp, &in2, &tmp2, &in3);
					if(recog == 1) son *= in;
					else if(recog == 3)
					{
						lcdtmp = lcd(son, in2);
						son /= lcdtmp;
						in2 /= lcdtmp;
						lcdtmp = lcd(mother, in);
						mother /= lcdtmp;
						in /= lcdtmp;
						son *= in;
						mother *= in2;
					}
					else
					{
						in2 += in * in3;
						lcdtmp = lcd(son, in3);
						son /= lcdtmp;
						in3 /= lcdtmp;
						lcdtmp = lcd(mother, in2);
						mother /= lcdtmp;
						in2 /= lcdtmp;
						son *= in2;
						mother *= in3;
					}
					break;
				}
			}
			str = strtok(NULL, " ");
		}while(str != NULL);
		if(!(son % mother)) printf("%d\n", son / mother);
		else
		{
			if(son > mother)
			{
				printf("%d-", son / mother);
				son %= mother;
			}
			printf("%d/%d\n", son, mother);
		}
	}
	return 0;
}
