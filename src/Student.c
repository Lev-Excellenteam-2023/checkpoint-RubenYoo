#include "../include/Student.h"

struct Student* createStudent(const char* first_name, const char* last_name, const char* telephone) {

    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    if (student == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    student->first_name = strdup(first_name);
    student->last_name = strdup(last_name);
    strcpy(student->telephone, telephone);
    student->num_of_grades = 0;
    student->head = NULL; 

    return student;
}

void freeLinkedList(struct node* head)
{
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

void freeStudent(struct Student* student) {
    free(student->first_name);
    free(student->last_name);
    freeLinkedList(student->head);
    free(student);
}

void addGrade(struct Student* student) {
    
}
