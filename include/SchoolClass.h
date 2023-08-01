#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include <stdio.h>
#include <stdlib.h>

struct SchoolClass
{
    struct Node
    {
        struct Student *student;
        struct Node *next;
    } *head;

    size_t num_of_students;
    size_t class_number;
};

#endif
