#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "library.txt"

struct Book {
    int id;
    char title[100];
    char author[100];
};

// Function to add a book
void addBook() {
    struct Book b;
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar();  // consume newline

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0; // remove newline

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;

    fprintf(fp, "%d|%s|%s\n", b.id, b.title, b.author);
    fclose(fp);
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    struct Book b;
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    printf("ID\tTitle\t\tAuthor\n");
    printf("----------------------------------------\n");

    while (fscanf(fp, "%d|%[^|]|%[^\n]\n", &b.id, b.title, b.author) == 3) {
        printf("%d\t%-15s\t%-15s\n", b.id, b.title, b.author);
    }

    fclose(fp);
}

// Function to delete a book
void deleteBook() {
    int id, found = 0;
    struct Book b;
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d|%[^|]|%[^\n]\n", &b.id, b.title, b.author) == 3) {
        if (b.id != id) {
            fprintf(temp, "%d|%s|%s\n", b.id, b.title, b.author);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
        printf("Book deleted successfully!\n");
    else
        printf("Book not found.\n");
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n📚 Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline left by scanf

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: deleteBook(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
