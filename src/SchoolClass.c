#include "../include/SchoolClass.h"

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
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

void freeSchoolClass(struct SchoolClass* schoolClass)
{
    freeStudentsList(schoolClass);
    free(schoolClass);
}

void addStudent(struct SchoolClass* schoolClass, struct Student* student) {
    schoolClass->num_of_students += 1;
    
    struct Node* tmp = schoolClass->head;

    if(tmp == NULL)
    {
        tmp = malloc(sizeof(struct Node));
        tmp->student = student;
        student->head = tmp;
        return;
    }

    while (tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = malloc(sizeof(struct Node));
    tmp->next->student = student;
}