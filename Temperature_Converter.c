#include <stdio.h>

int main() {
    int choice;
    float celsius, fahrenheit;

    printf("🌡️ Temperature Converter\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("🌡️ %.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("🌡️ %.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
    } else {
        printf("❌ Invalid choice.\n");
    }

    return 0;
}
