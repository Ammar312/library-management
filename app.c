#include <stdio.h>

int main()
{
    int choice;
    do
    {
        printf("   \nLibrary Managment System\n");
        printf("1: Add Book \n");
        printf("2: View All Books \n");
        printf("3: Edit Book \n");
        printf("4: Delete Book \n");
        printf("5: Issue Book \n");
        printf("6: View Issue Books \n");
        printf("7: Search Book \n");
        printf("0: Exit Program \n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            /* viewBooks(); */
            break;
        case 3:
            /* editBooks(); */
            break;
        case 4:
            /* deleteBook(); */
            break;
        case 5:
            /* issueBook(); */
            break;
        case 6:
            /* viewIssueBooks(); */
            break;
        case 7:
            /* searchBook(); */
            break;
        case 0:
            printf("Exiting....");
            break;
        default:
            printf("Invalid Choice \n");
        }
    } while (choice != 0);

    return 0;
}

int addBook()
{
    printf("Book Added");
    return 0;
}