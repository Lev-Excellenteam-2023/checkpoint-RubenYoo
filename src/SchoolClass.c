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
        tmp->next = NULL;
        return;
    }

    while (tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = malloc(sizeof(struct Node));
    tmp = tmp->next;
    tmp->student = student;
    tmp->next = NULL;
}

size_t deleteStudentFromClass(struct SchoolClass* schoolClass, const char* first_name, const char* last_name, const char* telephone)
{
    struct Node* tmp = schoolClass->head;
    struct Node* prev = NULL;
    size_t num_of_deleted_students = 0;

    while (tmp != NULL)
    {
        struct Node* next = tmp->next; 

        if (strcmp(tmp->student->first_name, first_name) == 0 && strcmp(tmp->student->last_name, last_name) == 0 &&
            (strcmp(tmp->student->telephone, "") == 0 || strcmp(tmp->student->telephone, telephone) == 0))
        {
            if (prev == NULL)
                schoolClass->head = tmp->next;
            else
                prev->next = tmp->next;

            num_of_deleted_students += 1;
            free(tmp);
            schoolClass->num_of_students -= 1;
        }
        else
            prev = tmp;

        tmp = next;
    }

    return num_of_deleted_students;
}

void printStudentDetails(struct SchoolClass* schoolClass, const char* first_name, const char* last_name, size_t level_num, size_t class_num)
{
    struct Node* tmp = schoolClass->head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->student->first_name, first_name) == 0 && strcmp(tmp->student->last_name, last_name) == 0)
        {
            printf("\n\tLevel Number of the student: %zu\n", level_num);
			printf("\tClass Number of the student: %zu\n", class_num);
            printStudent(tmp->student);
        }

        tmp = tmp->next;
    }
}

struct Student* getStudent(struct SchoolClass* schoolClass, const char* first_name, const char* last_name, const char* telephone)
{
    struct Node* tmp = schoolClass->head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->student->first_name, first_name) == 0 && strcmp(tmp->student->last_name, last_name) == 0
            && strcmp(tmp->student->telephone, telephone) == 0)
        {
            return tmp->student;
        }

        tmp = tmp->next;
    }

    return NULL;
}

double getClassAverage(struct SchoolClass* schoolClass, size_t course_num)
{
    double average = 0;
    struct Node* tmp = schoolClass->head;

    for (size_t i = 0; i < schoolClass->num_of_students; i++)
    {
        average += tmp->student->grades[course_num];
        tmp = tmp->next;
    }

    return average/schoolClass->num_of_students;
}

#endif