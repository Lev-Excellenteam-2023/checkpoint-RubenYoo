#ifndef STUDENT_H
#define STUDENT_H

#define TELEPHONE_SIZE 11

struct Student
{
    struct node {
        int grade;
        struct node *next;
    } *head;

    char* first_name;
    char* last_name;
    char telephone[TELEPHONE_SIZE];
    int num_of_grades;  
};

#endif