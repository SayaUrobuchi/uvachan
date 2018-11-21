#include <stdio.h>
#include <string.h>

char str[1000000], buf[10000], buf2[10000];

void rev()
{
	int i;
	i = strlen(str);
	for(i--; i>-1; i--)
	{
		printf("%c", str[i]);
	}
}

char* p(char* s)
{
	int i;
	char nl[2], t[2];
	buf[0] = 0;
	nl[0] = 10;
	nl[1] = 0;
	t[1] = 0;
	for(i=0; s[i]; i++)
	{
		if(s[i] == '\\')
		{
			strcat(buf, "\\\"");
			i++;
		}
		else if(s[i] == '/' && s[i+1] == 'P')
		{
			strcat(buf, "\\");
			i++;
		}
		else if(s[i] == 10)
		{
			strcat(buf, nl);
		}
		else
		{
			t[0] = s[i];
			strcat(buf, t);
		}
	}
	printf("%s", buf);
	return buf;
}

char* t(char* s)
{
	int i, j;
	for(i=0, j=0; s[i]; i++)
	{
		if(s[i] == 10)
		{
			buf2[j++] = '\\';
			buf2[j++] = 'n';
			printf("\\n");
		}
		else if(s[i] == '"')
		{
			buf2[j++] = '\\';
			buf2[j++] = '"';
			printf("\\\"");
		}
		else
		{
			buf2[j++] = s[i];
			printf("%c", s[i]);
		}
	}
	buf2[j] = 0;
	return buf2;
}

void self(char* s, int type)
{
	char temp[10000];
	if(type)
	{
		strcat(str, p(s));
		strcat(str, "	self(\"");
		printf("	self(\"");
		sprintf(temp, "%s", t(s));
		printf("\", 1);\n");
		strcat(str, temp);
		strcat(str, "\", 1);\n");
	}
	else
	{
		strcat(str, "	self(\"");
		printf("	self(\"");
		sprintf(temp, "%s", t(s));
		printf("\", 0);\n");
		strcat(str, temp);
		strcat(str, "\", 0);\n");
		strcat(str, p(s));
	}
}

int main()
{
	str[0] = 0;
	self("#include <stdio.h>\n#include <string.h>\n\nchar str[1000000], buf[10000], buf2[10000];\n\nvoid rev()\n{\n	int i;\n	i = strlen(str);\n	for(i--; i>-1; i--)\n	{\n		printf(\"%c\", str[i]);\n	}\n}\n\nchar* p(char* s)\n{\n	int i;\n	char nl[2], t[2];\n	buf[0] = 0;\n	nl[0] = 10;\n	nl[1] = 0;\n	t[1] = 0;\n	for(i=0; s[i]; i++)\n	{\n		if(s[i] == '/P/P')\n		{\n			strcat(buf, \"/P/P/P\"\");\n			i++;\n		}\n		else if(s[i] == '/' && s[i+1] == 'P')\n		{\n			strcat(buf, \"/P/P\");\n			i++;\n		}\n		else if(s[i] == 10)\n		{\n			strcat(buf, nl);\n		}\n		else\n		{\n			t[0] = s[i];\n			strcat(buf, t);\n		}\n	}\n	printf(\"%s\", buf);\n	return buf;\n}\n\nchar* t(char* s)\n{\n	int i, j;\n	for(i=0, j=0; s[i]; i++)\n	{\n		if(s[i] == 10)\n		{\n			buf2[j++] = '/P/P';\n			buf2[j++] = 'n';\n			printf(\"/P/Pn\");\n		}\n		else if(s[i] == '\"')\n		{\n			buf2[j++] = '/P/P';\n			buf2[j++] = '\"';\n			printf(\"/P/P/P\"\");\n		}\n		else\n		{\n			buf2[j++] = s[i];\n			printf(\"%c\", s[i]);\n		}\n	}\n	buf2[j] = 0;\n	return buf2;\n}\n\nvoid self(char* s, int type)\n{\n	char temp[10000];\n	if(type)\n	{\n		strcat(str, p(s));\n		strcat(str, \"	self(/P\"\");\n		printf(\"	self(/P\"\");\n		sprintf(temp, \"%s\", t(s));\n		printf(\"/P\", 1);/Pn\");\n		strcat(str, temp);\n		strcat(str, \"/P\", 1);/Pn\");\n	}\n	else\n	{\n		strcat(str, \"	self(/P\"\");\n		printf(\"	self(/P\"\");\n		sprintf(temp, \"%s\", t(s));\n		printf(\"/P\", 0);/Pn\");\n		strcat(str, temp);\n		strcat(str, \"/P\", 0);/Pn\");\n		strcat(str, p(s));\n	}\n}\n\nint main()\n{\n	str[0] = 0;\n", 1);
	self("	puts(\"\");\n	rev();\n	puts("");\n	return 0;\n}", 0);
	puts("");
	rev();
	puts("");
	return 0;
}
