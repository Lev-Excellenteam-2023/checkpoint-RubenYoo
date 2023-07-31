#ifndef SCHOOL_H
#define SCHOOL_H

#define NUMBER_OF_LEVELS 12

#include "Level.h"

struct School
{
    struct Level* levels[NUMBER_OF_LEVELS];
};

#endif