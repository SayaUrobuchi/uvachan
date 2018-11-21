#include <stdio.h>
#include <string.h>

int n, k;
char fornoun[5][10] = {"man", "dog", "fish", "computer", "waves"};
char fortverb[4][10] = {"struck", "saw", "bit", "took"};
char foriverb[4][10] = {"slept", "jumped", "walked", "swam"};
char forarticle[2][10] = {"the", "a"};
char foradjective[4][10] = {"green", "small", "rabid", "quick"};
char foradverb[3][12] = {"nearly", "suddenly", "restlessly"};
char forpreposition[3][10] = {"on", "over", "through"};
char buf[2008];
char ary[10000][12];

/* <sentence> ::= <trans-sentence> | <sentence> ::= <intrans-sentence>
<trans-sentence> ::= <subject> <verb-phrase> <object> <prep-phrase>
<intrans-sentence> ::= <subject> <intrans-verb-phrase> <prep-phrase>
<subject> ::= <noun-phrase>
<object> ::= <noun-phrase>
<noun-phrase> ::= <article> <modified-noun>
<modified-noun> ::= <noun> | <modifier> <noun>
<modifier> ::= <adjective> | <adverb> <adjective>
<verb-phrase> ::= <trans-verb> | <adverb> <trans-verb>
<intrans-verb-phrase> ::= <intrans-verb> | <adverb> <intrans-verb>
<prep-phrase> ::= <preposition> <noun-phrase> | <empty>
<noun> ::= man | dog | fish | computer | waves
<trans-verb> ::= struck | saw | bit | took
<intrans-verb> ::= slept | jumped | walked | swam
<article> ::= the | a
<adjective> ::= green | small | rabid | quick
<adverb> ::= nearly | suddenly | restlessly
<preposition> ::= on | over | through
<empty> ::= ""*/

void sentence();
void trans_sentence();
void intrans_sentence();
void subject();
void object();
void noun_phrase();
void modified_noun();
void modifier();
void verb_phrase();
void intrans_verb_phrase();
void prep_phrase();
void noun();
void trans_verb();
void intrans_verb();
void article();
void adjective();
void adverb();
void preposition();
void empty();

void sentence()
{
	int choice;
	choice = ++k % 2;
	if(choice)
	{
		intrans_sentence();
	}
	else
	{
		trans_sentence();
	}
}

void trans_sentence()
{
	subject();
	verb_phrase();
	object();
	prep_phrase();
}

void intrans_sentence()
{
	subject();
	intrans_verb_phrase();
	prep_phrase();
}

void subject()
{
	noun_phrase();
}

void object()
{
	noun_phrase();
}

void noun_phrase()
{
	article();
	modified_noun();
}

void modified_noun()
{
	int choice;
	choice = ++k % 2;
	if(choice)
	{
		modifier();
		noun();
	}
	else
	{
		noun();
	}
}

void modifier()
{
	int choice;
	choice = ++k % 2;
	if(choice)
	{
		adverb();
		adjective();
	}
	else
	{
		adjective();
	}
}

void verb_phrase()
{
	int choice;
	choice = ++k % 2;
	if(choice)
	{
		adverb();
		trans_verb();
	}
	else
	{
		trans_verb();
	}
}

void intrans_verb_phrase()
{
	int choice;
	choice = ++k % 2;
	if(choice)
	{
		adverb();
		intrans_verb();
	}
	else
	{
		intrans_verb();
	}
}

void prep_phrase()
{
	int choice;
	choice = ++k % 2;
	if(choice)
	{
		empty();
	}
	else
	{
		preposition();
		noun_phrase();
	}
}

void noun()
{
	int choice;
	choice = ++k % 5;
	strcpy(ary[n++], fornoun[choice]);
}

void trans_verb()
{
	int choice;
	choice = ++k % 4;
	strcpy(ary[n++], fortverb[choice]);
}

void intrans_verb()
{
	int choice;
	choice = ++k % 4;
	strcpy(ary[n++], foriverb[choice]);
}

void article()
{
	int choice;
	choice = ++k % 2;
	strcpy(ary[n++], forarticle[choice]);
}

void adjective()
{
	int choice;
	choice = ++k % 4;
	strcpy(ary[n++], foradjective[choice]);
}

void adverb()
{
	int choice;
	choice = ++k % 3;
	strcpy(ary[n++], foradverb[choice]);
}
void preposition()
{
	int choice;
	choice = ++k % 3;
	strcpy(ary[n++], forpreposition[choice]);
}

void empty()
{
	/*strcpy(ary[n++], "");*/
}

int main()
{
	/*freopen("1.txt", "w", stdout);
	while(gets(buf))
	{
		strtok(buf+1, ">");
		printf("\t\telse if(!strcmp(buf, \"%s\"))\n\t\t{\n\t\t\t%s();\n\t\t}\n", buf+1, buf+1);
	}*/
	int c, i;
	c = 0;
	while(scanf("%s", buf) == 1)
	{
		n = 0;
		if(!strcmp(buf, "sentence"))
		{
			sentence();
		}
		else if(!strcmp(buf, "trans-sentence"))
		{
			trans_sentence();
		}
		else if(!strcmp(buf, "intrans-sentence"))
		{
			intrans_sentence();
		}
		else if(!strcmp(buf, "subject"))
		{
			subject();
		}
		else if(!strcmp(buf, "object"))
		{
			object();
		}
		else if(!strcmp(buf, "noun-phrase"))
		{
			noun_phrase();
		}
		else if(!strcmp(buf, "modified-noun"))
		{
			modified_noun();
		}
		else if(!strcmp(buf, "modifier"))
		{
			modifier();
		}
		else if(!strcmp(buf, "verb-phrase"))
		{
			verb_phrase();
		}
		else if(!strcmp(buf, "intrans-verb-phrase"))
		{
			intrans_verb_phrase();
		}
		else if(!strcmp(buf, "prep-phrase"))
		{
			prep_phrase();
		}
		else if(!strcmp(buf, "noun"))
		{
			noun();
		}
		else if(!strcmp(buf, "trans-verb"))
		{
			trans_verb();
		}
		else if(!strcmp(buf, "intrans-verb"))
		{
			intrans_verb();
		}
		else if(!strcmp(buf, "article"))
		{
			article();
		}
		else if(!strcmp(buf, "adjective"))
		{
			adjective();
		}
		else if(!strcmp(buf, "adverb"))
		{
			adverb();
		}
		else if(!strcmp(buf, "preposition"))
		{
			preposition();
		}
		else if(!strcmp(buf, "empty"))
		{
			empty();
		}
		if(n)
		{
			printf("%s", ary[0]);
			for(i=1; i<n; i++)
			{
				printf(" %s", ary[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
