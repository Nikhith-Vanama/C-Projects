#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks[3];  // Marks for 3 subjects
    float total;
    float percentage;
};

void inputStudents(struct Student s[], int *n) {
    printf("Enter number of students: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        s[i].total = 0;
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].percentage = s[i].total / 3.0;
    }
}

void displayStudents(struct Student s[], int n) {
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Total", "Percent");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-10.2f %-10.2f\n", s[i].id, s[i].name, s[i].total, s[i].percentage);
    }
}

void rankList(struct Student s[], int n) {
    // Sort based on total marks (descending)
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j].total > s[i].total) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\n🏆 Rank List\n");
    printf("%-5s %-20s %-10s %-10s\n", "Rank", "Name", "Total", "Percent");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-10.2f %-10.2f\n", i + 1, s[i].name, s[i].total, s[i].percentage);
    }
}

int main() {
    struct Student students[MAX];
    int n;

    inputStudents(students, &n);
    displayStudents(students, n);
    rankList(students, n);

    return 0;
}
