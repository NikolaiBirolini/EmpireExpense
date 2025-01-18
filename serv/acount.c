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
    char line[220];
    size_t len = 220; 
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
        int i = 0;
        uint8_t nb_space = 0;
        while (line[i] == test[i])
        {
            i += 1;
            if (line[i] == ' ')
            {
                nb_space += 1;
                if (nb_space == 2)
                {
                    fclose(acount);
                    return 1;
                }
            }
        }
    }
    fclose(acount);
    return 0;
}
