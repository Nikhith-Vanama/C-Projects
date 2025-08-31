#include <stdio.h>
#include <stdlib.h>

void encryptFile(const char *filename, int key);
void decryptFile(const char *filename, int key);

int main() {
    int choice, key;
    char filename[100];

    printf("Simple File Encryption/Decryption\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter key (number): ");
    scanf("%d", &key);

    if (choice == 1) {
        encryptFile(filename, key);
        printf("File encrypted successfully.\n");
    } else if (choice == 2) {
        decryptFile(filename, key);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

void encryptFile(const char *filename, int key) {
    FILE *fin = fopen(filename, "r");
    FILE *fout = fopen("encrypted.txt", "w");

    if (!fin || !fout) {
        perror("File error");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch + key, fout); // Caesar shift
    }

    fclose(fin);
    fclose(fout);
}

void decryptFile(const char *filename, int key) {
    FILE *fin = fopen(filename, "r");
    FILE *fout = fopen("decrypted.txt", "w");

    if (!fin || !fout) {
        perror("File error");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch - key, fout); // Caesar reverse shift
    }

    fclose(fin);
    fclose(fout);
}
