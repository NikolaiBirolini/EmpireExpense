#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <err.h>
#include "clavier.h"
#include "gui.h"
#include "net.h"
#include "perso.h"
#include "control.h"
#include "ordre.h"
#include "ia.h"
#include "map.h"
#include <fcntl.h>
#include "init_sprite.h"
#include "init_gui.h"
#include "chiffrement.h"
#include "pathfinding.h"
#include "init_sound.h"
#include "btree.h"
#include "shared_var.h"
#include "arg_parse.h"
#include <time.h>
#include <sys/time.h>
#include "display.h"
#include "initWorld.h"
#include "graphic_widget/button.h"
#include "graphic_widget/pictureButton.h"
#include "graphic_widget/textBox.h"
#include "graphic_widget/textInfo.h"
#include "graphic_widget/menuSelector.h"
#include "graphic_widget/gauge.h"
#include "graphic_widget/dropDown.h"

void set_pos(SDL_Rect *pos, int x, int y);
void boucle_jeu(int socket, char *name);
char *log_menu(int socket);
int menu_connection();

/**
 * @brief Handles errors and performs cleanup operations.
 *
 * This function is used to handle errors, free dynamically allocated memory,
 * and shut down the SDL library.
 *
 * @param errorCode The error code to be returned at the end of the program.
 *
 * @return N/A (the function exits the program with the specified error code).
 */
void handleErrorsAndCleanup(int errorCode);


/**
 * @brief Communicates with a server over a socket and waits for a response.
 *
 * This function sends data to a server using the provided socket and then waits for
 * a response. It checks the response and handles errors accordingly. If the response
 * is 'p', it continues waiting; if the response is 'o', the function returns true.
 * If there is an error during communication or if the response is not 'o', it handles
 * the error and return false.
 *
 * @param socket The socket to communicate with the server.
 * @param to_send The data to send to the server.
 * @param size The size of the data to send.
 * @param flags The flags to control the behavior of the send function.
 *
 */
bool communicateWithServer(int socket, char* to_send, int size, int flags);


bool sendLoginDataToServer(char *login, char *password, int socket, int size, int flags);

