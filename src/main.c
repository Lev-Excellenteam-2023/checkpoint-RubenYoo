#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/School.h"
#include "../include/Level.h"
#include "../include/SchoolClass.h"
#include "../include/Student.h"
#include "School.c"
#include "Level.c"
#include "SchoolClass.c"
#include "Student.c"

#define MAX_LINE_LENGTH 256
#define DELIMITERS " \t\n"

void readDatabase(struct School* school);
void printDatabase(struct School* school);
void menu();
void insertNewStudent(struct School* school);
void deleteStudent(struct School* school);
void searchStudent(struct School* school);
void handleClosing(struct School* school);
void printAllStudents(struct School* school);

enum menu_inputs {

    Insert = '0',

    Delete = '1',

    Edit = '2',

    Search = '3',

    Showall = '4',

    Top10 = '5',

    UnderperformedStudents = '6',

    Average = '7',

    Export = '8',

    Exit = '9'

};

int main() {
    menu();
    return 0;
}


void menu() {

    struct School* school = createSchool();

    readDatabase(school);
    //printDatabase(school);

    char input;

    setSchoolName(school, "schoolName");

    do {

        printf("\n|School Manager<::>Home|\n");

        printf("--------------------------------------------------------------------------------\n");

        printf("Welcome to ( %s ) School!\nYou have inserted ( %zu ) students.\n\n", school->school_name, school->num_of_students);

        printf("\t[0] |--> Insert\n");

        printf("\t[1] |--> Delete\n");

        printf("\t[2] |--> Edit\n");

        printf("\t[3] |--> Search\n");

        printf("\t[4] |--> Show All\n");

        printf("\t[5] |--> Top 10 students per course\n");

        printf("\t[6] |--> Underperformed students\n");

        printf("\t[7] |--> Average per course\n");

        printf("\t[8] |--> Export\n");

        printf("\t[9] |--> Exit\n");

        printf("\n\tPlease Enter Your Choice (0-9): ");

        input = getc(stdin);

        fflush(stdin);

        getc(stdin);

        switch (input) {

            case Insert:
            
                insertNewStudent(school);
                break;
            
            case Delete:

                deleteStudent(school);
                break;

            case Edit:

                //editStudentGrade();

                break;

            case Search:

                searchStudent(school);

                break;

            case Showall:

                printAllStudents(school);

                break;

            case Top10:

                //printTopNStudentsPerCourse();

                break;

            case UnderperformedStudents:

                //printUnderperformedStudents();

                break;

            case Average:

                //printAverage();

                break;

            case Export:

                //exportDatabase();

                break;

            case Exit:

                handleClosing(school);

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

void searchStudent(struct School* school)
{
    char first_name[SIZE_OF_NAME];
    char last_name[SIZE_OF_NAME];
	
	printf("\n\tPlease Enter The First Name: ");
    scanf(" %19[^\n]", first_name); 

    printf("\n\tPlease Enter The Last Name: ");
    scanf(" %19[^\n]", last_name); 

	for (size_t i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        for (size_t j = 0; j < NUMBER_OF_CLASSES; j++)
            printStudentDetails(school->levels[i]->classes[j], first_name, last_name, i, j);
    }

	fflush(stdin);
    getc(stdin);

}

void deleteStudent(struct School* school)
{
    char first_name[SIZE_OF_NAME];
    char last_name[SIZE_OF_NAME];
    char telephone_num[TELEPHONE_SIZE] = "";
    size_t deleted_students = 0;

    printf("\n\tPlease Enter The First Name: ");
    scanf(" %19[^\n]", first_name); 

    printf("\n\tPlease Enter The Last Name: ");
    scanf(" %19[^\n]", last_name); 

    printf("\n\tPlease Enter The Telephone: ");
    scanf(" %10[^\n]", telephone_num);

    for (size_t i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        for (size_t j = 0; j < NUMBER_OF_CLASSES; j++)
        { 
            deleted_students = deleteStudentFromClass(school->levels[i]->classes[j], first_name, last_name, telephone_num);
            school->num_of_students -= deleted_students;
        } 
    }

    fflush(stdin);
    getc(stdin);
    
}

void insertNewStudent(struct School* school) {
    size_t level_num, class_num;
    char first_name[SIZE_OF_NAME];
    char last_name[SIZE_OF_NAME];
    char telephone_num[TELEPHONE_SIZE];

    printf("\n\tPlease Enter The Level (1-10): ");
    scanf("%zu", &level_num);

    printf("\n\tPlease Enter The Class (1-12): ");
    scanf("%zu", &class_num);

    printf("\n\tPlease Enter The First Name: ");
    scanf(" %19[^\n]", first_name); 

    printf("\n\tPlease Enter The Last Name: ");
    scanf(" %19[^\n]", last_name); 

    printf("\n\tPlease Enter The Telephone: ");
    scanf(" %10[^\n]", telephone_num); 

    struct Student* my_new_student = createStudent(first_name, last_name, telephone_num);
    addStudentToLevel(school, my_new_student, level_num, class_num);

    fflush(stdin);
    getc(stdin);
}

void handleClosing(struct School* school)
{
	freeSchool(school);
}

void printAllStudents(struct School* school)
{
    for (size_t i = 0; i < NUMBER_OF_LEVELS; i++)
    {
      printf("\tLevel Number: %zu\n", i);
      for (size_t j = 0; j < NUMBER_OF_CLASSES; j++)
      {
        printf("\tClass Number: %zu\n", j);
        struct Node* tmp = school->levels[i]->classes[j]->head;

        while(tmp != NULL)
        {
          printf("\t\tStudent informations:\n");
          printf("\t\tFirst name: %s\n", tmp->student->first_name);
          printf("\t\tLast name: %s\n", tmp->student->last_name);
          printf("\t\tTelephone: %s\n", tmp->student->telephone);
          
          for (size_t k = 0; k < NUM_OF_GRADES; k++)
            printf("\t\tGrade %zu: %zu\n", k, tmp->student->grades[k]);

          tmp = tmp->next;
        }
      }
    }
}


void readDatabase(struct School* school)
{
    FILE* file = fopen("../students_with_class.txt", "r");
    if (file == NULL) {
        perror("Error opening the file");
        return;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* word = strtok(line, DELIMITERS);

        char* first_name = word;
        word = strtok(NULL, DELIMITERS);
        char* last_name = word;
        word = strtok(NULL, DELIMITERS);
        char* telephone = word;
        word = strtok(NULL, DELIMITERS);
        int level_number = atoi(word);
        word = strtok(NULL, DELIMITERS);
        int class_number = atoi(word);

        struct Student* student = createStudent(first_name, last_name, telephone);
        addStudentToLevel(school, student, level_number, class_number);

        word = strtok(NULL, DELIMITERS);
        for (size_t p = 0; p < NUM_OF_GRADES; p++)
        {
          int grade = atoi(word);
          addGrade(student, grade, p);
          word = strtok(NULL, DELIMITERS);
        }
    }

    fclose(file);
}
