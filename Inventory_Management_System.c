#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addItem() {
    struct Item it;
    FILE *fp = fopen("inventory.txt", "a");

    printf("Enter Item ID: ");
    scanf("%d", &it.id);
    printf("Enter Item Name: ");
    scanf(" %[^\n]", it.name);
    printf("Enter Quantity: ");
    scanf("%d", &it.quantity);
    printf("Enter Price per item: ");
    scanf("%f", &it.price);

    fprintf(fp, "%d %s %d %.2f\n", it.id, it.name, it.quantity, it.price);
    fclose(fp);
    printf("Item added successfully.\n");
}

void viewItems() {
    struct Item it;
    FILE *fp = fopen("inventory.txt", "r");

    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-----------------------------------------------\n");

    while (fscanf(fp, "%d %s %d %f", &it.id, it.name, &it.quantity, &it.price) != EOF) {
        printf("%-10d %-20s %-10d ₹%.2f\n", it.id, it.name, it.quantity, it.price);
    }

    fclose(fp);
}

void searchItem() {
    int searchId, found = 0;
    struct Item it;
    FILE *fp = fopen("inventory.txt", "r");

    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    printf("Enter Item ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(fp, "%d %s %d %f", &it.id, it.name, &it.quantity, &it.price) != EOF) {
        if (it.id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: ₹%.2f\n", it.id, it.name, it.quantity, it.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }

    fclose(fp);
}

void updateItem() {
    int id, found = 0;
    struct Item it;
    FILE *fp = fopen("inventory.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %d %f", &it.id, it.name, &it.quantity, &it.price) != EOF) {
        if (it.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", it.name);
            printf("Enter new quantity: ");
            scanf("%d", &it.quantity);
            printf("Enter new price: ");
            scanf("%f", &it.price);
            found = 1;
        }
        fprintf(temp, "%d %s %d %.2f\n", it.id, it.name, it.quantity, it.price);
    }

    fclose(fp);
    fclose(temp);

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found)
        printf("Item updated successfully.\n");
    else
        printf("Item not found.\n");
}

void calculateTotalValue() {
    struct Item it;
    float total = 0.0;
    FILE *fp = fopen("inventory.txt", "r");

    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    while (fscanf(fp, "%d %s %d %f", &it.id, it.name, &it.quantity, &it.price) != EOF) {
        total += it.quantity * it.price;
    }

    fclose(fp);
    printf("Total Inventory Value: ₹%.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Total Inventory Value\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: calculateTotalValue(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
