#include <stdio.h>
#include <string.h>

int id;
int tbl[4] = {1, 3, 6, 12};
int connect[12][12], num[12];
int distance[12][12];
int queue[15], step[15];
int chk[15];
char list[1000];
char str[13];

int valid(int now)
{
	return now > -1 && now < 12;
}

int idfs(int loc, int dis, int depth)
{
	int i, target;
	char temp;
	if(!dis)
	{
		list[depth] = 0;
		return 1;
	}
	if(depth == id)
	{
		return 0;
	}
	if(dis + depth > id)
	{
		return 0;
	}
	for(i=0; i<num[loc]; i++)
	{
		target = connect[loc][i];
		temp = list[depth] = str[target];
		str[target] = str[loc];
		str[loc] = temp;
		if(idfs(target, dis+distance[loc][temp-65]-distance[target][temp-65], depth+1))
		{
			return 1;
		}
		str[loc] = str[target];
		str[target] = temp;
	}
	return 0;
}

int main()
{
	int cas, count, i, j, k, l, loc, dis, temp;
	cas = 0;
	for(i=0; i<12; i++)
	{
		for(j=0, k=0; j<3; j++)
		{
			loc = i + tbl[j];
			if(valid(loc) && i / tbl[j+1] == loc / tbl[j+1])
			{
				connect[i][k++] = loc;
			}
			loc = i - tbl[j];
			if(valid(loc) && i / tbl[j+1] == loc / tbl[j+1])
			{
				connect[i][k++] = loc;
			}
		}
		num[i] = k;
	}
	for(i=0; i<12; i++)
	{
		queue[0] = i;
		step[0] = 0;
		memset(chk, 0, sizeof(chk));
		chk[i] = 1;
		for(j=0, k=1; j<k; j++)
		{
			distance[i][temp=queue[j]] = step[j];
			for(l=0; l<num[temp]; l++)
			{
				if(!chk[connect[temp][l]])
				{
					chk[connect[temp][l]] = 1;
					queue[k] = connect[temp][l];
					step[k++] = step[j] + 1;
				}
			}
		}
	}
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		for(i=0, dis=0; str[i]; i++)
		{
			if(str[i] == 'L')
			{
				loc = i;
			}
			else
			{
				dis += distance[i][str[i]-65];
				/*printf("%d\n", distance[i][str[i]-65]);*/
			}
		}
		/*printf("dis %d\n", dis);*/
		for(id=dis; id<39; id+=2)
		{
			/*printf("%d\n", id);*/
			if(idfs(loc, dis, 0))
			{
				break;
			}
		}
		printf("Permutation #%d\n%s\n\n", ++cas, list);
	}
	return 0;
}
