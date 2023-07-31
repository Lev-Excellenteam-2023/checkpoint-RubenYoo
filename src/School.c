#ifndef SCHOOL_C
#define SCHOOL_C

#include "../include/School.h"

struct School* createSchool() {

    struct School* school = (struct School*)malloc(sizeof(struct School));

    if (school == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    for (size_t i = 0; i < NUMBER_OF_CLASSES; i++)
    {
        level->classes[i] = createSchoolClass(i);
    }
    
    return school;
}




#endif
