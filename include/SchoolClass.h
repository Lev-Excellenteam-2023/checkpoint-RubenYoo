#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include <stdio.h>
#include <stdlib.h>

struct SchoolClass
{
    struct Node {
        struct Student* student;
        struct Node* next;
    } *head;

    int num_of_students;
    int class_number;
};

#endif
