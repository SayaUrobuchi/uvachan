#include <stdio.h>
#include <string.h>

char str[100000], buf[11], chr[53];
char tbl[53][10] = {".-", ".---", "...", ".----", ".-.-.-", "---...", "-...", "-.-", "-",
				  "..---", "--..--", "-.-.-.", "-.-.", ".-..", "..-", "...--", "..--..",
				  "-...-", "-..", "--", "...-", "....-", ".----.", ".-.-.", ".", "-.", ".--",
				  ".....", "-.-.--", "-....-", "..-.", "---", "-..-", "-....", "-..-.", "..--.-",
				  "--.", ".--.", "-.--", "--...", "-.--.", ".-..-.", "....", "--.-", "--..",
				  "---..", "-.--.-", ".--.-.", "..", ".-.", "-----", "----.", ".-..."};

int main()
{
	int cas, count, i, j, len;
	chr[0] = 'A';
	chr[1] = 'J';
	chr[2] = 'S';
	chr[3] = '1';
	chr[4] = '.';
	chr[5] = ':';
	chr[6] = 'B';
	chr[7] = 'K';
	chr[8] = 'T';
	chr[9] = '2';
	chr[10] = ',';
	chr[11] = ';';
	chr[12] = 'C';
	chr[13] = 'L';
	chr[14] = 'U';
	chr[15] = '3';
	chr[16] = '?';
	chr[17] = '=';
	chr[18] = 'D';
	chr[19] = 'M';
	chr[20] = 'V';
	chr[21] = '4';
	chr[22] = '\'';
	chr[23] = '+';
	chr[24] = 'E';
	chr[25] = 'N';
	chr[26] = 'W';
	chr[27] = '5';
	chr[28] = '!';
	chr[29] = '-';
	chr[30] = 'F';
	chr[31] = 'O';
	chr[32] = 'X';
	chr[33] = '6';
	chr[34] = '/';
	chr[35] = '_';
	chr[36] = 'G';
	chr[37] = 'P';
	chr[38] = 'Y';
	chr[39] = '7';
	chr[40] = '(';
	chr[41] = '"';
	chr[42] = 'H';
	chr[43] = 'Q';
	chr[44] = 'Z';
	chr[45] = '8';
	chr[46] = ')';
	chr[47] = '@';
	chr[48] = 'I';
	chr[49] = 'R';
	chr[50] = '0';
	chr[51] = '9';
	chr[52] = '&';
	cas = 0;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		printf("Message #%d\n", ++cas);
		gets(str);
		buf[0] = 0;
		len = 0;
		for(i=0; ; i++)
		{
			if(!str[i])
			{
				if(len)
				{
					buf[len] = 0;
					for(j=0; j<53; j++)
					{
						if(!strcmp(buf, tbl[j]))
						{
							printf("%c", chr[j]);
							break;
						}
					}
				}
				if(count)
				{
					printf("\n");
				}
				printf("\n");
				break;
			}
			else if(str[i] == 32)
			{
				if(len)
				{
					buf[len] = 0;
					for(j=0; j<53; j++)
					{
						if(!strcmp(buf, tbl[j]))
						{
							printf("%c", chr[j]);
							break;
						}
					}
					len = 0;
				}
				else
				{
					printf(" ");
				}
			}
			else
			{
				buf[len++] = str[i];
			}
		}
	}
	return 0;
}
