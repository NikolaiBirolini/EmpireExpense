#include "shared_var.h"
#include "perso.h"
#include "map_op.h"

char allowed_to_move(struct personnages *perso, float x, float y, float mvx, float mvy);
void collision(void);