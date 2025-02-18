#include "init_recipe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define GRID_SIZE 3

void freeRecipes(CraftRecipe *recipes, int count) {
    for (int i = 0; i < count; i++) {
        free(recipes[i].name);
        free(recipes[i].result);
        for (int y = 0; y < GRID_SIZE; y++)
            for (int x = 0; x < GRID_SIZE; x++)
                free(recipes[i].grid[y][x]);
    }
    free(recipes);
}

CraftRecipe *loadRecipes(const char *filename, int *recipeCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    CraftRecipe *recipes = NULL;
    char line[MAX_LINE];
    *recipeCount = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        if (line[0] == '#' || strlen(line) == 0) continue;

        // Allocate a new recipe
        recipes = realloc(recipes, (*recipeCount + 1) * sizeof(CraftRecipe));
        CraftRecipe *recipe = &recipes[*recipeCount];
        memset(recipe, 0, sizeof(CraftRecipe));

        // Read the recipe name
        recipe->name = malloc(strlen(line) + 1);
        if (recipe->name) strcpy(recipe->name, line);

        // Read the 3x3 crafting grid
        for (int y = 0; y < GRID_SIZE; y++) {
            if (!fgets(line, sizeof(line), file)) break;
            line[strcspn(line, "\n")] = 0;

            char *token = strtok(line, " ");
            for (int x = 0; x < GRID_SIZE && token; x++) {
                if (strcmp(token, ".") == 0) {
                    recipe->grid[y][x] = NULL;
                } else {
                    recipe->grid[y][x] = malloc(strlen(token) + 1);
                    if (recipe->grid[y][x]) strcpy(recipe->grid[y][x], token);
                }
                token = strtok(NULL, " ");
            }
        }
        fgets(line, sizeof(line), file);
        if (strstr(line, "=>") == NULL) continue;

        // Read the result
        if (!fgets(line, sizeof(line), file)) continue;
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, " ");
        recipe->quantity = atoi(token);
        token = strtok(NULL, "");
        if (token) {
            recipe->result = malloc(strlen(token) + 1);
            if (recipe->result) strcpy(recipe->result, token);
        }

        (*recipeCount)++;
    }

    fclose(file);
    return recipes;
}

void printRecipe(CraftRecipe recipe) {
    printf("\n%s:\n", recipe.name);
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            printf("%s", recipe.grid[y][x]); 
            if (x < GRID_SIZE - 1) printf(" ");
        }
        printf("\n");
    }
    printf("=> %d %s\n", recipe.quantity, recipe.result);
}
