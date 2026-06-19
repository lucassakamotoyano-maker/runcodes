#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define DEBUG(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)

#endif
