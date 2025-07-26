#include <stdio.h>

int main() {
    float height, weight, bmi;

    printf("🏋️ BMI Calculator\n");
    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    if (height <= 0 || weight <= 0) {
        printf("❌ Invalid input. Height and weight must be positive values.\n");
        return 1;
    }

    bmi = weight / (height * height);

    printf("📊 Your BMI is: %.2f\n", bmi);

    // Health category
    if (bmi < 18.5) {
        printf("🔹 Category: Underweight\n");
    } else if (bmi < 24.9) {
        printf("✅ Category: Normal weight\n");
    } else if (bmi < 29.9) {
        printf("⚠️ Category: Overweight\n");
    } else {
        printf("🚨 Category: Obese\n");
    }

    return 0;
}
