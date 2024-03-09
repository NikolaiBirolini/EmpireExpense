#include "formation.h"

void square(struct linked_list *selected ,float x, float y)
{
    int nbOfSelected = getSizeLinkedList(selected);

    double side_length = sqrt(nbOfSelected);

    double half_side_length = side_length / 2.0;

    // Distribute point to have a square
    int pointIndex = 0;
    for (struct linked_list* current = selected; current != NULL; current = current->next) 
    {
        if (pointIndex == 0) {
            current->p->ordrex = x - half_side_length;
            current->p->ordrey = y - half_side_length;
        } else if (pointIndex == 1) {
            current->p->ordrex = x + half_side_length;
            current->p->ordrey = y - half_side_length;
        } else if (pointIndex == 2) {
            current->p->ordrex = x + half_side_length;
            current->p->ordrey = y + half_side_length;
        } else if (pointIndex == 3) {
            current->p->ordrex = x - half_side_length;
            current->p->ordrey = y + half_side_length;
        } else {
           // // Remaining points
           // double remaining = nbOfSelected - 4;
           // double increment = side_length / remaining;
//
           // int sideIndex = pointIndex - 3;
           // if (sideIndex < 2 * side_length) {
           //     current->p->x = x + half_side_length;
           //     current->p->y = y - half_side_length + increment * (sideIndex - side_length);
           // } else if (sideIndex < 3 * side_length) {
           //     current->p->x = x + half_side_length - increment * (sideIndex - 2 * side_length);
           //     current->p->y = y + half_side_length;
           // } else {
           //     current->p->x = x - half_side_length;
           //     current->p->y = y + half_side_length - increment * (sideIndex - 3 * side_length);
           // }
        }
        pointIndex++;
    }
    

}