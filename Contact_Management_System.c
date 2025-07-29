#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

void addContact() {
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "ab");

    if (!fp) {
        printf("❌ Unable to open file.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", c.phone);

    fwrite(&c, sizeof(struct Contact), 1, fp);
    fclose(fp);
    printf("✅ Contact saved.\n");
}

void displayContacts() {
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "rb");

    if (!fp) {
        printf("📂 No contacts found.\n");
        return;
    }

    printf("\n📒 Contact List:\n");
    printf("-----------------------------\n");

    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        printf("Name : %s\n", c.name);
        printf("Phone: %s\n", c.phone);
        printf("-----------------------------\n");
    }

    fclose(fp);
}

void searchContact() {
    struct Contact c;
    char searchName[50];
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");

    if (!fp) {
        printf("📂 No contacts found.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcmp(c.name, searchName) == 0) {
            printf("✅ Contact found:\n");
            printf("Name : %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Contact not found.\n");

    fclose(fp);
}

void deleteContact() {
    struct Contact c;
    char nameToDelete[50];
    int found = 0;

    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("❌ Error opening file.\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf(" %[^\n]", nameToDelete);

    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcmp(c.name, nameToDelete) != 0) {
            fwrite(&c, sizeof(struct Contact), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");

    if (found)
        printf("✅ Contact deleted.\n");
    else
        printf("❌ Contact not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n📱 Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("👋 Goodbye!\n"); break;
            default: printf("⚠️ Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
