#include "acount.h"

void cut(char *str, char cutter)
{
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == cutter)
        {
            str[i] = 0;
            return;
        }
        i++;
    }
}

int open_acount(char *test)
{
    if (test[0] == '\0' || test[0] == '\n')
        return 0;
    FILE *acount = fopen("acount.txt", "r");
    char *line = NULL;
    size_t len = 0;
    char *s = test;
    int count  = 0;
    while (*s != ' ')
    {
        count++;
        s = s + 1;
    } 
    s = s + 1;
    char *tmp = calloc(count + 1, sizeof(char));
    strncat(tmp, test,count);
    deschifrage(s, tmp);
    free(tmp);
    while (getline(&line, &len, acount) > 0)
    {
        if (strncmp(line, test, strlen(line) - 1) == 0)
        {
            fclose(acount);
            return 1;
        }
    }
    fclose(acount);
    return 0;
}
