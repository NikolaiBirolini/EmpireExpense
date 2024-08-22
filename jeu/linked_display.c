#include "linked_display.h"

void sortedInsert(struct to_disp* new_node)
{
    struct to_disp* current;
    /* Special case for the head end */
    if (list_disp == NULL || list_disp->y > (int)new_node->y || (list_disp->x > new_node->x && (int)list_disp->y == (int)new_node->y)) {
        new_node->next = list_disp;
        list_disp = new_node;
    }
    else {
        /* Locate the node before the
 point of insertion */
        current = list_disp;
        while (current->next != NULL && ((int)new_node->y > (int)current->next->y || (new_node->x > current->next->x && (int)new_node->y == (int)current->next->y))) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

struct to_disp* deleteKey(int id) 
{ 
    if (!list_disp) 
        return list_disp; 
    // Until the head data is equal to the key move the head 
    // pointer 
    while (list_disp && list_disp->id == id) 
        list_disp = list_disp->next; 
    struct to_disp *curr = list_disp, *prev = NULL; 
    while (curr) { 
        if (curr->id == id) 
            prev->next = curr->next; 
        else
            prev = curr; 
        curr = curr->next; 
    } 
    return list_disp; 
} 