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

  struct School* school = createSchool();

  readDatabase(school);
  //printDatabase(school);

  menu();
  
  freeSchool(school);

  return 0;
}


void menu() {

    char input;

    // school.name = "schoolName";

    do {

        printf("\n|School Manager<::>Home|\n");

        printf("--------------------------------------------------------------------------------\n");

        //printf("Welcome to ( %s ) School!\nYou have inserted ( %zu ) students.\n\n", school.name, school.numOfStudents);

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

                //insertNewStudent();

                break;

            case Delete:

                //deleteStudent();

                break;

            case Edit:

                //editStudentGrade();

                break;

            case Search:

                //searchStudent();

                break;

            case Showall:

                //printAllStudents();

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

                //handleClosing();

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

void printDatabase(struct School* school)
{
  for (size_t i = 0; i < NUMBER_OF_LEVELS; i++)
  {
    printf("Level Number: %zu\n", i);
    for (size_t j = 0; j < NUMBER_OF_CLASSES; j++)
    {
      printf("class Number: %zu\n", j);
      struct Node* tmp = school->levels[i]->classes[j]->head;

      while(tmp != NULL)
      {
        printf("Student informations:\n");
        printf("First name: %s\n", tmp->student->first_name);
        printf("Last name: %s\n", tmp->student->last_name);
        printf("Telephone: %s\n", tmp->student->telephone);
        
        for (size_t k = 0; k < NUM_OF_GRADES; k++)
          printf("Grade %zu: %d\n", k, tmp->student->grades[k]);

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
