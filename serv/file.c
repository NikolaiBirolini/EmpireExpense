#include "file.h"

size_t load_file_as_string(char *path, char **ret)
{
	FILE *f = fopen(path, "r");
	if (f == NULL)
		printf ("error ");
	fseek(f, 0, SEEK_END);
	size_t size_string = ftell(f);
	fseek(f, 0, SEEK_SET);  
	*ret = calloc(size_string,1);
	fread(*ret, size_string, 1, f);
	fclose(f);
	return size_string;
}

