#ifndef INIT_RECIPE_H
#define INIT_RECIPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define GRID_SIZE 3

typedef struct {
    char *name;                      // Recipe name
    char *grid[GRID_SIZE][GRID_SIZE]; // 3x3 crafting grid
    char *result;                    // Crafting result
    int quantity;                     // Quantity of the result
} CraftRecipe;

/**
 * Loads crafting recipes from a given file.
 * @param filename The file containing the crafting recipes.
 * @param recipeCount A pointer to store the number of recipes loaded.
 * @return CraftRecipe structures.
 */
CraftRecipe *loadRecipes(const char *filename, int *recipeCount);

/**
 * Prints a crafting recipe.
 * @param recipe The crafting recipe to print.
 */
void printRecipe(CraftRecipe recipe);

/**
 * @param recipes The array of CraftRecipe structures.
 * @param count The number of recipes in the array.
 */
void freeRecipes(CraftRecipe *recipes, int count);

#endif // INIT_RECIPE_H
