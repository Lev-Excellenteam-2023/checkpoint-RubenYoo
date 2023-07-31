#ifndef STUDENT_C
#define STUDENT_C

#include "../include/Student.h"

struct Student* createStudent(const char* first_name, const char* last_name, const char* telephone) {

    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    if (student == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    strcpy(student->first_name, first_name);
    strcpy(student->last_name, last_name);
    strcpy(student->telephone, telephone);
    student->num_of_grades = 0;

    return student;
}

void freeStudent(struct Student* student) {
    free(student);
}

void addGrade(struct Student* student, int grade) {
    student->grades[student->num_of_grades] = grade;
    student->num_of_grades += 1;
}

#endif
