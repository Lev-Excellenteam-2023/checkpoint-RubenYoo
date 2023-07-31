struct SchoolClass
{
    struct Node {
        struct Student* student;
        struct Node* next;
    } *head;

    int num_students;
};
