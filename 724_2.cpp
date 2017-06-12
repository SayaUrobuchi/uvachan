#include <stdio.h>
#include <string.h>

char str[10000], buf[10000], tmp[10000];

char* c(char* s)
{
	int i, j;
	for(i=0, j=0; s[i]; i++)
	{
		if(s[i] == 10)
		{
			buf[j++] = '\\';
			buf[j++] = 'n';
		}
		else if(s[i] == '"')
		{
			buf[j++] = '\\';
			buf[j++] = '"';
		}
		else
		{
			buf[j++] = s[i];
		}
	}
	buf[j] = 0;
	return buf;
}

char* t(char* s)
{
	int i, j;
	for(i=0, j=0; s[i]; i++)
	{
		if(s[i] == '/' && s[i+1] == 'P')
		{
			tmp[j++] = '\\';
			i++;
		}
		else
		{
			tmp[j++] = s[i];
		}
	}
	tmp[j] = 0;
	return tmp;
}

void p(char* s, int type)
{
	char buf2[10000];
	if(type)
	{
		sprintf(buf2, "%s\np(\"%s\", 1);\n", t(s), c(s));
	}
	else
	{
		sprintf(buf2, "p(\"%s\", 0);\n%s", c(s), t(s));
	}
	strcat(str, buf2);
}

void rev()
{
	int i;
	for(i=0; str[i]; i++)
	{
		printf("%c", str[i]);
	}
	for(i-=2; i>-1; i--)
	{
		printf("%c", str[i]);
	}
}

int main()
{
	p("#include <stdio.h>\n#include <string.h>\n\nchar str[10000], buf[10000], tmp[10000];\n\nchar* c(char* s)\n{\n	int i, j;\n	for(i=0, j=0; s[i]; i++)\n	{\n		if(s[i] == 10)\n		{\n			buf[j++] = '/P/P';\n			buf[j++] = 'n';\n		}\n		else if(s[i] == '\"')\n		{\n			buf[j++] = '/P/P';\n			buf[j++] = '\"';\n		}\n		else\n		{\n			buf[j++] = s[i];\n		}\n	}\n	buf[j] = 0;\n	return buf;\n}\n\nchar* t(char* s)\n{\n	int i, j;\n	for(i=0, j=0; s[i]; i++)\n	{\n		if(s[i] == '/' && s[i+1] == 'P')\n		{\n			tmp[j++] = '/P/P';\nSP"
	"			i++;\n		}\n		else\n		{\n			tmp[j++] = s[i];\n		}\n	}\n	tmp[j] = 0;\n	return tmp;\n}\n\nvoid p(char* s, int type)\n{\n	char buf2[10000];\n	if(type)\n	{\n		sprintf(buf2, \"%s/Pnp(/P\"%s/P\", 1);/Pn\", t(s), c(s));\n	}\n	else\n	{\n		sprintf(buf2, \"p(/P\"%s/P\", 0);/Pn%s\", c(s), t(s));\n	}\n	strcat(str, buf2);\n}\n\nvoid rev()\n{\n	int i;\n	for(i=0; str[i]; i++)\n	{\n		printf(\"%c\", str[i]);\n	}\n	for(i-=2; i>-1; i--)\n	{\n		printf(\"%c\", str[i]);\n	}\n}\n\nint main()\n{\n", 1);
	p("	rev();\n	puts(\"\");\n	return 0;\n}\n", 0);
	rev();
	puts("");
	return 0;
}
