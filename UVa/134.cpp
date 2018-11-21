#include <stdio.h>
#include <string.h>

int n;
char ary[100000][50];
int len[100000];

int predstring(int, int), predname(int, int);

int son(char ch)
{
	return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
}

int a(int now)
{
	return now <= n && len[now] == 1 && !son(ary[now][0]);
}

int mod(int now)
{
	return now <= n && len[now] == 2 && ary[now][0] == 'g' && !son(ary[now][1]);
}

int ba(int now)
{
	return now <= n && len[now] == 2 && ary[now][0] == 'b' && !son(ary[now][1]);
}

int da(int now)
{
	return now <= n && len[now] == 2 && ary[now][0] == 'd' && !son(ary[now][1]);
}

int la(int now)
{
	return now <= n && len[now] == 2 && ary[now][0] == 'l' && !son(ary[now][1]);
}

int name(int now)
{
	return now <= n && son(ary[now][len[now]-1]);
}

int preda(int now)
{
	return now <= n && len[now] == 5 && son(ary[now][0]) && son(ary[now][3]) && !son(ary[now][4]) && (son(ary[now][1]) ^ son(ary[now][2]));
}

int verbpred(int left, int right)
{
	return left <= right && mod(left) && predstring(left+1, right);
}

int statement(int left, int right)
{
	int i, j;
	if(left > right)
	{
		return 0;
	}
	for(i=left+1; i<right; i++)
	{
		for(j=i+1; j<right; j++)
		{
			if(predname(left, i-1) && verbpred(i, j-1) && predname(j, right))
			{
				return 1;
			}
		}
		if(predname(left, i-1) && verbpred(i, right))
		{
			return 1;
		}
	}
	return 0;
}

int predstring(int left, int right)
{
	if(left > right)
	{
		return 0;
	}
	else if(left == right)
	{
		return preda(left);
	}
	else
	{
		return predstring(left, right-1) && preda(right);
	}
}

int predname(int left, int right)
{
	if(left > right)
	{
		return 0;
	}
	else if(left == right)
	{
		return name(left);
	}
	else
	{
		return la(left) && predstring(left+1, right);
	}
}

int preds(int left, int right)
{
	int i;
	if(left > right)
	{
		return 0;
	}
	if(predstring(left, right))
	{
		return 1;
	}
	for(i=left+1; i<right; i++)
	{
		if(preds(left, i-1) && a(i) && predstring(i+1, right))
		{
			return 1;
		}
	}
	return 0;
}

int predclaim(int left, int right)
{
	int i;
	if(da(left))
	{
		return preds(left+1, right);
	}
	for(i=left+1; i<right; i++)
	{
		if(predname(left, i-1) && ba(i) && preds(i+1, right))
		{
			return 1;
		}
	}
	return 0;
}

int sentence(int left, int right)
{
	return statement(left, right) || predclaim(left, right);
}

int main()
{
	n = 0;
	while(scanf("%s", ary[n]) == 1)
	{
		if(!n && !strcmp(ary[0], "#"))
		{
			break;
		}
		len[n] = strlen(ary[n]);
		if(ary[n][len[n]-1] == '.')
		{
			ary[n][--len[n]] = 0;
			if(sentence(0, n))
			{
				printf("Good\n");
			}
			else
			{
				printf("Bad!\n");
			}
			n = 0;
		}
		else
		{
			n++;
		}
	}
	return 0;
}
