#include "deschiffrement.h"
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

            if (tmp == -128)
                tmp = 0;
            tmp = (tmp - **ma);
            if (tmp < 0)
                tmp = tmp + 128;
            *ma = *ma + 1;
            *c = tmp;
            c = c + 1;
        }
    }
}
void deschifrage(char *in, char *ma)
{
    my_modif(&in,&ma,ma);

}

