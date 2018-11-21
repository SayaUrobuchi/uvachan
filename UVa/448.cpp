#include <stdio.h>

int buf[20], need;

void deal(char ch)
{
	if(ch >= '0' && ch <= '4')
	{
		need = 8;
	}
	else if(ch >= 'C' && ch <= 'E')
	{
		need = 12;
	}
	else
	{
		need = 4;
	}
	if(ch == '0')
	{
		printf("ADD ");
	}
	else if(ch == '1')
	{
		printf("SUB ");
	}
	else if(ch == '2')
	{
		printf("MUL ");
	}
	else if(ch == '3')
	{
		printf("DIV ");
	}
	else if(ch == '4')
	{
		printf("MOV ");
	}
	else if(ch == '5')
	{
		printf("BREQ ");
	}
	else if(ch == '6')
	{
		printf("BRLE ");
	}
	else if(ch == '7')
	{
		printf("BRLS ");
	}
	else if(ch == '8')
	{
		printf("BRGE ");
	}
	else if(ch == '9')
	{
		printf("BRGR ");
	}
	else if(ch == 'A')
	{
		printf("BRNE ");
	}
	else if(ch == 'B')
	{
		printf("BR ");
	}
	else if(ch == 'C')
	{
		printf("AND ");
	}
	else if(ch == 'D')
	{
		printf("OR ");
	}
	else if(ch == 'E')
	{
		printf("XOR ");
	}
	else
	{
		printf("NOT ");
	}
}

char trans(char ch)
{
	if(ch < 65)
	{
		return ch-48;
	}
	else
	{
		return ch-55;
	}
}

void decode(char* s)
{
	int i, j, res;
	s += 3;
	for(i=0; i<4; i++, s--)
	{
		*s = trans(*s);
		for(j=0; j<4; j++)
		{
			buf[i*4+j] = *s % 2;
			*s /= 2;
		}
	}
	if(!buf[15] && !buf[14])
	{
		putchar('R');
	}
	else if(!buf[15] && buf[14])
	{
		putchar('$');
	}
	else if(buf[15] && !buf[14])
	{
		printf("PC+");
	}
	res = 0;
	for(i=13; i>-1; i--)
	{
		res *= 2;
		res += buf[i];
	}
	printf("%d", res);
}

int main()
{
	int state, count;
	char ch, opcode[20];
	state = 1;
	while((ch=getchar())!=EOF)
	{
		if(ch != '\n')
		{
			if(state)
			{
				deal(ch);
				state = 0;
				count = 0;
			}
			else
			{
				opcode[count++] = ch;
				if(!(count % 4))
				{
					if(count != 4)
					{
						putchar(',');
					}
					decode(opcode+count-4);
				}
				if(count == need)
				{
					state = -1;
					putchar('\n');
				}
			}
		}
	}
	return 0;
}
