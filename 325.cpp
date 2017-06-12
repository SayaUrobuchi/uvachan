#include <stdio.h>
#include <string.h>

char str[100000], buf[100000];

int dig(char now)
{
	return now > 47 && now < 58;
}

int illegal(char now)
{
	if(now > 47 && now < 58)
	{
		return 0;
	}
	if(now == 'e' || now == 'E')
	{
		return 0;
	}
	if(now == '+' || now == '-')
	{
		return 0;
	}
	if(now == '.')
	{
		return 0;
	}
	return 1;
}

int main()
{
	int i, c, chk;
	char *ptr;
	while(gets(str))
	{
		if(str[0] == '*')
		{
			break;
		}
		if(sscanf(str, "%s", buf) == EOF)
		{
			printf(" is illegal.\n");
		}
		else
		{
			for(i=0; str[i]==' '; i++);
			strcpy(buf, str+i);
			for(i=strlen(buf)-1; buf[i]==' '; i--);
			buf[i+1] = 0;
			strcpy(str, buf);
			for(i=0, c=0, chk=0; str[i]; i++)
			{
				if(illegal(str[i]))
				{
					break;
				}
				c += (str[i] == 'e' || str[i] == 'E');
				if(c > 1)
				{
					break;
				}
				if(str[i] == '+' || str[i] == '-')
				{
					if(i && (str[i-1] != 'e' && str[i-1] != 'E'))
					{
						break;
					}
				}
				chk += (str[i] == '.');
				if(chk > 1)
				{
					break;
				}
			}
			if(str[i])
			{
				printf("%s is illegal.\n", buf);
			}
			else
			{
				if(str[strlen(str)-1] == 'e' || str[strlen(str)-1] == 'E')
				{
					printf("%s is illegal.\n", str);
				}
				else
				{
					ptr = strtok(str, "eE");
					for(i=0, c=0, chk=-1; ptr[i]; i++)
					{
						if(ptr[i] == '.')
						{
							chk = i;
						}
						c += (ptr[i] > 47 && ptr[i] < 58);
					}
					if(!c && strlen(ptr)>1 && (ptr[0]!='+'&&ptr[0]!='-'))
					{
						printf("%s is illegal.\n", buf);
					}
					else
					{
						if(chk != -1)
						{
							if(!chk || !dig(ptr[chk+1]))
							{
								printf("%s is illegal.\n", buf);
							}
							else
							{
								ptr = strtok(NULL, "eE");
								if(ptr)
								{
									for(i=0, c=0; ptr[i]; i++)
									{
										if(ptr[i] == '.')
										{
											break;
										}
										if(ptr[i] == '+' || ptr[i] == '-')
										{
											if(i)
											{
												break;
											}
										}
										c += dig(ptr[i]);
									}
									if(!c || ptr[i])
									{
										printf("%s is illegal.\n", buf);
									}
									else
									{
										printf("%s is legal.\n", buf);
									}
								}
								else
								{
									printf("%s is legal.\n", buf);
								}
							}
						}
						else
						{
							ptr = strtok(NULL, "eE");
							if(ptr)
							{
								for(i=0, c=0; ptr[i]; i++)
								{
									if(ptr[i] == '.')
									{
										break;
									}
									if(ptr[i] == '+' || ptr[i] == '-')
									{
										if(i)
										{
											break;
										}
									}
									c += dig(ptr[i]);
								}
								if(!c || ptr[i])
								{
									printf("%s is illegal.\n", buf);
								}
								else
								{
									printf("%s is legal.\n", buf);
								}
							}
							else
							{
								printf("%s is illegal.\n", buf);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
