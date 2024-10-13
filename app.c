#include <stdio.h>
#include <time.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    struct tm date;
    int isIssued; // 0=available , 1=issued
};

int addBook();
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
            //  viewBooks();
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
    FILE *file;
    file = fopen("library.txt", "a");
    struct Book book;
    printf("Enter Book Id: ");
    scanf("%d", &book.id);
    // Clear the input buffer to consume the newline character
    getchar(); // This will consume the leftover newline from the previous scanf

    printf("Enter Book Title: ");
    // scanf(" %s", &book.title);
    fgets(book.title, sizeof(book.title), stdin); // Using fgets to handle spaces
    printf("Enter Book Author: ");
    fgets(book.author, sizeof(book.author), stdin); // Using fgets to handle spaces
    // scanf(" %s", &book.author);
    // Get the current date
    time_t t = time(NULL);
    book.date = *localtime(&t);
    book.isIssued = 0;
    fwrite(&book, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book Added Successfully");
    return 0;
}