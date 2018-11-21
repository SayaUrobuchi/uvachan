#include <stdio.h>
#include <string.h>

int tbl[127];
char s1[1000], s2[1000];

int main()
{
	int i, j, k, len;
	for(i=65; i<91; i++)
	{
		tbl[i] = 1;
	}
	for(i=97; i<123; i++)
	{
		tbl[i] = 2;
	}
	for(i=48; i<58; i++)
	{
		tbl[i] = 3;
	}
	strcpy(s1, "~!@#$%^&*()_+|`-=\\{}[]:\";'<>?,./ ");
	for(i=0; s1[i]; i++)
	{
		tbl[s1[i]] = 4;
	}
	while(gets(s1))
	{
		gets(s2);
		if(!strcmp(s1, s2))
		{
			if(!strcmp(s1, "END"))
			{
				break;
			}
			len = strlen(s1);
			if(len >= 8 && len <= 12)
			{
				for(i=0; i<len; i++)
				{
					if(tbl[s1[i]] == 1)
					{
						break;
					}
				}
				if(i < len)
				{
					for(i=0; i<len; i++)
					{
						if(tbl[s1[i]] == 2)
						{
							break;
						}
					}
					if(i < len)
					{
						for(i=0; i<len; i++)
						{
							if(tbl[s1[i]] == 3)
							{
								break;
							}
						}
						if(i < len)
						{
							for(i=0; i<len; i++)
							{
								if(tbl[s1[i]] == 4)
								{
									break;
								}
							}
							if(i < len)
							{
								for(i=0, j=len-1; i<j; i++, j--)
								{
									if(s1[i] != s1[j])
									{
										break;
									}
								}
								if(i < j)
								{
									for(i=3; i<=6; i++)
									{
										for(j=0; j<i; j++)
										{
											for(k=j+i; k<len; k+=i)
											{
												if(s1[k] != s1[j])
												{
													break;
												}
											}
											if(k < len)
											{
												break;
											}
										}
										if(j == i)
										{
											break;
										}
									}
									if(i > 6)
									{
										printf("Password is valid.\n");
									}
									else
									{
										printf("Circular password is not allowed.\n");
									}
								}
								else
								{
									printf("Symmetric password is not allowed.\n");
								}
							}
							else
							{
								printf("Password should contain at least one special character.\n");
							}
						}
						else
						{
							printf("Password should contain at least one number.\n");
						}
					}
					else
					{
						printf("Password should contain at least one lower-case alphabetical character.\n");
					}
				}
				else
				{
					printf("Password should contain at least one upper-case alphabetical character.\n");
				}
			}
			else
			{
				printf("Password should contain 8 to 12 characters.\n");
			}
		}
		else
		{
			printf("Password settings are not consistent.\n");
		}
	}
	return 0;
}
