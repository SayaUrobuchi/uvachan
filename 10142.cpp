#include <stdio.h>
#include <string.h>

char name[20][81], vote[1000][20], ptr[1000], deathnote[20], buf[100], *str, survive[20];
int getticket[20];

int main()
{
	int count, n, m, i, j, min;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(buf);
		for(i=0; i<n; i++)
		{
			gets(name[i]);
			getticket[i] = 0;
			survive[i] = 1;
		}
		m = 0;
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			str = strtok(buf, " ");
			vote[m][0] = str[0] - 48;
			if(str[1])
			{
				vote[m][0] *= 10;
				vote[m][0] += str[1] - 48;
			}
			getticket[--vote[m][0]]++;
			ptr[m] = 0;
			for(j=1; j<n; j++)
			{
				str = strtok(NULL, " ");
				vote[m][j] = str[0] - 48;
				if(str[1])
				{
					vote[m][j] *= 10;
					vote[m][j] += str[1] - 48;
				}
				vote[m][j]--;
			}
			m++;
		}
		while(1)
		{
			min = 2000;
			for(i=0; i<n; i++)
			{
				if(survive[i])
				{
					if(getticket[i] + getticket[i] > m)
					{
						break;
					}
					if(getticket[i] < min)
					{
						min = getticket[i];
						memset(deathnote, 0, sizeof(deathnote));
						deathnote[i] = 1;
					}
					else if(getticket[i] == min)
					{
						deathnote[i] = 1;
					}
					getticket[i] = 0;
				}
			}
			if(i < n)
			{
				break;
			}
			for(i=0, j=0; i<n; i++)
			{
				if(deathnote[i])
				{
					survive[i] = 0;
				}
				else if(survive[i])
				{
					j = 1;
				}
			}
			if(!j)
			{
				break;
			}
			for(i=0; i<m; i++)
			{
				while(!survive[vote[i][ptr[i]]])
				{
					ptr[i]++;
				}
				getticket[vote[i][ptr[i]]]++;
			}
		}
		if(i < n)
		{
			printf("%s\n", name[i]);
		}
		else
		{
			for(i=0; i<n; i++)
			{
				if(deathnote[i])
				{
					printf("%s\n", name[i]);
				}
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}