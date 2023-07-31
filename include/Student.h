struct Student
{
    char* first_name;
    char* last_name;
    int telephone;
    
    struct node {
        int grade;
        struct node *next;
    };
};