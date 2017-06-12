#include <stdio.h>

int main()
{
	while(gets(str))
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		sscanf(str, "%c%d%d%d", &ch, &i, &j, &k);
		if(ch == 'A')
		{
			ptr = avenue[i];
		}
		else
		{
			ptr = street[i];
		}
		for(; j<=k; j++)
		{
			ptr[j] = 1;
		}
		ptr[j] = 1;
	}
	while(gets(str))
	{
		sscanf(str, "%s%d%s%d", s1, &qn[0], s2, &en);
		if(!strcmp(s1, s2) && qn[0] == en)
		{
			printf("1\n");
		}
		else
		{
			memset(chk, 0, sizeof(chk));
			qtype[0] = gettype(s1[0]);
			sscanf(s1+1, "%d", &qnum[0]);
			qdis[0] = 1;
			chk[qtype[0]][qnum[0]][qn[0]] = 1;
			endtype = gettype(s2[0]);
			sscanf(s2+1, "%d", &endway);
		}
	}
	return 0;
}
