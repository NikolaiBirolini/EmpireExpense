#include "acount.h"

char *cut(char *str, char cutter)
{
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == cutter)
        {
            str[i] = 0;
            return str;
        }
        i++;
    }
    return NULL;
}

struct personnages *have_char(char *name)
{
    char espace = -1;
    for (int i = 0; name[i] != 0; i++)
        if (name[i] == ' ')
            espace = i;
    if (espace <= 0)
        return NULL;
    for (struct personnages *l = list; l != NULL; l = l->next)
    {
        if (strncmp(l->nom_de_compte, name, espace-1) == 0)
            return l;
    }
    return NULL;
}


int open_acount(char *test)
{
    if (test[0] == '\0' || test[0] == '\n')
        return 0;
    FILE *acount = fopen("acount.txt", "r");
    char line[110];
    size_t len = 110; 
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
    while (fgets(line, len, acount))
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
