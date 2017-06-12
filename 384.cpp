#include <stdio.h>

int p;
char str[101];

int slump()
{
	if(str[p] == 'D' || str[p] == 'E')
	{
		p++;
		if(str[p] == 'F')
		{
			for(; str[p]=='F'; p++);
			if(str[p] == 'G')
			{
				p++;
				return 1;
			}
			else if(slump())
			{
				return 1;
			}
		}
	}
	return 0;
}

int slimp()
{
	if(str[p] == 'A')
	{
		p++;
		if(str[p] == 'H')
		{
			p++;
			return 1;
		}
		else if(str[p] == 'B')
		{
			for(; str[p]=='B'; p++);
			if(slimp())
			{
				if(str[p] == 'C')
				{
					p++;
					return 1;
				}
			}
		}
		else if(slump())
		{
			if(str[p] == 'C')
			{
				p++;
				return 1;
			}
		}
	}
	return 0;
}

int slurpy()
{
	if(slimp())
	{
		if(slump())
		{
			return !str[p];
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	int count;
	printf("SLURPYS OUTPUT\n");
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", str);
		p = 0;
		if(slurpy())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
