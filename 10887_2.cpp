#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index1[1505], index2[1505];
int length[1505];
char str1[1505][12], str2[1505][12];
char buf1[25], buf2[25];

int comp1(const void *p, const void *q)
{
	return strcmp(str1[*(int*)p], str1[*(int*)q]);
}

int comp2(const void *p, const void *q)
{
	return strcmp(str2[*(int*)p], str2[*(int*)q]);
}

int main()
{
	int cas, count, n, m, i, j, k, l, p, q, ans, now, last, cmp;
	char *p1, *p2;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		gets(buf1);
		for(i=0; i<n; i++)
		{
			/*scanf("%s", str1[i]);*/
			gets(str1[i]);
			length[i] = strlen(str1[i]);
			index1[i] = i;
		}
		qsort(index1, n, sizeof(int), comp1);
		for(i=0; i<m; i++)
		{
			/*scanf("%s", str2[i]);*/
			gets(str2[i]);
			index2[i] = i;
		}
		qsort(index2, m, sizeof(int), comp2);
		for(i=1, ans=n*m; i<n; i++)
		{
			now = index1[i];
			for(j=i-1; j>=0; j--)
			{
				last = index1[j];
				if(str1[now][0] != str1[last][0])
				{
					break;
				}
				if(!strncmp(str1[now], str1[last], length[last]))
				{
					strcpy(buf1, str1[now]);
					strcpy(buf2, str1[last]);
					printf("DO %s %s\n", buf1, buf2);
					for(k=0, l=0, p1=buf1+length[now], p2=buf2+length[last]; k<m&&l<m; )
					{
						p = index2[k];
						q = index2[l];
						strcpy(p1, str2[p]);
						strcpy(p2, str2[q]);
						printf("%s %s\n", buf1, buf2);
						cmp = strcmp(buf1, buf2);
						if(!cmp)
						{
							ans--;
							k++;
							l++;
						}
						else if(cmp > 0)
						{
							l++;
						}
						else
						{
							k++;
						}
					}
					printf("\n");
				}
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
