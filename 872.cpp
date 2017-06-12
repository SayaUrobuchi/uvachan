#include <stdio.h>
#include <string.h>

char n, no, in[20], pre[26][20], out[50], check[20], ptr[26];

void permutation(char now)
{
	char i, j, buf, tmp, loc;
	if(now == n)
	{
		no = 0;
		puts(out);
		return;
	}
	loc = now + now;
	for(i=0; i<n; i++)
	{
		if(check[i])
		{
			buf = pre[in[i]][0];
			for(j=1; j<buf; j++)
			{
				tmp = ptr[pre[in[i]][j]];
				if(!check[tmp]) return;
			}
			check[i] = 0;
			out[loc] = in[i] + 65;
			permutation(now + 1);
			check[i] = 1;
		}
	}
}

int main()
{
	int count;
	char i, *tmp, buf[250];
	memset(out, 32, sizeof(out));
	memset(check, 1, sizeof(check));
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		for(n=0; n<26; n++) pre[n][0] = 0;
		gets(buf);
		tmp = strtok(buf, " ");
		while(tmp != NULL)
		{
			pre[tmp[0] - 65][0] = 1;
			tmp = strtok(NULL, " ");
		}
		for(i=0, n=0; i<26; i++)
		{
			if(pre[i][0])
			{
				ptr[i] = n;
				in[n++] = i;
			}
		}
		gets(buf);
		tmp = strtok(buf, " ");
		while(tmp != NULL)
		{
			i = tmp[0] - 65;
			pre[i][pre[i][0]++] = tmp[2] - 65;
			tmp = strtok(NULL, " ");
		}
		no = 1;
		out[n * 2 - 1] = 0;
		permutation(0);
		out[n * 2 - 1] = 32;
		if(no) puts("NO");
		if(count)
		{
			puts("");
			gets(buf);
		}
	}
	return 0;
}
