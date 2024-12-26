#include "map_op.h"

void save_map(void)
{
	FILE *file = fopen("map.txt","w");
	char order[100000]; //TODO
	fprintf(file, "%s", order);
	fclose(file);
}

struct personnages *init_map(void)
{
    FILE *acount = fopen("map.txt", "r+");
    char line[500];
    size_t len = 500;
    while (fgets(line, len, acount))
    {
        if (line[0] == '1')
            append_building(line);
        else
            append_perso(line);
    }

    return list;
}

