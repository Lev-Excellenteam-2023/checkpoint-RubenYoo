#ifndef LEVEL_H
#define LEVEL_H

#include "SchoolClass.h"

struct Level
{
    struct SchoolClass classes[10];
    int level_number;
};

#endif