#include <stdio.h>

int main()
{
	int i, s[2], b[3], o, type;
	char str[1000];
	while(scanf("%s", str) == 1)
	{
		type = 0;
		s[0] = s[1] = 0;
		b[0] = b[1] = b[2] = o = 0;
		for(i=0; str[i]; i++)
		{
			if(str[i] == 'K' || str[i] == 'O')
			{
				o++;
				if(o == 3)
				{
					b[0] = b[1] = b[2] = o = 0;
					type = 1 - type;
				}
			}
			else if(str[i] == 'H')
			{
				s[type] += b[0] + b[1] + b[2] + 1;
				b[0] = b[1] = b[2] = 0;
			}
			else if(str[i] == 'W')
			{
				if(b[0])
				{
					if(b[1])
					{
						if(b[2])
						{
							s[type]++;
						}
						b[2] = 1;
					}
					b[1] = 1;
				}
				b[0] = 1;
			}
			else if(str[i] == 'S')
			{
				s[type] += b[2];
				b[2] = b[1];
				b[1] = b[0];
				b[0] = 1;
			}
			else if(str[i] == 'D')
			{
				s[type] += b[2] + b[1];
				b[2] = b[0];
				b[1] = 1;
				b[0] = 0;
			}
			else if(str[i] == 'T')
			{
				s[type] += b[2] + b[1] + b[0];
				b[2] = 1;
				b[1] = 0;
				b[0] = 0;
			}
		}
		printf("%d %d\n", s[0], s[1]);
	}
	return 0;
}
