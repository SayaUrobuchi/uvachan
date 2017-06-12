#include <stdio.h>
#include <string.h>

int buf1[2500], buf2[2500];
int chk1[2500], chk2[2500];

int main()
{
	int n, i, j, k, c, temp;
	while(scanf("%d", &n) == 1)
	{
		if(n < 4)
		{
			printf("Impossible\n");
		}
		else if(!((n-2)%6) || !((n-3)%6))
		{
			memset(buf1, 0, sizeof(buf1));
			memset(buf2, 0, sizeof(buf2));
			temp = (n-2) / 6;
			temp += temp;
			c = 1;
			printf("%d", temp+2);
			buf1[c+temp+2] = 1;
			buf2[c-temp-2+1100] = 1;
			c++;
			for(i=temp+4; i<=n; i+=2, c++)
			{
				printf(" %d", i);
				buf1[c+i] = 1;
				buf2[c-i+1100] = 1;
			}
			for(i=2; i<=temp; i+=2, c++)
			{
				printf(" %d", i);
				buf1[c+i] = 1;
				buf2[c-i+1100] = 1;
			}
			for(i=1; i<=n; i+=2)
			{
				memcpy(chk1, buf1, sizeof(chk1));
				memcpy(chk2, buf2, sizeof(chk2));
				for(j=i, k=c; j<=n; j+=2, k++)
				{
					if(chk1[k+j] || chk2[k-j+1100])
					{
						break;
					}
					chk1[k+j] = chk2[k-j+1100] = 1;
				}
				if(j > n)
				{
					for(j=1; j<i; j+=2, k++)
					{
						if(chk1[k+j] || chk2[k-j+1100])
						{
							break;
						}
						chk1[k+j] = chk2[k-j+1100] = 1;
					}
					if(j >= i)
					{
						for(j=i; j<=n; j+=2)
						{
							printf(" %d", j);
						}
						for(j=1; j<i; j+=2)
						{
							printf(" %d", j);
						}
						printf("\n");
						break;
					}
				}
			}
		}
		else
		{
			printf("2");
			for(i=4; i<=n; i+=2)
			{
				printf(" %d", i);
			}
			for(i=1; i<=n; i+=2)
			{
				printf(" %d", i);
			}
			printf("\n");
		}
	}
	return 0;
}
