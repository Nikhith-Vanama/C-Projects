#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "accounts.txt"

struct Account {
    int id;
    char name[100];
    float balance;
};

// Create new account
void createAccount() {
    struct Account acc;
    FILE *fp = fopen(FILENAME, "a");

    printf("Enter Account ID: ");
    scanf("%d", &acc.id);
    getchar();  // consume newline

    printf("Enter Account Holder Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0;

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fprintf(fp, "%d|%s|%.2f\n", acc.id, acc.name, acc.balance);
    fclose(fp);
    printf("Account created successfully.\n");
}

// Display all accounts
void displayAccounts() {
    struct Account acc;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No accounts found.\n");
        return;
    }

    printf("\nAccounts List:\n");
    printf("ID\tName\t\tBalance\n");
    printf("---------------------------------\n");

    while (fscanf(fp, "%d|%[^|]|%f\n", &acc.id, acc.name, &acc.balance) == 3) {
        printf("%d\t%-15s\t%.2f\n", acc.id, acc.name, acc.balance);
    }

    fclose(fp);
}

// Update account balance (deposit or withdraw)
void updateBalance(int type) {
    int id, found = 0;
    float amount;
    struct Account acc;
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Account ID: ");
    scanf("%d", &id);

    printf("Enter amount to %s: ", type == 1 ? "deposit" : "withdraw");
    scanf("%f", &amount);

    while (fscanf(fp, "%d|%[^|]|%f\n", &acc.id, acc.name, &acc.balance) == 3) {
        if (acc.id == id) {
            found = 1;
            if (type == 1) {
                acc.balance += amount;
            } else if (amount <= acc.balance) {
                acc.balance -= amount;
            } else {
                printf("Insufficient balance.\n");
            }
        }
        fprintf(temp, "%d|%s|%.2f\n", acc.id, acc.name, acc.balance);
    }

    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
        printf("Transaction completed.\n");
    else
        printf("Account not found.\n");
}

// Check balance
void checkBalance() {
    int id, found = 0;
    struct Account acc;
    FILE *fp = fopen(FILENAME, "r");

    printf("Enter Account ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d|%[^|]|%f\n", &acc.id, acc.name, &acc.balance) == 3) {
        if (acc.id == id) {
            printf("Account Holder: %s\n", acc.name);
            printf("Current Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found)
        printf("Account not found.\n");
}

// Main Menu
int main() {
    int choice;

    do {
        printf("\n🏦 Bank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        switch (choice) {
            case 1: createAccount(); break;
            case 2: updateBalance(1); break;
            case 3: updateBalance(0); break;
            case 4: checkBalance(); break;
            case 5: displayAccounts(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
