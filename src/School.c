#ifndef SCHOOL_C
#define SCHOOL_C

#include "../include/School.h"
#include "Level.c"

struct School* createSchool() {

    struct School* school = (struct School*)malloc(sizeof(struct School));

    if (school == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    for (size_t i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        school->levels[i] = createLevel(i);
    }

    school->num_of_students = 0;
    
    return school;
}

void freeSchool(struct School* school)
{
    for (size_t i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        freeLevel(school->levels[i]);
    }
    
    free(school);
}

void addStudentToLevel(struct School* school, struct Student* student, int level_num, int class_num) {
    addStudentToClass(school->levels[level_num - 1], student, class_num);
    school->num_of_students += 1;
}

void setSchoolName(struct School* school, const char* school_name)
{
    strncpy(school->school_name, school_name, SCHOOL_NAME_SIZE);
}

#endif
