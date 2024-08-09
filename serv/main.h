#pragma once
#define _POSIX_C_SOURCE 200112l
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>

#include "building.h"
#include "perso.h"
#include "net.h"
#include "map_op.h"
#include "req.h"
#include "utile.h"
#include "time.h"
#include "demographie.h"
#include "acount.h"
#include "file.h"
#include "collision.h"