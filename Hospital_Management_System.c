#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

void addPatient() {
    struct Patient p;
    FILE *fp = fopen("patients.dat", "ab");
    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf("%s", p.gender);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("Patient added successfully.\n");
}

void viewPatients() {
    struct Patient p;
    FILE *fp = fopen("patients.dat", "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    printf("\n%-5s %-20s %-5s %-10s %-20s\n", "ID", "Name", "Age", "Gender", "Disease");
    printf("-----------------------------------------------------------\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("%-5d %-20s %-5d %-10s %-20s\n", p.id, p.name, p.age, p.gender, p.disease);
    }
    fclose(fp);
}

void editPatient() {
    struct Patient p;
    int id, found = 0;
    FILE *fp = fopen("patients.dat", "rb+");

    if (!fp) {
        printf("File not found.\n");
        return;
    }

    printf("Enter patient ID to edit: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            printf("Enter new Name: ");
            scanf(" %[^\n]", p.name);
            printf("Enter new Age: ");
            scanf("%d", &p.age);
            printf("Enter new Gender: ");
            scanf("%s", p.gender);
            printf("Enter new Disease: ");
            scanf(" %[^\n]", p.disease);

            fseek(fp, -(long)sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            printf("Record updated.\n");
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }

    fclose(fp);
}

void deletePatient() {
    struct Patient p;
    int id, found = 0;
    FILE *fp = fopen("patients.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("File error!\n");
        return;
    }

    printf("Enter patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
        } else {
            fwrite(&p, sizeof(p), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found)
        printf("Record deleted.\n");
    else
        printf("Patient not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n2. View Patients\n3. Edit Patient\n4. Delete Patient\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: editPatient(); break;
            case 4: deletePatient(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
