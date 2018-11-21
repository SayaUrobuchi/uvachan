#include <stdio.h>
#include <string.h>

int ary[1000], left[1000], temp[1000];
char str[1000], top[1000];

int main()
{
	int i, j, k, l, p, pos, lim, len, alen, head;
	while(gets(str))
	{
		for(i=0; str[i]; i++)
		{
			ary[i] = str[i] - 48;
		}
		for(pos=i; i<=pos+102; i++)
		{
			ary[i] = 0;
		}
		lim = i;
		for(i=1-pos%2, len=0, alen=0, head=0; i<lim; i+=2, len++, alen++)
		{
			/*printf("%d%d%d\n", ary[0], ary[1], ary[2]);*/
			for(; head<i&&ary[head]==0; head++);
			for(j=1; j<10; j++)
			{
				left[len] = j;
				for(k=len, temp[k+1]=0; k>=0; k--)
				{
					temp[k+1] += left[k] * j;
					if(temp[k+1] >= 10)
					{
						temp[k] = temp[k+1] / 10;
						temp[k+1] %= 10;
					}
					else
					{
						temp[k] = 0;
					}
				}
				l = len + (temp[0] != 0) + 1;
				/*if(i<10)printf("%d %d %d %d\n", l, i-head+1, i, head);*/
				if(l > (i-head+1))
				{
					break;
				}
				else if(l == (i-head+1))
				{
					for(k=(temp[0]==0), p=head; k<=len+1; k++, p++)
					{
						if(temp[k] != ary[p])
						{
							break;
						}
					}
					if(k <= len+1 && temp[k] > ary[p])
					{
						break;
					}
				}
			}
			left[len] = --j;
			top[alen] = j + 48;
			for(k=len, temp[k+1]=0; k>=0; k--)
			{
				temp[k+1] += left[k] * j;
				if(temp[k+1] >= 10)
				{
					temp[k] = temp[k+1] / 10;
					temp[k+1] %= 10;
				}
				else
				{
					temp[k] = 0;
				}
			}
			/*printf("L:");
			for(k=0; k<=len; k++)
			{
				printf("%d", left[k]);
			}
			printf("\n");
			printf("T:");
			for(k=0; k<=len+1; k++)
			{
				printf("%d", temp[k]);
			}
			printf("\n");*/
			for(k=len+1, p=i; p>=head; k--, p--)
			{
				ary[p] -= temp[k];
				if(ary[p] < 0)
				{
					ary[p] += 10;
					ary[p-1]--;
				}
			}
			left[len] += j;
			for(k=len; k>=0; k--)
			{
				if(left[k] >= 10)
				{
					if(k == 0)
					{
						memmove(left+1, left, (++len)*sizeof(int));
						/*printf("F!!\n");*/
						left[k+1] -= 10;
						left[k] = 1;
					}
					else
					{
						left[k] -= 10;
						left[k-1]++;
					}
				}
			}
		}
		if(top[alen-1] >= '5')
		{
			top[alen-2]++;
		}
		top[alen] = 0;
		pos++;
		pos >>= 1;
		/*printf("%d %d\n", alen, pos);
		for(i=0; i<alen; i++)
		{
			printf("%c", *(top+i+pos));
		}
		printf("%s\n", top);*/
		printf("%.*s.%.*s\n", pos, top, 50, top+pos);
	}
	return 0;
}
