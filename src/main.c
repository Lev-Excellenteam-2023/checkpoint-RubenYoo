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

void readDatabase(const struct School* school);
void printDatabase(const struct School* school);

int main() {

  struct School* school = createSchool();
  readDatabase(school);
  
  

  freeSchool(school);

  return 0;
}

void printDatabase(const struct School* school)
{
  
}


void readDatabase(const struct School* school)
{
  FILE* file = fopen("../students_with_class.txt", "r");
  if (file == NULL) {
      perror("Error opening the file");
      return 1;
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
      while (word != NULL) {
          int grade = atoi(word);
          addGrade(student, grade);
          word = strtok(NULL, DELIMITERS);
      }

      printf("Telephone: %s\n", telephone);
  }

  fclose(file);
}
