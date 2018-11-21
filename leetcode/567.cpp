int tbl[128];

bool check()
{
	int i;
	for (i='a'; i<='z'; i++)
	{
		if (tbl[i])
		{
			return false;
		}
	}
	return true;
}

bool checkInclusion(char* s1, char* s2) {
	int i, j;
    memset(tbl, 0, sizeof(tbl));
    for (i=0; s1[i]; i++)
    {
    	tbl[s1[i]]--;
    }
    for (i=0; s1[i]&&s2[i]; i++)
    {
    	tbl[s2[i]]++;
    }
    if (s1[i] && !s2[i])
    {
    	return false;
    }
    if (check())
    {
    	return true;
    }
    for (j=i, i=0; s2[j]; i++, j++)
    {
    	tbl[s2[j]]++;
    	tbl[s2[i]]--;
    	if (check())
    	{
    		return true;
    	}
    }
    return false;
}
