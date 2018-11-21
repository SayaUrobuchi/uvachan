#include <stdio.h>
#include <string.h>

char str[1001];
int save[1000][1000];

int maximum(int p, int q)
{
	return p>q ? p : q;
}

int calc(int left, int right)
{
	int tmp;
	if(left == right) return 1;
	if(left > right) return 0;
	if(save[left][right] == -1)
	{
		if(str[left] == str[right]) save[left][right] = calc(left + 1, right - 1) + 2;
		else save[left][right] = maximum(calc(left + 1, right), calc(left, right - 1));
	}
	return save[left][right];
}

int main()
{
	int count, len, i, j;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		len = strlen(str);
		for(i=0; i<len; i++)
		  for(j=0; j<len; j++) save[i][j] = -1;
		if(!len) printf("0\n");
		else printf("%d\n", calc(0, len - 1));
	}
	return 0;
}
