#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int l;
int next[30][30], prev[30][30];
int conr[30][30][100], cons[30][30][100];
int num[30][30];
int qr[700], qs[700];
int froms[30][30], fromr[30][30];
int maxs[30][30];
int queuer[4][700], queues[4][700];
int step[4][700];
int len[4];
char str[1000];

void backtracing(int r, int s, int st)
{
	if(froms[r][s])
	{
		if(fromr[r][s])
		{
			backtracing(fromr[r][s], froms[r][s], st);
		}
		else
		{
			backtracing(r, froms[r][s], st);
		}
	}
	else
	{
		printf("%3d: %c%c", st, r+64, s+96);
		return;
	}
	if(fromr[r][s])
	{
		printf("=%c", r+64);
	}
	putchar(s+96);
}

void dfs(int r, int s)
{
	int i, tr, ts;
	for(i=0; i<num[r][s]; i++)
	{
		if(!maxs[tr=conr[r][s][i]][ts=cons[r][s][i]])
		{
			maxs[tr][ts] = 1;
			qr[l] = tr;
			qs[l++] = ts;
			dfs(tr, ts);
		}
	}
}

int main()
{
	int n, i, j, k, p, q, r, s, ch, sr, ss, er, es, tr, ts, st, now, last, temp, temp2;
	while(scanf("%d", &n) == 1)
	{
		memset(next, 0, sizeof(next));
		memset(prev, 0, sizeof(prev));
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++)
		{
			scanf("%s", str);
			ch = str[0] - 64;
			for(j=2, last=0; ; )
			{
				now = str[j] - 96;
				if(last)
				{
					next[ch][last] = now;
					prev[ch][now] = last;
				}
				if(str[j+1] == '=')
				{
					j += 2;
					temp = str[j++] - 64;
					temp2 = str[j] - 96;
					conr[ch][now][num[ch][now]] = temp;
					cons[ch][now][num[ch][now]++] = temp2;
					conr[temp][temp2][num[temp][temp2]] = ch;
					cons[temp][temp2][num[temp][temp2]++] = now;
				}
				if(!str[++j])
				{
					break;
				}
				if(str[j] == str[2])
				{
					next[ch][now] = str[2] - 96;
					prev[ch][str[2]-96] = now;
					break;
				}
				last = now;
			}
		}
		memset(maxs, 0, sizeof(maxs));
		for(i=1; i<27; i++)
		{
			for(j=1; j<27; j++)
			{
				if(num[i][j] && !maxs[i][j])
				{
					maxs[i][j] = 1;
					l = 1;
					qr[0] = i;
					qs[0] = j;
					dfs(i, j);
					for(p=0; p<l; p++)
					{
						r = qr[p];
						s = qs[p];
						num[r][s] = 0;
						for(q=0; q<l; q++)
						{
							if(p != q)
							{
								tr = qr[q];
								ts = qs[q];
								conr[r][s][num[r][s]] = tr;
								cons[r][s][num[r][s]++] = ts;
							}
						}
					}
				}
			}
		}
		while(scanf("%s", str) == 1)
		{
			if(str[0] == '#')
			{
				break;
			}
			memset(len, 0, sizeof(len));
			memset(fromr, 0, sizeof(fromr));
			memset(froms, 0, sizeof(froms));
			memset(maxs, 1, sizeof(maxs));
			sr = str[0] - 64;
			ss = str[1] - 96;
			er = str[2] - 64;
			es = str[3] - 96;
			queuer[0][0] = sr;
			queues[0][0] = ss;
			step[0][len[0]++] = 0;
			maxs[sr][ss] = 0;
			for(i=0; len[0]||len[1]||len[2]||len[3]; i++)
			{
				if(i > 3)
				{
					i -= 4;
				}
				for(j=0; j<len[i]; j++)
				{
					r = queuer[i][j];
					s = queues[i][j];
					st = step[i][j];
					/*printf("%c %c %d\n", r+64, s+96, st);*/
					if(st != maxs[r][s])
					{
						continue;
					}
					if(r == er && s == es)
					{
						break;
					}
					st++;
					tr = r;
					ts = next[r][s];
					if(st < maxs[tr][ts])
					{
						fromr[tr][ts] = 0;
						froms[tr][ts] = s;
						maxs[tr][ts] = st;
						temp = st % 4;
						queuer[temp][len[temp]] = tr;
						queues[temp][len[temp]] = ts;
						step[temp][len[temp]++] = st;
					}
					ts = prev[r][s];
					if(st < maxs[tr][ts])
					{
						fromr[tr][ts] = 0;
						froms[tr][ts] = s;
						maxs[tr][ts] = st;
						temp = st % 4;
						queuer[temp][len[temp]] = tr;
						queues[temp][len[temp]] = ts;
						step[temp][len[temp]++] = st;
					}
					st += 2;
					for(k=0; k<num[r][s]; k++)
					{
						tr = conr[r][s][k];
						ts = cons[r][s][k];
						if(st < maxs[tr][ts])
						{
							fromr[tr][ts] = r;
							froms[tr][ts] = s;
							maxs[tr][ts] = st;
							temp = st % 4;
							queuer[temp][len[temp]] = tr;
							queues[temp][len[temp]] = ts;
							step[temp][len[temp]++] = st;
						}
					}
				}
				if(j<len[i])
				{
					break;
				}
				len[i] = 0;
			}
			backtracing(r, s, st);
			putchar(10);
		}
	}
	return 0;
}
