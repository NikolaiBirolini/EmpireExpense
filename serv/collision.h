#include "shared_var.h"
#include "perso.h"
#include "map_op.h"

float allowed_to_move(struct personnages *perso, float x, float y, float mvx, float mvy);
void collision(void);
extern int *ground_altitude;
