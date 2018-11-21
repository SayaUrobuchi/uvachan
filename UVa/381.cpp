#include <stdio.h>
#include <math.h>

int bonus[35], absent[35];
int level[35];
double staver[35];

void adjust(int *ptr)
{
	if(*ptr < 1)
	{
		*ptr = 1;
	}
	if(*ptr > 5)
	{
		*ptr = 5;
	}
}

int main()
{
	int count, n, m, i, j, grade, mingrade;
	double claver, graver, sd;
	printf("MAKING THE GRADE OUTPUT\n");
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0, claver=0; i<n; i++)
		{
			for(j=0, staver[i]=0, mingrade=101; j<m; j++)
			{
				scanf("%d", &grade);
				if(grade < mingrade)
				{
					mingrade = grade;
				}
				staver[i] += grade;
			}
			if(m > 2)
			{
				staver[i] -= mingrade;
				staver[i] /= m - 1;
			}
			else
			{
				staver[i] /= m;
			}
			claver += staver[i];
			/*printf("Student %d AVER %lf\n", i, staver[i]);*/
			scanf("%d%d", &bonus[i], &absent[i]);
		}
		claver /= n;
		for(i=0, sd=0; i<n; i++)
		{
			sd += (staver[i] - claver) * (staver[i] - claver);
		}
		sd = sqrt(sd/n);
		/*printf("%lf %lf\n", claver, sd);*/
		for(i=0, graver=0; i<n; i++)
		{
			staver[i] += (bonus[i] / 2) * 3;
			if(staver[i] >= claver + sd)
			{
				level[i] = 1;
			}
			else if(staver[i] >= claver)
			{
				level[i] = 2;
			}
			else if(staver[i] >= claver - sd)
			{
				level[i] = 3;
			}
			else
			{
				level[i] = 4;
			}
			/*printf("Student %d LEVEL %d\n", i, level[i]);
			printf("%d ABSENT %d\n", i, absent[i]);*/
			level[i] -= (!absent[i]) - absent[i] / 4;
			adjust(level+i);
			/*printf("Student %d LEVEL %d\n", i, level[i]);*/
			graver += 5 - level[i];
		}
		graver /= n;
		printf("%.1lf\n", graver);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
