#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H


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
