#include "demographie.h"

int count_pop()
{
	int i = 0;
	struct personnages *parcour = list;
	while (parcour != NULL)
	{
		parcour = parcour->next;
		i++;
	}
	return i;
}