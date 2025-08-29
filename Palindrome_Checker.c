#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindromeString(char str[]) {
    int start = 0, end = strlen(str) - 1;

    while (start < end) {
        // Skip non-alphanumeric characters
        while (!isalnum(str[start]) && start < end) start++;
        while (!isalnum(str[end]) && start < end) end--;

        if (tolower(str[start]) != tolower(str[end]))
            return 0;
        start++;
        end--;
    }
    return 1;
}

// Function to check if a number is a palindrome
int isPalindromeNumber(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int choice;
    char input[100];

    printf("🔁 Palindrome Checker\n");
    printf("1. Check Palindrome (String)\n");
    printf("2. Check Palindrome (Number)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // clear newline from buffer

    if (choice == 1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove trailing newline

        if (isPalindromeString(input))
            printf("✅ The string is a palindrome.\n");
        else
            printf("❌ The string is not a palindrome.\n");
    } else if (choice == 2) {
        int number;
        printf("Enter a number: ");
        scanf("%d", &number);

        if (isPalindromeNumber(number))
            printf("✅ The number is a palindrome.\n");
        else
            printf("❌ The number is not a palindrome.\n");
    } else {
        printf("❌ Invalid choice.\n");
    }

    return 0;
}
