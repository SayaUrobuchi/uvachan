#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dir[1000001], tdir[1000001], buf[100000001], dnam[1000001];

int main()
{
	int i, f, len, dcnt, siz, res, tlen;
	char *ptr, *pp;
	strcpy(dir, "\\");
	len = 1;
	f = 0;
	pp = buf;
	while(f || gets(pp))
	{
		f = 0;
		if(strcmp(pp, ">exit") == 0)
		{
			break;
		}
		else if(*pp == '>')
		{
			if(pp[1] == 'c')
			{
				ptr = pp+4;
				if(*ptr == '\\')
				{
					strcpy(dir, ptr);
					len = strlen(dir);
					if(dir[len-1] != '\\')
					{
						strcpy(dir+len, "\\");
						len++;
					}
				}
				else if(*ptr == '.')
				{
					for(i=len-2; i>=0; i--)
					{
						if(dir[i] == '\\')
						{
							dir[i+1] = 0;
							len = i+1;
							break;
						}
					}
				}
				else
				{
					strcpy(dir+len, ptr);
					len += strlen(ptr);
					if(dir[len-1] != '\\')
					{
						strcpy(dir+len, "\\");
						len++;
					}
				}
				pp += strlen(pp) + 1;
			}
			else if(pp[2] == 'i')
			{
				pp += strlen(pp) + 1;
				while(gets(pp))
				{
					if(*pp == '>')
					{
						break;
					}
					pp += strlen(pp) + 1;
				}
				f = 1;
			}
			else
			{
				ptr = pp + 9;
				if(*ptr == '\\')
				{
					strcpy(dir, ptr);
					len = strlen(ptr);
				}
				else
				{
					strcpy(dir+len, ptr);
					len += strlen(ptr);
				}
				strcpy(tdir, dir);
				tlen = len;
				strcpy(dir, "\\");
				len = 1;
				for(pp=buf, res=0; ; )
				{
					if(*pp == '>')
					{
						if(pp[1] == 'c')
						{
							ptr = pp+4;
							if(*ptr == '\\')
							{
								strcpy(dir, ptr);
								len = strlen(dir);
								if(dir[len-1] != '\\')
								{
									strcpy(dir+len, "\\");
									len++;
								}
							}
							else if(*ptr == '.')
							{
								for(i=len-2; i>=0; i--)
								{
									if(dir[i] == '\\')
									{
										dir[i+1] = 0;
										len = i+1;
										break;
									}
								}
							}
							else
							{
								strcpy(dir+len, ptr);
								len += strlen(ptr);
								if(dir[len-1] != '\\')
								{
									strcpy(dir+len, "\\");
									len++;
								}
							}
							pp += strlen(pp) + 1;
						}
						else if(pp[2] == 'i')
						{
							pp += strlen(pp) + 1;
							while(1)
							{
								if(*pp == '>')
								{
									break;
								}
								if(strncmp(tdir, dir, tlen) == 0 && sscanf(pp, "%*s%d", &siz) == 1)
								{
									res += siz;
								}
								pp += strlen(pp) + 1;
							}
						}
						else
						{
							break;
						}
					}
				}
				printf("%d\n", res);
			}
		}
		else
		{
			strcpy(dir, "\\");
			len = 1;
			pp = buf;
		}
	}
	return 0;
}
