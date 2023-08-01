#ifndef LEVEL_H
#define LEVEL_H

#define NUMBER_OF_CLASSES 10

#include "SchoolClass.h"

struct Level
{
    struct SchoolClass *classes[NUMBER_OF_CLASSES];
    size_t level_number;
};

#endif