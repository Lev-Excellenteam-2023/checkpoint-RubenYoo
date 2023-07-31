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


int main() {
  struct School school;
  struct Student* test;
  struct SchoolClass* test2;
  
  test = createStudent("Ruben", "Yoo", "0541111119");

  printf("\nThe entered first name is : %s", test->first_name);
  printf("\nThe entered last name is : %s", test->last_name);
  printf("\nThe entered telephone is : %s", test->telephone);
  printf("\n");

  addGrade(test, 59);
  addGrade(test, 60);
  addGrade(test, 61);

  test2 = createSchoolClass(0);
  addStudent(test2, test);


  freeSchoolClass(test2);

  return 0;
}