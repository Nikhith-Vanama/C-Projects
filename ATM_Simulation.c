#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int pin;
    float balance;
};

void loadAccount(struct Account *acc) {
    FILE *fp = fopen("account.dat", "rb");
    if (fp == NULL) {
        // Initialize account if file doesn't exist
        acc->pin = 1234;
        acc->balance = 1000.0;
        FILE *newfp = fopen("account.dat", "wb");
        fwrite(acc, sizeof(struct Account), 1, newfp);
        fclose(newfp);
    } else {
        fread(acc, sizeof(struct Account), 1, fp);
        fclose(fp);
    }
}

void saveAccount(struct Account *acc) {
    FILE *fp = fopen("account.dat", "wb");
    fwrite(acc, sizeof(struct Account), 1, fp);
    fclose(fp);
}

int authenticate(int storedPin) {
    int enteredPin;
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == storedPin) {
        return 1;
    } else {
        printf("Incorrect PIN!\n");
        return 0;
    }
}

void checkBalance(struct Account *acc) {
    printf("Current balance: ₹%.2f\n", acc->balance);
}

void deposit(struct Account *acc) {
    float amount;
    printf("Enter amount to deposit: ₹");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        saveAccount(acc);
        printf("₹%.2f deposited successfully.\n", amount);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(struct Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ₹");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        saveAccount(acc);
        printf("₹%.2f withdrawn successfully.\n", amount);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}

int main() {
    struct Account acc;
    int choice;

    loadAccount(&acc);

    printf("=== Welcome to Simple ATM ===\n");

    if (!authenticate(acc.pin)) {
        return 1;
    }

    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkBalance(&acc); break;
            case 2: deposit(&acc); break;
            case 3: withdraw(&acc); break;
            case 4: printf("Thank you for using the ATM!\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
