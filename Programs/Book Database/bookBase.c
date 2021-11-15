#include <stdio.h>
#include <stdlib.h>
FILE *fptr;

int br()
{
    // function for section breaking
    printf("\n\n=====     =====     =====\n");
    return 0;
}

struct library
{
    char title[21];
    char author[21];
    int pages;
    float price;
};

int main()
{
    // prompt how many books will be entered
    int bookQuan;

    printf("How many books will you be saving?: ");
    scanf(" %d", &bookQuan);
    getchar(); // catches any data leak (most especially \n)

    // SECTION: begin database storage
    struct library *book[bookQuan];

    // prompt book details
    for (int i = 0; i < bookQuan; i++)
    {
        br();
        // allocate heap memory
        book[i] = (struct library *)malloc(sizeof(struct library));
        if (!book[i])
        {
            printf("Insuficient memory.\n");
            exit(1);
        }
        printf("Book %d of %d.\n\n", i + 1, bookQuan);

        printf("Please enter title of the book: ");
        gets(book[i]->title);
        printf("Please enter author of the book: ");
        gets(book[i]->author);
        printf("Please enter the number of pages of the book: ");
        scanf(" %d", &book[i]->pages);
        printf("Please enter price of the book: ");
        scanf(" %f", &book[i]->price);
        getchar(); // catches any leak
    }

    // SECTION: access file
    fptr = fopen("bookBase.txt", "w");

    br();
    printf("Opening file...\n");

    // ensure that filed has indeed been accessed
    // fptr (or whatever name used for file pointer during FILE declaration)
    if (fptr == 0)
    {
        // file not found, create new file instead
        printf("Error. File cannot be found.\n");
        exit(1);
    }

    // write on file
    printf("Writing on file...\n");
    fprintf(fptr, "===== LIST OF BOOKS =====\n\n\n");

    for (int i = 0; i < bookQuan; i++)
    {
        // write on file
        fprintf(fptr, "Book %d of %d:\n\nTitle: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n", i + 1, bookQuan, book[i]->title, book[i]->author, book[i]->pages, book[i]->price);

        // print results on terminal
        br();
        printf("Book %d of %d:\n\nTitle: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n", i + 1, bookQuan, book[i]->title, book[i]->author, book[i]->pages, book[i]->price);
    }

    // program termination
    fclose(fptr); // closing opened file
    free(book);

    return 0;
}