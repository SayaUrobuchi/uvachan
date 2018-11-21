#include <stdio.h>
#include <string.h>

int n, strtail;
char abc[16], space[17];

void recursion(char* last, int depth)
{
	int loc, slen, i;
	char tmp, ch, str[16];
	strcpy(str, last);
	slen = depth * 2 - 2;
	loc = slen;
	ch = depth + 96;
	str[loc] = ch;
	if(depth > n)
	{
		space[slen] = 0;
		printf("%s", space);
		space[slen] = 32;
		printf("writeln(%s)\n", str);
		return;
	}
	if(depth == 1)
	{
		recursion(str, depth + 1);
		return;
	}
	for(i=loc; i>0; i-=2)
	{
		space[slen] = 0;
		printf("%s", space);
		space[slen] = 32;
		if(i == loc)
		{
			printf("if %c < %c then\n", str[i-2], ch);
		}
		else
		{
			printf("else if %c < %c then\n", str[i-2], ch);
		}
		recursion(str, depth + 1);
		tmp = str[i];
		str[i] = str[i-2];
		str[i-2] = tmp;
	}
	space[slen] = 0;
	printf("%s", space);
	space[slen] = 32;
	printf("else\n");
	recursion(str, depth + 1);
}

int main()
{
	int m, i;
	char ans[16];
	scanf("%d", &m);
	strcpy(abc, "a,b,c,d,e,f,g,h");
	strcpy(ans, abc);
	strcpy(space, "                ");
	while(m--)
	{
		scanf("%d", &n);
		strtail = n * 2 - 1;
		abc[strtail] = 0;
		ans[strtail] = 0;
		printf("program sort(input,output);\nvar\n%s : integer;\nbegin\n  readln(%s);\n", abc, abc);
		recursion(ans, 1);
		ans[strtail] = ',';
		abc[strtail] = ',';
		printf("end.\n");
		if(m) printf("\n");
	}
	return 0;
}
