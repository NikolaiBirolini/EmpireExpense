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

void create_new_char(char *name)
{
	char *line = malloc(1000);
	line[0] = 0;
	int id = find_smalest_valid_id(0);
	if (name == NULL) //pnj
	{
		sprintf (line, "%d 10 none %f %f -1 0 0 0 100 civil todo %s none none todo 0 [] [] none 0 0 [] 0 0" , id, flag->x, flag->y, flag->nom_superieur);
	}
	else //joueur
	{
		sprintf (line, "%d 10 %s %f %f -1 0 0 0 100 civil %s %s none none todo 0 [] [] none 0 0 [] 0 0" , id, name, flag->x, flag->y, name, flag->nom_superieur); 
	}
	struct personnages *s = find_perso_by_name(flag->nom_superieur);
	s = find_first_valid_leader(s);
	if ( s!= NULL)
		s->nb_vassaux += 1;
	list = append_perso(line);
}

struct personnages *croissance_pop()
{
	
	int new = (int)(count_pop(list) * 0.1);
	for (int i = 0; i < new; i++)
		create_new_char(NULL);
	return list;
}
