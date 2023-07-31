#ifndef SCHOOLCLASS_C
#define SCHOOLCLASS_C

#include "../include/SchoolClass.h"
#include "Student.c"

struct SchoolClass* createSchoolClass(int class_num) {

    struct SchoolClass* schoolClass = (struct SchoolClass*)malloc(sizeof(struct SchoolClass));
    if (schoolClass == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    schoolClass->class_number = class_num;
    schoolClass->num_of_students = 0;
    schoolClass->head = NULL; 

    return schoolClass;
}

void freeStudentsList(struct Node* head)
{
    struct Node* tmp;

    while (head != NULL)
    {
       tmp = head;
       head = head->next;
       freeStudent(tmp->student);
       free(tmp);
    }
}

void freeSchoolClass(struct SchoolClass* schoolClass)
{
    freeStudentsList(schoolClass->head);
    free(schoolClass);
}

void addStudent(struct SchoolClass* schoolClass, struct Student* student) {
    schoolClass->num_of_students += 1;
    
    struct Node* tmp = schoolClass->head;

    if(tmp == NULL)
    {
        tmp = malloc(sizeof(struct Node));
        tmp->student = student;
        schoolClass->head = tmp;
        return;
    }

    while (tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = malloc(sizeof(struct Node));
    tmp->next->student = student;
}

#endif