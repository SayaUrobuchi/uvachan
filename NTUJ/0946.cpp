#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int slen;
int num_loc[1005], num[1005], up_ptr[1005], down_ptr[1005];
int down_sig[1005], down_dis[1005], up_sig[1005], up_dis[1005];
int down_table[1005], up_table[1005];
int posloc[1005], negloc[1005], sign[2005], sign_type[2005], ptr[2005];
int q_up[3000005], q_down[3000005];
int inq[1005][1005], score[1005][1005];

int sign_comp(const void *p, const void *q)
{
	int pp, qq;
	pp = *(int*)p;
	qq = *(int*)q;
	if(sign[pp] > sign[qq])
	{
		return 1;
	}
	return -1;
}

int down_ptr_comp(const void *p, const void *q)
{
	int pp, qq;
	pp = *(int*)p;
	qq = *(int*)q;
	if(down_dis[pp] == -1)
	{
		return 1;
	}
	if(down_dis[qq] == -1)
	{
		return -1;
	}
	if(down_dis[pp] < down_dis[qq])
	{
		return -1;
	}
	return 1;
}

int up_ptr_comp(const void *p, const void *q)
{
	int pp, qq;
	pp = *(int*)p;
	qq = *(int*)q;
	if(up_dis[pp] == -1)
	{
		return 1;
	}
	if(up_dis[qq] == -1)
	{
		return -1;
	}
	if(up_dis[pp] < up_dis[qq])
	{
		return -1;
	}
	return 1;
}

int main()
{
	int n, m, o, i, j, k, p, q, t, c, up, down, sc, stemp, flag, ans;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(n == 0 && m == 0 && o == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &num_loc[i], &num[i]);
			up_ptr[i] = i;
			down_ptr[i] = i;
		}
		slen = 0;
		for(i=0; i<m; i++)
		{
			scanf("%d", &posloc[i]);
			sign[slen] = posloc[i];
			sign_type[slen] = 0;
			ptr[slen] = slen;
			slen++;
		}
		for(i=0; i<o; i++)
		{
			scanf("%d", &negloc[i]);
			sign[slen] = negloc[i];
			sign_type[slen] = 1;
			ptr[slen] = slen;
			slen++;
		}
		qsort(ptr, slen, sizeof(int), sign_comp);
		for(i=0; i<n; i++)
		{
			for(p=0, q=slen-1, t=-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(sign[ptr[c]] < num_loc[i])
				{
					p = c+1;
					t = c;
				}
				else
				{
					q = c-1;
				}
			}
			if(t == -1)
			{
				down_sig[i] = -1;
				down_dis[i] = -1;
			}
			else
			{
				down_sig[i] = ptr[t];
				down_dis[i] = num_loc[i] - sign[ptr[t]];
			}
			if(t+1 >= slen)
			{
				up_sig[i] = -1;
				up_dis[i] = -1;
			}
			else
			{
				up_sig[i] = ptr[t+1];
				up_dis[i] = sign[ptr[t+1]] - num_loc[i];
				//printf("aaaaaa %d\n", up_dis[i]);
			}
		}
		qsort(down_ptr, n, sizeof(int), down_ptr_comp);
		qsort(up_ptr, n, sizeof(int), up_ptr_comp);
		for(i=0; i<n; i++)
		{
			down_table[down_ptr[i]] = i;
			up_table[up_ptr[i]] = i;
		}
		q_up[0] = 0;
		q_down[0] = 0;
		memset(inq, 0, sizeof(inq));
		inq[0][0] = 1;
		score[0][0] = 0;
		ans = 0;
		for(i=0, j=1; i<j; i++)
		{
			up = q_up[i];
			down = q_down[i];
			sc = score[down][up];
			//printf("%d %d %d: score %d\n", i, down, up, sc);
			for(k=down, stemp=0; k<n; k++)
			{
				//printf("!! %d %d %d\n", k, down_ptr[k], down_sig[down_ptr[k]]);
				if(down_dis[down_ptr[k]] == -1)
				{
					break;
				}
				if(up_table[down_ptr[k]] < up)
				{
					continue;
				}
				if(down_dis[down_ptr[k]] != down_dis[down_ptr[down]])
				{
					break;
				}
				flag = 1;
				if(sign_type[down_sig[down_ptr[k]]])
				{
					flag = -1;
				}
				//printf("stemp %d %d\n", flag, num[down_ptr[k]]);
				stemp += num[down_ptr[k]] * flag;
			}
			if(k != down)
			{
				if(inq[k][up] == 0 || (inq[k][up] && score[k][up] < sc + stemp))
				{
					score[k][up] = sc + stemp;
					//printf("sc %d, stemp %d, score[k][up] = %d, add (%d, %d)\n", sc, stemp, score[k][up], k, up);
					if(sc + stemp > ans)
					{
						ans = sc + stemp;
					}
					if(inq[k][up] == 0)
					{
						inq[k][up] = 1; 
						q_up[j] = up;
						q_down[j] = k;
						j++;
					}
				}
			}
			for(k=up, stemp=0; k<n; k++)
			{
				if(up_dis[up_ptr[k]] == -1)
				{
					break;
				}
				if(down_table[up_ptr[k]] < down)
				{
					continue;
				}
				if(up_dis[up_ptr[k]] != up_dis[up_ptr[up]])
				{
					break;
				}
				flag = 1;
				if(sign_type[up_sig[up_ptr[k]]])
				{
					flag = -1;
				}
				stemp += num[up_ptr[k]] * flag;
			}
			if(k != up)
			{
				if(inq[down][k] == 0 || (inq[down][k] && score[down][k] < sc + stemp))
				{
					score[down][k] = sc + stemp;
					if(sc + stemp > ans)
					{
						ans = sc + stemp;
						//printf("ans %d %d: %d\n", down, k, ans);
					}
					if(inq[down][k] == 0)
					{
						inq[down][k] = 1; 
						q_up[j] = k;
						q_down[j] = down;
						j++;
					}
				}
			}
			inq[up][down] = 0;
		}
		printf("%d\n", ans); 
	}
	return 0;
}


