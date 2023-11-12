#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include <argp.h>
#include <stdbool.h>

extern struct argp_option options[];

struct arguments {
    char* address;
    char* login;
    char* password;
};

/**
 * Verify if all arguments in the 'args' structure are initialized (not NULL) and meet the requirements.
 * 
 * @param args - The 'arguments' structure containing 'address', 'login', and 'password'.
 * @return true if all arguments are initialized and meet the requirements, false otherwise.
 */
bool areArgumentsInitialized(struct arguments args);

/**
 * Verify if each argument in the 'args' structure is defined (not NULL).
 * 
 * @param args - The 'arguments' structure containing 'address', 'login', and 'password'.
 * @return true if all arguments are defined, false if at least one argument is not defined.
 */
bool verifyEachArgument(struct arguments args);

/**
 * Callback function to process command-line options and arguments using the 'argp' library.
 * 
 * @param key - The option key or code.
 * @param arg - The argument associated with the option.
 * @param state - The state structure used by 'argp'.
 * @return 0 if option processing is successful, an error code otherwise.
 */
extern error_t parse_opt(int key, char *arg, struct argp_state *state);

extern struct argp argp;

#endif /* ARG_PARSE_H */
