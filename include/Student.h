#ifndef STUDENT_H
#define STUDENT_H

#define TELEPHONE_SIZE 11
#define NUM_OF_GRADES 10
#define SIZE_OF_NAME 51

struct Student
{
    char first_name[SIZE_OF_NAME];
    char last_name[SIZE_OF_NAME];
    char telephone[TELEPHONE_SIZE];
    size_t grades[NUM_OF_GRADES];
};

#endif
