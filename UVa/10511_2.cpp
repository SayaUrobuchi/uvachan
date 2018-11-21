#include <stdio.h>
#include <string.h>

#define CNUM 1005
#define NUM 1005

int n, cnum, pnum;
int own[NUM];
int used[NUM];
int sused[CNUM], tused[NUM];
int party[NUM];
int cassign[CNUM];
int num[CNUM];
int map[CNUM][NUM];
char buf[NUM];
char name[NUM][85];
char partyname[NUM][85];
char clubname[CNUM][85];

int fill(int);

int getparty(char *s)
{
	int i;
	for(i=0; i<pnum; i++)
	{
		if(!strcmp(s, partyname[i]))
		{
			return i;
		}
	}
	strcpy(partyname[pnum], s);
	return pnum++;
}

int getclub(char *s)
{
	int i;
	for(i=0; i<cnum; i++)
	{
		if(!strcmp(s, clubname[i]))
		{
			return i;
		}
	}
	if(cnum >= CNUM) while(1);
	strcpy(clubname[cnum], s);
	return cnum++;
}

int assign(int now)
{
	int i, temp, ptemp;
	if(used[now])
	{
		if(sused[used[now]-1])
		{
			return 0;
		}
		return fill(used[now]-1);
	}
	else
	{
		ptemp = party[now];
		if(own[ptemp] + own[ptemp] + 2 < cnum)
		{
			return 1;
		}
		for(i=0; i<cnum; i++)
		{
			if(!sused[i] && cassign[i] && !tused[cassign[i]] && party[temp=cassign[i]] == ptemp)
			{
				tused[temp] = 1;
				if(fill(i))
				{
					used[temp] = 0;
					own[ptemp]--;
					return 1;
				}
			}
		}
	}
	return 0;
}

int fill(int now)
{
	int i, target;
	sused[now] = 1;
	for(i=0; i<num[now]; i++)
	{
		target = map[now][i];
		/*printf("now %d: TARGET %d, used? %d, party %d, tused %d.\n", now, target, used[target], party[target], tused[party[target]]);*/
		if(!tused[target])
		{
			/*printf("now %d TARGET %d\n", now, target);*/
			tused[target] = 1;
			if(assign(target))
			{
				own[party[target]]++;
				used[target] = now + 1;
				cassign[now] = target;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, temp;
	char *ptr, *ptr2;
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		memset(num, 0, sizeof(num));
		memset(used, 0, sizeof(used));
		memset(own, 0, sizeof(own));
		n = 1;
		cnum = pnum = 0;
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			for(ptr=ptr2=buf; *ptr2!=' '; ptr2++);
			*ptr2 = 0;
			strcpy(name[n], ptr);
			for(ptr=++ptr2; *ptr2!=' '; ptr2++);
			*ptr2 = 0;
			party[n] = getparty(ptr);
			for(; ; )
			{
				for(ptr=++ptr2; *ptr2&&*ptr2!=' '; ptr2++);
				if(*ptr2)
				{
					*ptr2 = 0;
					temp = getclub(ptr);
					/*printf("%d owns %d.\n", temp, n);*/
					if(num[temp] >= NUM) while(1);
					map[temp][num[temp]++] = n;
				}
				else
				{
					temp = getclub(ptr);
					/*printf("%d owns %d.\n", temp, n);*/
					if(num[temp] >= NUM) while(1);
					map[temp][num[temp]++] = n;
					break;
				}
			}
			n++;
		}
		/*printf("%d\n", num[2]);*/
		memset(cassign, 0, sizeof(cassign));
		for(i=0; i<cnum; i++)
		{
			memset(sused, 0, sizeof(sused));
			memset(tused, 0, sizeof(tused));
			if(!fill(i))
			{
				/*printf("FAIL %d\n", i);*/
				break;
			}
		}
		if(i < cnum)
		{
			printf("Impossible.\n");
		}
		else
		{
			for(i=0; i<cnum; i++)
			{
				printf("%s %s\n", name[cassign[i]], clubname[i]);
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
