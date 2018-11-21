bool isNumber(char* s) {
    int a, aa;
    double b;
    char cc[128], *p;
    if (sscanf(s, "%lf%s", &b, cc) == 1)
    {
        printf("2");
        if (strchr(s, 'x'))
        {
            return false;
        }
        p = strchr(s, 'e');
        if (!p)
        {
            p = strchr(s, 'E');
        }
        if (p)
        {
            *p = 0;
            if (sscanf(p+1, "%d", &a) != 1)
            {
                return false;
            }
            if (sscanf(s, "%lf", &b) != 1)
            {
                return false;
            }
            return true;
        }
        return true;
    }
    return false;
}
