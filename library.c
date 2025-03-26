#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure for Book
typedef struct {
    int id;
    char title[50];
    char author[50];
    int year;
    int copies;  // Number of available copies
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function to add a new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[bookCount].id);
    getchar(); // Consume newline character

    printf("Enter Book Title: ");
    fgets(library[bookCount].title, 50, stdin);
    strtok(library[bookCount].title, "\n"); // Remove newline

    printf("Enter Author: ");
    fgets(library[bookCount].author, 50, stdin);
    strtok(library[bookCount].author, "\n");

    printf("Enter Year of Publication: ");
    scanf("%d", &library[bookCount].year);

    printf("Enter Number of Copies: ");
    scanf("%d", &library[bookCount].copies);

    bookCount++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tYear\tCopies\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t%s\t%d\t%d\n", library[i].id, library[i].title, library[i].author, library[i].year, library[i].copies);
    }
}

// Function to search for a book by ID
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\nCopies: %d\n",
                   library[i].id, library[i].title, library[i].author, library[i].year, library[i].copies);
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to delete a book by ID
void deleteBook() {
    int id, i, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < bookCount - 1; j++) {
            library[j] = library[j + 1]; // Shift books to remove the deleted one
        }
        bookCount--;
        printf("Book deleted successfully!\n");
    } else {
        printf("Book not found.\n");
    }
}

// Function to update book details
void updateBook() {
    int id;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            getchar(); // Consume newline character
            printf("Enter new Title: ");
            fgets(library[i].title, 50, stdin);
            strtok(library[i].title, "\n");

            printf("Enter new Author: ");
            fgets(library[i].author, 50, stdin);
            strtok(library[i].author, "\n");

            printf("Enter new Year: ");
            scanf("%d", &library[i].year);

            printf("Enter new Number of Copies: ");
            scanf("%d", &library[i].copies);

            printf("Book updated successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to borrow a book
void borrowBook() {
    int id;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].copies > 0) {
                library[i].copies--;
                printf("You have successfully borrowed \"%s\".\n", library[i].title);
            } else {
                printf("Sorry, no copies available for \"%s\".\n", library[i].title);
            }
            return;
        }
    }
    printf("Book not found.\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Update Book\n");
        printf("6. Borrow Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                updateBook();
                break;
            case 6:
                borrowBook();
                break;
            case 7:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

