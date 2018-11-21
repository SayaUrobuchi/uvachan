bool checkRecord(char* s) {
	int a, l, i;
	a = 0;
	l = 0;
    for (i=0; s[i]; i++)
    {
    	if (s[i] == 'L')
    	{
    		l++;
    		if (l > 2)
    		{
    			return false;
    		}
    	}
    	else
		{
			l = 0;
			if (s[i] == 'A')
	    	{
	    		a++;
	    		if (a > 1)
	    		{
	    			return false;
	    		}
	    	}
    	}
    }
    return true;
}
