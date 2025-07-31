#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Booking {
    char name[50];
    int roomNumber;
    int days;
    char roomType[20]; // Deluxe, Standard
    float amount;
};

float calculateAmount(char type[], int days) {
    if (strcmp(type, "Deluxe") == 0)
        return 2000.0 * days;
    else if (strcmp(type, "Standard") == 0)
        return 1000.0 * days;
    else
        return 0;
}

void addBooking() {
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "a");

    printf("Enter customer name: ");
    scanf(" %[^\n]", b.name);
    printf("Enter room number: ");
    scanf("%d", &b.roomNumber);
    printf("Enter number of days: ");
    scanf("%d", &b.days);
    printf("Enter room type (Deluxe/Standard): ");
    scanf("%s", b.roomType);

    b.amount = calculateAmount(b.roomType, b.days);

    fprintf(fp, "%s %d %d %s %.2f\n", b.name, b.roomNumber, b.days, b.roomType, b.amount);
    printf("Booking successful! Total Bill: ₹%.2f\n", b.amount);

    fclose(fp);
}

void viewBookings() {
    struct Booking b;
    FILE *fp = fopen("bookings.txt", "r");

    if (fp == NULL) {
        printf("No bookings found.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name", "Room#", "Days", "Type", "Amount");
    printf("-------------------------------------------------------------\n");

    while (fscanf(fp, "%s %d %d %s %f", b.name, &b.roomNumber, &b.days, b.roomType, &b.amount) != EOF) {
        printf("%-20s %-10d %-10d %-10s ₹%.2f\n", b.name, b.roomNumber, b.days, b.roomType, b.amount);
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Hotel Booking System ---\n");
        printf("1. Book Room\n");
        printf("2. View Bookings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBooking(); break;
            case 2: viewBookings(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
