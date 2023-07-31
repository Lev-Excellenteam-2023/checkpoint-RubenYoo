struct Student
{
    struct node {
        int grade;
        struct node *next;
    } *head;


    char* first_name;
    char* last_name;
    char telephone[11];
    int num_grades;  
};