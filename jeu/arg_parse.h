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

bool areArgumentsInitialized(struct arguments args);

bool verifyEachArgument(struct arguments args);

extern error_t parse_opt(int key, char *arg, struct argp_state *state);

extern struct argp argp;

#endif /* ARG_PARSE_H */
