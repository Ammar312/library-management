#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
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
int viewAllBooks();
int searchBook();
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
            viewAllBooks();
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
            searchBook();
            break;
        case 0:
            printf("Exiting....");
            exit(0);
            break;
        default:
            printf("Invalid Choice \n");
        }
        printf("\nPress Any Key To Continue...\n");
        getch();
    } while (choice != 0);

    return 0;
}

int addBook()
{
    FILE *file;
    file = fopen("library.txt", "ab");
    struct Book book;
    srand(time(0)); // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random ID number between a range, for example, 1000 to 9999
    int random_id = rand() % 9000 + 1000; // % 9000 ensures it's in the range 0-8999, then +1000 makes it 1000-9999
    book.id = random_id;
    // Clear the input buffer to consume the newline character
    getchar(); // This will consume the leftover newline

    printf("Enter Book Title: ");
    // scanf(" %s", &book.title);
    fgets(book.title, sizeof(book.title), stdin); // Using fgets to handle spaces

    // Remove newline character from title
    size_t len = strlen(book.title);
    if (len > 0 && book.title[len - 1] == '\n')
    {
        book.title[len - 1] = '\0';
    }

    printf("Enter Book Author: ");
    fgets(book.author, sizeof(book.author), stdin); // Using fgets to handle spaces

    // Remove newline character from author
    len = strlen(book.author);
    if (len > 0 && book.author[len - 1] == '\n')
    {
        book.author[len - 1] = '\0';
    }

    // Get the current date
    time_t t = time(NULL);
    book.date = *localtime(&t);
    book.isIssued = 0;
    fwrite(&book, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book Added Successfully");
    return 0;
}

int viewAllBooks()
{
    FILE *file = fopen("library.txt", "rb");
    struct Book book;

    if (file == NULL)
    {
        printf("No Book found\n");
        return 0;
    }

    printf("\n%-10s %-30s %-30s %s \n", "ID", "Title", "Author", "Status");
    while (fread(&book, sizeof(struct Book), 1, file))
    {
        printf("\n%-10d %-30s %-30s %s", book.id, book.title, book.author, book.isIssued ? "Issued" : "Available");
    }
    fclose(file);
    return 0;
}

int searchBook()
{
    FILE *file = fopen("library.txt", "rb");
    struct Book book;
    char bookTitle[50];

    if (file == NULL)
    {
        printf("No Books Found \n");
        return -1;
    }
    getchar();
    printf("\nEnter the title of the book to search: ");
    fgets(bookTitle, sizeof(bookTitle), stdin);

    // Remove newline character from author
    size_t len = strlen(bookTitle);
    if (len > 0 && bookTitle[len - 1] == '\n')
    {
        bookTitle[len - 1] = '\0';
    }

    while (fread(&book, sizeof(struct Book), 1, file))
    {
        if (strcmp(book.title, bookTitle) == 0)
        {
            printf("\nBook Found:\n");
            printf("ID: %d\n", book.id);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Status: %s\n", book.isIssued ? "Issued" : "Available");
            break;
        }
        else
        {
            printf("\nBook with title %s not found", bookTitle);
            break;
        }
    }
    fclose(file);
    return 0;
}