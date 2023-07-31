struct SchoolClass
{
    struct Node {
        struct Student* student;
        struct Node* next;
    } *head;

    int num_of_students;
    int class_number;
};
