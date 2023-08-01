#ifndef STUDENT_C
#define STUDENT_C

#include "../include/Student.h"
#include <string.h>

struct Student* createStudent(const char* first_name, const char* last_name, const char* telephone) {

    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    if (student == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    strcpy(student->first_name, first_name);
    strcpy(student->last_name, last_name);
    strcpy(student->telephone, telephone);

    for (size_t i = 0; i < NUM_OF_GRADES; i++)
        student->grades[i] = 0;

    return student;
}

void freeStudent(struct Student* student) {
    free(student);
}

void addGrade(struct Student* student, int grade, int index) {
    student->grades[index] = grade;
}

void printStudent(struct Student* student)
{
    printf("\tFirst Name of the student: %s\n", student->first_name);
    printf("\tLats Name of the student: %s\n", student->last_name);
    printf("\tTelephone Number of the student: %s\n", student->telephone);

    for (size_t i = 0; i < NUM_OF_GRADES; i++)
        printf("\tGrade %zu: %zu\n", (i+1), student->grades[i]);
    
}

double getStudentAverage(struct Student* student)
{
    double average = 0;

    for (size_t i = 0; i < NUM_OF_GRADES; i++)
    {
        average += student->grades[i];
    }

    return average/NUM_OF_GRADES;
}

void editInformation(struct Student* student)
{
    enum options {

    FirstName = '0',

    LastName = '1',

    Telephone = '2',

    Grade = '3',

    Exit = '4'
    };

    char input;

    printf("\tWhich information you want to edit?\n");

    do
    {
        printf("\t[0] |--> First Name\n");

        printf("\t[1] |--> Last Name\n");

        printf("\t[2] |--> Telephone\n");

        printf("\t[3] |--> Grade\n");

        printf("\t[4] |--> Exit\n");

        printf("\n\tPlease Enter Your Choice (0-4): ");

        input = getc(stdin);

        fflush(stdin);

        getc(stdin);

        switch (input)
        {
        case FirstName:
        {
            char first_name[SIZE_OF_NAME];
            printf("\n\tPlease Enter The First Name: ");
            scanf(" %50[^\n]", first_name);
            strcpy(student->first_name, first_name);
            fflush(stdin);
            getc(stdin);
            break;
        }
        case LastName:
        {
            char last_name[SIZE_OF_NAME];
            printf("\n\tPlease Enter The Last Name: ");
            scanf(" %50[^\n]", last_name);
            strcpy(student->last_name, last_name);
            fflush(stdin);
            getc(stdin);
            break;
        }
        case Telephone:
        {
            char telephone_num[TELEPHONE_SIZE];
            printf("\n\tPlease Enter The Telephone: ");
            scanf(" %10[^\n]", telephone_num);
            strcpy(student->telephone, telephone_num);
            fflush(stdin);
            getc(stdin);
            break;
        }
        case Grade:
        {
            size_t course_num, grade;
            printf("\n\tPlease Enter The Course Num (1-10): ");
            scanf("%zu", &course_num);

            printf("\n\tPlease Enter The New Grade (0-100): ");
            scanf("%zu", &grade);

            student->grades[course_num - 1] = grade;
            fflush(stdin);
            getc(stdin);

            break;
        }
        case Exit:
            printf("\n\tThe student is edited!\n");
            printStudent(student);
            break;
        default:
            printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-10!\nPress any key to continue...",

                       input);

            getc(stdin);

            getc(stdin);

            break;
        }

    } while (input != Exit);
    

}

#endif
