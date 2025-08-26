#include <stdio.h>

int main() {
    int year;

    printf("📅 Leap Year Checker\n");
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year < 0) {
        printf("❌ Invalid input. Please enter a positive year.\n");
        return 1;
    }

    // Leap year logic
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("✅ %d is a leap year.\n", year);
    } else {
        printf("❌ %d is not a leap year.\n", year);
    }

    return 0;
}
