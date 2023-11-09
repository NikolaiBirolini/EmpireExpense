#include "chiffrement.h"
void my_modif(char **in, char **ma, char *s)
{
    char *c = *in;
    int tmp = *c;
    while (*c != '\0')
    {
        tmp = *c;
        if (**ma ==  '\0')
        {
            *ma = s;
        }
        else
        {
            tmp = (tmp + **ma) % 128;
            if (tmp == 0)
                tmp = -128;
            *ma = *ma + 1;
            *c = tmp;
            c = c + 1;
        }
    }
}
void chifrage(char *in, char *ma)
{
    my_modif(&in,&ma,ma);

}

