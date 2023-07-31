#ifndef LEVEL_C
#define LEVEL_C

#include "../include/Level.h"
#include "SchoolClass.c"

struct Level* createLevel(int level_num) {

    struct Level* level = (struct Level*)malloc(sizeof(struct Level));
    if (level == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    level->level_number = level_num;

    for (size_t i = 0; i < NUMBER_OF_CLASSES; i++)
    {
        level->classes[i] = createSchoolClass(i);
    }
    
    return level;
}

void freeLevel(struct Level* level)
{
    for (size_t i = 0; i < NUMBER_OF_CLASSES; i++)
    {
        freeSchoolClass(level->classes[i]);
    }
    
    free(level);
}

void addStudentToClass(struct Level* level, struct Student* student, int class_num) {
    addStudent(level->classes[class_num], student);
}

#endif