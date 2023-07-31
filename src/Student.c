#include "../include/Student.h"

struct Student* createStudent(const char* first_name, const char* last_name, const char* telephone) {
    
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    if (student == ((void *)0)) {
        perror("Memory allocation error");
        exit(1);
    }

    student->first_name = strdup(first_name);
    student->last_name = strdup(last_name);
    strcpy(student->telephone, telephone);
    student->num_of_grades = 0;
    student->head = ((void *)0); 

    return student;
}