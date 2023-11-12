#include <stdio.h>
#include <stdlib.h>
#include "arg_parse.h"

struct argp_option options[] = {
    {"address", 'a', "", 0, "Specify an address : --address <ip_address>:<port> or -a <ip_address>:<port>", 0},
    {"login", 'l', "", 0, "Specify a login : --login <login> or -l <login>", 0},
    {"password", 'p', "", 0, "Specify a password : --password <password> or -p <password>", 0},
    {0}
};

error_t parse_opt(int key, char *arg, struct argp_state *state) 
{
    struct arguments *arguments = state->input;

    switch (key) {
        case 'a':
            arguments->address = arg;
            break;
        case 'l':
            arguments->login = arg;
            break;
        case 'p':
            arguments->password = arg;
            break;
        case 'h':
            argp_usage(state);
            break;
        case ARGP_KEY_ARG:
            if (state->arg_num >= 3)
            {
              argp_usage(state);
            }
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    
    return 0;
}

struct argp argp = {
    .options = options,
    .parser = parse_opt,
    .args_doc = 0,
    .doc = 0,
};
