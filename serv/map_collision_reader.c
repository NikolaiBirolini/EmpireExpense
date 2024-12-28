#include "map_collision_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MapElement* parseCollisionMap(const char* filename, int* elementCount) 
{
    FILE* file = fopen(filename, "r");
    if (!file) 
    {
        perror("Erreur d'ouverture du fichier");
        return NULL;
    }

    char line[256];
    int lineIndex = 0, x_found = -1, y_found = -1;
    MapElement* elements = NULL;
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0'; 
        
        for (int i = 0; line[i] != '\0'; ++i) 
        {
            if (line[i] == 'x') 
            {
                x_found = i;
                y_found = lineIndex;
            }
        }
        lineIndex++;
    }

    if (x_found == -1 || y_found == -1) 
    {
        printf("Aucun 'x' trouvé dans le fichier.\n");
        fclose(file);
        return NULL;
    }

    rewind(file);
    lineIndex = 0;

    while (fgets(line, sizeof(line), file)) 
    {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0'; 
        
        for (int i = 0; line[i] != '\0'; ++i) {
            if (line[i] == '|' || line[i] == 'w' || line[i] == 'x') 
            {
                elements = realloc(elements, (count + 1) * sizeof(MapElement));
                elements[count].character = line[i];
                elements[count].relative_x = i - x_found;
                elements[count].relative_y = y_found - lineIndex; 
                count++;  
            }
        }
        lineIndex++;
    }

    fclose(file);
    *elementCount = count;
    return elements;
}