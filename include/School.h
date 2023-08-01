#ifndef SCHOOL_H
#define SCHOOL_H

#define NUMBER_OF_LEVELS 12
#define SCHOOL_NAME_SIZE 51

#include "Level.h"

struct School
{
    struct Level *levels[NUMBER_OF_LEVELS];
    char school_name[SCHOOL_NAME_SIZE];
    size_t num_of_students;
};

#endif