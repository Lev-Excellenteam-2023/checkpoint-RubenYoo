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

int main() {

  struct School* school = createSchool();

  readDatabase(school);
  printDatabase(school);
  
  freeSchool(school);

  return 0;
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
