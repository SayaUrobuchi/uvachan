#include <stdio.h>
#include <string.h>

int n, m, o;
int used[128];
int key[128];
int hash[128];
int list[26];
int dnum[17];
int diclist[17][1001];
int dmatch[1001][45];
int qnum[128];
int queuex[128][45], queuey[128][45];
int mdone[45];
int length[45];
char ary[45][81];
char dic[1001][18];
char buf[2008], stemp[2008];

int dfs(int depth)
{
	int i, j, k, l, d, loc, nowc, noww, md;
	int tbl[128];
	if(depth == m)
	{
		return 1;
	}
	memset(tbl, 0, sizeof(tbl));
	for(i=0, nowc=list[depth]; i<qnum[nowc]; i++)
	{
		noww = queuex[nowc][i];
		loc = queuey[nowc][i];
		l = length[noww];
		md = mdone[noww];
		memset(hash, 0, sizeof(hash));
		for(j=0; j<dnum[l]; j++)
		{
			d = diclist[l][j];
			if(dmatch[d][noww] == md)
			{
				if(!hash[dic[d][loc]])
				{
					tbl[dic[d][loc]]++;
					hash[dic[d][loc]] = 1;
				}
			}
		}
	}
	for(k='a'; k<='z'; k++)
	{
		if(!used[k] && tbl[k] == qnum[nowc])
		{
			used[k] = 1;
			for(i=0, nowc=list[depth]; i<qnum[nowc]; i++)
			{
				noww = queuex[nowc][i];
				loc = queuey[nowc][i];
				l = length[noww];
				md = mdone[noww];
				for(j=0; j<dnum[l]; j++)
				{
					d = diclist[l][j];
					if(dmatch[d][noww] == md && dic[d][loc] == k)
					{
						dmatch[d][noww]++;
					}
				}
				mdone[noww]++;
			}
			key[list[depth]] = k;
			if(dfs(depth+1))
			{
				return 1;
			}
			used[k] = 0;
			for(i=0, nowc=list[depth]; i<qnum[nowc]; i++)
			{
				noww = queuex[nowc][i];
				loc = queuey[nowc][i];
				l = length[noww];
				md = mdone[noww];
				for(j=0; j<dnum[l]; j++)
				{
					d = diclist[l][j];
					if(dmatch[d][noww] == md && dic[d][loc] == k)
					{
						dmatch[d][noww]--;
					}
				}
				mdone[noww]--;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, l;
	char *ptr;
	scanf("%d", &n);
	gets(buf);
	for(i=0; i<n; i++)
	{
		gets(dic[i]);
		l = strlen(dic[i]);
		diclist[l][dnum[l]++] = i;
	}
	key[' '] = ' ';
	while(gets(buf))
	{
		memset(hash, 0, sizeof(hash));
		memset(qnum, 0, sizeof(qnum));
		strcpy(stemp, buf);
		m = o = 0;
		ptr = strtok(stemp, " ");
		do
		{
			l = strlen(ptr);
			if(l > 16)
			{
				break;
			}
			strcpy(ary[o], ptr);
			length[o++] = l;
			for(i=0; ptr[i]; i++)
			{
				if(!hash[ptr[i]])
				{
					hash[ptr[i]] = 1;
					list[m++] = ptr[i];
				}
				queuex[ptr[i]][qnum[ptr[i]]] = o - 1;
				queuey[ptr[i]][qnum[ptr[i]]++] = i;
			}
		}while(ptr=strtok(NULL, " "));
		/*printf("%d\n", m);*/
		if(ptr)
		{
			for(i='a'; i<='z'; i++)
			{
				key[i] = '*';
			}
		}
		else
		{
			memset(dmatch, 0, sizeof(dmatch));
			memset(mdone, 0, sizeof(mdone));
			memset(used, 0, sizeof(used));
			if(!dfs(0))
			{
				for(i='a'; i<='z'; i++)
				{
					key[i] = '*';
				}
			}
		}
		for(ptr=buf; *ptr; ptr++)
		{
			*ptr = key[*ptr];
		}
		puts(buf);
	}
	return 0;
}
