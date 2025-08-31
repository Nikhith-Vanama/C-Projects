#include <stdio.h>

int main() {
    int subjects, i;
    float marks[10], total = 0.0, percentage;
    char grade;

    printf("📘 Student Grade System\n");
    printf("Enter number of subjects (max 10): ");
    scanf("%d", &subjects);

    if (subjects <= 0 || subjects > 10) {
        printf("❌ Invalid number of subjects.\n");
        return 1;
    }

    for (i = 0; i < subjects; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        if (marks[i] < 0 || marks[i] > 100) {
            printf("❌ Invalid marks entered. Must be between 0 and 100.\n");
            return 1;
        }
        total += marks[i];
    }

    percentage = total / subjects;

    // Assign grade
    if (percentage >= 90)
        grade = 'A';
    else if (percentage >= 80)
        grade = 'B';
    else if (percentage >= 70)
        grade = 'C';
    else if (percentage >= 60)
        grade = 'D';
    else if (percentage >= 50)
        grade = 'E';
    else
        grade = 'F';

    // Output
    printf("\n📊 Results:\n");
    printf("Total Marks: %.2f\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}
